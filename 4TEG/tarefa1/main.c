#include "arq.h"

/*
    Como compilar este projeto:

gcc -o main main.c

*/

int main(){
    // char *arquivo = "teste2.csv";
    char* arquivo = "teste1.csv";

    int num_vertices=0;

    varreduraListaAdjacencias(arquivo, &num_vertices);

    Grafo *grafo = novoGrafo(num_vertices);
    printf("Criado o grafo.\n");
    printf("\tmax_vertices:\t%d\n", num_vertices);

    carregarListaAdjacencias(grafo, arquivo);
    printf("Carregada a lista.\n");

    printf("\tGrau maximo:\t%d\n", grauMaximo(grafo));
    printf("\tGrau minimo:\t%d\n", grauMinimo(grafo));

    int multigrafo_bool, lacos=0, repeticoes=0;
    multigrafo_bool = ehMultigrafo(grafo, &lacos, &repeticoes);
    printf("Eh um multigrafo? %s\n", multigrafo_bool ? "Sim." : "Nao.");
    if(multigrafo_bool){
        printf("\tLacos:\t\t%d\n\tArestas mult:\t%d\n", lacos, repeticoes);
    }

    // printarListaAdjacencias(grafo);
    
    int num_componentes=0;
    int* tamanhos = (int*)calloc(grafo->num_vertices, sizeof(int));
    int** componentes = componentesConexos(grafo, &num_componentes, tamanhos);
    for(int i=0; i<num_componentes; i++){
        printf("\nComponente %d de tamanho %d:\n", i+1, tamanhos[i]);
        for(int j=0; j<tamanhos[i]; j++){
            printf("%d ", componentes[i][j]);
        }
        printf("\n");
    }


    return 0;
}