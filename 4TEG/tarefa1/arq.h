#ifndef ARQ_H
#define ARQ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1024

typedef struct Vertice{
    struct Vertice* anterior;
    struct Vertice* posterior;
    int valor;
} Nodo, Vertice;

/*
    O grafo apresenta uma lista de adjacencias composta por todos os vertices
    encadeados ordenadamente com os vertices com arestas em comum..
*/
typedef struct{
    Vertice* lista;
    int* graus;                 // Graus de cada vertice.
    int num_vertices;
} Grafo;

int main();

Vertice* novoVertice(int valor){
    Vertice* vertice = (Vertice*)malloc(sizeof(Vertice));
    if(!vertice){
        printf("Nao foi possivel criar o vertice.");
    }
    vertice->anterior = NULL;
    vertice->posterior = NULL;
    vertice->valor = valor;

    return vertice;
}

Grafo* novoGrafo(int max_vertices){
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    if(!grafo){
        printf("Nao foi possivel criar o grafo.");
    }
    grafo->lista = (Vertice*)malloc(max_vertices*sizeof(Vertice));
    if(!grafo->lista){
        printf("Nao foi possivel criar a lista de adjacencias.");
    }
    grafo->graus = (int*)calloc(max_vertices, sizeof(int));
    if(!grafo->graus){
        printf("Nao foi possivel criar a lista e graus do grafo.");
    }
    for(int i=0; i<max_vertices; i++){
        grafo->lista[i].anterior = NULL;
        grafo->lista[i].posterior = NULL;
        grafo->lista[i].valor = i;
    }
    grafo->num_vertices = max_vertices;

    return grafo;
}
/*
    "origem" se refere ao valor do grafo da lista de adjacencia, enquanto
    "destino" serah o valor do novo vertice a ser encadeado.
*/
void inserirVertice(Grafo* grafo, int origem, int destino){
    Vertice* v_origem = &(grafo->lista[origem]);
    Vertice* v_destino = novoVertice(destino);     

    // Caso o vertice de origem nao estiver encadeado a nenhum vertice.
    if(v_origem->posterior == NULL){
        v_destino->anterior = v_origem;
        v_origem->posterior = v_destino;
    }
    else{
        Vertice* walker = v_origem->posterior;
        Vertice* v_anterior = v_origem;
        while(walker != NULL && walker->valor < destino){
            v_anterior = walker;
            walker = walker->posterior;
        }
        v_destino->posterior = walker;
        v_destino->anterior = v_anterior;
        v_anterior->posterior = v_destino;
    }
    grafo->graus[origem]++;
}

/*
    Adiciona a aresta no vertice "origem" e a aresta reciproca para o vertice
    "destino". Aqui eh desconsiderado o vertice 0 na intepretacao do grafo, mas
    computacionalmente ele serah utilizado apenas como um indice da lista.
*/
void adicionarAresta(Grafo* grafo, int origem, int destino){
    if(origem <= 0 || destino <= 0){return;}

    inserirVertice(grafo, origem, destino);

    if(origem != destino){
        inserirVertice(grafo, destino, origem);
    }
}

/*
    Calcula a quantidade maxima de vertices presentes no arquivo CSV para uma
    computacao mais exata do grafo.
*/
void varreduraListaAdjacencias(char* path, int* num_vertices){
    FILE* file = fopen(path, "r");
    if(!file){
        printf("Erro ao abrir o arquivo\n");
    }

    // Coleta cada linha do arquivo a separando e multiplos "tokens".
    char buffer[BUFFER];
    while(fgets(buffer, BUFFER, file)){
        char* token = strtok(buffer, " \n");
        int num_arestas=0, maior_num;

        // Ignora a primeira linha (metadados?)
        token = strtok(NULL, " \n");
        
        if(token == NULL){continue;}

        /*
            num_vertices eh correspondente ao vertice de maior valor no arquivo,
            e o mesmo valor serah usado para a quantidade maxima de arestas.
        */
        while(token != NULL){
            maior_num = strtol(token, NULL, 10);
            maior_num >* num_vertices ?* num_vertices = maior_num : 0;
            token = strtok(NULL, " \n");     
        }
    }
    (*num_vertices)++;  // Pois a primeira linha foi ignorada.
    fclose(file);
}

