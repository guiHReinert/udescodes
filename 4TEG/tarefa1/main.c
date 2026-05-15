#include "arq.h"

/*
    Como compilar este projeto:

gcc funcs.c main.c -o main

*/

int main(){
    char *arquivo = "teste2.csv";
    
    int num_vertices=0;

    varreduraListaAdjacencias(arquivo, &num_vertices);

    Grafo *grafo = novoGrafo(num_vertices);
    carregarListaAdjacencias(grafo, arquivo);

    printf("\n----------------Dados sobre o Grafo----------------\n\n");
    printf("Quantidade de vertices:\t%d\nGrau maximo:\t%d\nGrau minimo:\t%d\n\n",
        num_vertices-1, grauMaximo(grafo), grauMinimo(grafo));

    int multigrafo_bool, lacos=0, repeticoes=0;
    multigrafo_bool = ehMultigrafo(grafo, &lacos, &repeticoes);
    printf("Eh um multigrafo? %s\n\n", multigrafo_bool ? "Sim." : "Nao.");
    if(multigrafo_bool){
        printf("\tLacos:\t\t%d\n\tArestas mult:\t%d\n\n", lacos, repeticoes);
    }
    
    int num_componentes=0;
    int* tamanhos = (int*)calloc(grafo->num_vertices, sizeof(int));
    int** componentes = componentesConexos(grafo, &num_componentes, tamanhos);
    
    printf("----------------Componentes Conexos do Grafo----------------\n");
    for(int i=0; i<num_componentes; i++){
        printf("\nComponente %d de tamanho %d:\n", i+1, tamanhos[i]);
        for(int j=0; j<tamanhos[i]; j++){
            printf("%d ", componentes[i][j]);
        }
        printf("\n");
    }

    // printf("\n");
    // printarListaAdjacencias(grafo);
    // printf("\n");

    return 0;
}