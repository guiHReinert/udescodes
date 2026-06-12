#include "funcoes.h"

/*
    Criacao
*/
Vertice* criar_vertice(char* palavra){
    Vertice* vertice = (Vertice*)malloc(sizeof(Vertice));
    if(!vertice){
        printf("Nao foi possivel criar o vertice.");
    }
    vertice->posterior = NULL;
    vertice->palavra = palavra;
    vertice->grau = 0;

    return vertice;
}

Grafo* criar_grafo(int max_vertices){
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    if(!grafo){
        printf("Nao foi possivel criar o grafo.");
    }

    grafo->lista = (Vertice*)malloc(max_vertices*sizeof(Vertice));
    if(!grafo->lista){
        printf("Nao foi possivel criar a lista de adjacencias.");
    }
    for(int i=0; i < max_vertices; i++){
        grafo->lista[i].posterior = NULL;
        grafo->lista[i].palavra = NULL;
        grafo->lista[i].grau = 0;
    }

    grafo->num_vertices = max_vertices;

    return grafo;
}

/*
    "origem" se refere ao valor do grafo da lista de adjacencia, enquanto
    "palavra" serah a palavra do novo vertice a ser encadeado.
*/
void inserir_vertice(Grafo* grafo, char* origem, char* nova){
    Vertice* v_origem = NULL;
    for(int i=0; i<grafo->num_vertices; i++){
        if(grafo->lista[i].palavra && !strcmp(grafo->lista[i].palavra, origem)){
            v_origem = &(grafo->lista[i]);
            break;
        }
    }
    if(!v_origem){return;}

    Vertice* v_destino = criar_vertice(nova);     

    // Caso o vertice de origem nao estiver encadeado a nenhum vertice.
    if(v_origem->posterior == NULL){
        v_origem->posterior = v_destino;
    }
    else{
        Vertice* walker = v_origem->posterior;
        while(walker->posterior != NULL){
            walker = walker->posterior;
        }
        walker->posterior = v_destino;
    }
}

/*
    Adiciona a aresta no vertice "origem" e a aresta reciproca para o vertice
    "destino". Aqui eh desconsiderado o vertice 0 na intepretacao do grafo, mas
    computacionalmente ele serah utilizado apenas como um indice da lista.
*/
void adicionar_aresta(Grafo* grafo, char* origem, char* destino){
    if(strlen(origem) != 4 || strlen(destino) != 4){
        return;
    }

    inserir_vertice(grafo, origem, destino);

    if(strcmp(origem, destino)){
        inserir_vertice(grafo, destino, origem);
    }
}

/*
    Importacao da base de dados
*/

/*
    Abre o arquivo CSV e posteriormente alimenta as lista de adjacencias no
    grafo.
*/
void carregar_lista_adjacencias(Grafo** grafo, char* path){
    FILE* file = fopen(path, "r");
    if(!file){
        printf("Erro ao abrir o arquivo\n");
    }

    // Abre e le o arquivo uma vez para retornar a quantidade de vertices.
    int num_vertices = 0;
    char buffer[BUFFER];
    while(fgets(buffer, BUFFER, file)){
        num_vertices++;
    }

    *grafo = criar_grafo(num_vertices);

    int id = 0;
    rewind(file);
    while(fgets(buffer, BUFFER, file)){
        buffer[strcspn(buffer, "\n")] = '\0';
        
        // Coleta os vertices de origem.
        // id < 100 ? printf("%s", buffer) : 0;
        (*grafo)->lista[id++].palavra = strdup(buffer);
    }
    (*grafo)->num_vertices = id;

    /*
        CRIAR ADJACENCIAS DOS VERTICES
    */






    fclose(file);
}

/*
    Analise de componentes
*/

/*
    Graus maximo e minimo do grafo. O vertice 0 eh novamente desconsiderado.
*/
int grau_maximo(Grafo* grafo){
    int maior = 0;
    for(int i=0; i<grafo->num_vertices; i++){
        grafo->lista[i].grau > maior ? maior = grafo->lista[i].grau : 0;
    }
    return maior;
}
int grau_minimo(Grafo* grafo){
    int menor = grafo->num_vertices;
    for(int i=0; i<grafo->num_vertices; i++){
        grafo->lista[i].grau < menor ? menor = grafo->lista[i].grau : 0;
    }
    return menor;
}

/*
    Caminho minimo por Dijkstra
*/



void printar_lista_adjacencias(Grafo* grafo, int max_vertical, int max_horizontal){
    Vertice* walker = NULL;
    for(int i = 0; i < max_vertical; i++){
        walker = &(grafo->lista[i]);

        int count = 0;
        while(walker && count++ < max_horizontal){
            printf("(%d)[%s]{%d} -> ", i+1, walker->palavra, grafo->lista[i].grau);
            walker = walker->posterior;
        }
        printf("NULL\n");
    }
}