/*
    Abre o arquivo CSV e posteriormente alimenta as lista de adjacencias no
    grafo.
*/
void* *carregarListaAdjacencias(Grafo* grafo, char* path){
    FILE* file = fopen(path, "r");
    if(!file){
        printf("Erro ao abrir o arquivo\n");
    }

    // Buffer para cada linha do arquivo e ignora a primeira linha (metadados?)
    char buffer[BUFFER];
    fgets(buffer, BUFFER, file);

    while(fgets(buffer, BUFFER, file)){
        char* token = strtok(buffer, " \n");
    
        if(token == NULL){continue;}

        /*
            Guarda o primeiro vertice de uma linha em "origem" e adiciona na
            linha de adjacencia correspondente os vertices associados.        
        */
        int origem = strtol(token, NULL, 10);
        token = strtok(NULL, " \n");
        while(token != NULL){
            adicionarAresta(grafo, origem, strtol(token, NULL, 10));  
            token = strtok(NULL, " \n");     
        }
    }
    fclose(file);
}

/*
    Graus maximo e minimo do grafo. O vertice 0 eh novamente desconsiderado.
*/
int grauMaximo(Grafo* grafo){
    int maior=grafo->graus[1];
    for(int i=2; i<grafo->num_vertices; i++){
        maior < grafo->graus[i] ? maior = grafo->graus[i] : 0;
    }
    return maior;
}
int grauMinimo(Grafo* grafo){
    int menor=grafo->graus[1];
    for(int i=2; i<grafo->num_vertices; i++){
        menor > grafo->graus[i] ? menor = grafo->graus[i] : 0;
    }
    return menor;
}

/*
    Funcao booleana para determinar se o grafo eh multigrafo ou simples.

    Grafo simples: SSE nao ha arestas conectando um vertice a ele mesmo e nao há
    dois vertices conectados por mais de uma aresta. (sem lacos ou arestas
    iguais). 
*/
int ehMultigrafo(Grafo* grafo, int* lacos, int* repeticoes){
    for(int i=1; i<grafo->num_vertices; i++){
        Vertice* walker = grafo->lista[i].posterior;
        
        while(walker != NULL){
            if(walker->valor == i){
                (*lacos)++;
            }
            Vertice* skin = grafo->lista[i].posterior;

            // Analogo a um for(){}, onde "walker" eh o limite de "skin".
            while(walker != skin){
                if(walker->valor == skin->valor){
                    (*repeticoes)++;
                    break;  // Na primeira nova occorencia de uma repeticao,
                            // passa para o proximo walker e evita redundancia.
                }
                skin = skin->posterior;
            }
            walker = walker->posterior;
        }
    }
    if(*lacos == 0 && *repeticoes == 0){return 0;}
    return 1;
}

/*
    Busca por DFS, com algumas alteracoes para a descricao dos componentes
    conexos:
        - tamanho: tamanho do componente encontrado pela DFS
        - componente: vetor com as "raizes", ou seja, os valores dos vertices
        que compoem um mesmo componente conexo (distribuicao).
*/
void DFS_G(Grafo* grafo, int raiz, int* vet_marca, int* tamanho, int*componente){
    // Caso nao se queira retornar um vetor com os valores marcados.
    if(vet_marca == NULL){
        vet_marca = (int*)calloc(grafo->num_vertices, sizeof(int));
    }
    vet_marca[raiz] = 1;
    // printf("%d ", raiz);
    componente[*tamanho] = raiz;
    (*tamanho)++;
    
    Vertice* walker = grafo->lista[raiz].posterior;
    while(walker != NULL){
        if(vet_marca[walker->valor] == 0){
            DFS_G(grafo, walker->valor, vet_marca, tamanho, componente);
        }
        walker = walker->posterior;
    }
}


/*
    Deve-se descrever o(s) componente(s) conexo(s) contido(s) no grafo a partir
    das características abaixo:
        1. Distribuicao dos componentes conexos;
        2. Quantidade de componentes conexos;
        3. Tamanhos dos componentes conexos.
*/
int** componentesConexos(Grafo* grafo, int* num_componentes, int* tamanhos){
    // Distribuicao dos vertices por componentes conexos
    int** componentes = (int**)calloc(grafo->num_vertices, sizeof(int*));
    // Vetor principal de comparacao dos vertices
    int* marcados = (int*)calloc(grafo->num_vertices, sizeof(int));
    *num_componentes = 0;

    for(int i=1; i<grafo->num_vertices; i++){
        componentes[*num_componentes] = (int*)calloc(grafo->num_vertices, sizeof(int));
        if(!marcados[i]){
            tamanhos[*num_componentes] = 0;
            DFS_G(grafo, i, marcados, &(tamanhos[*num_componentes]), componentes[*num_componentes]);
            (*num_componentes)++;
        }
    }
    return componentes;
}

void printarListaAdjacencias(Grafo* grafo){
    Vertice* walker = novoVertice(0);
    for(int i=1; i<grafo->num_vertices; i++){
        walker = &(grafo->lista[i]);

        printf("(grau:%d) ", grafo->graus[i]);
        while(walker != NULL){
            printf("[%d] -> ", walker->valor);
            walker = walker->posterior;
        }
        printf("NULL\n");
    }
}


#endif