#include "arq.h"

/*
    Como compilar este projeto:

gcc -o main main.c

*/

int main(){
    char *arquivo = "teste2.csv";
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
    printf("Eh um multigrafo? %s\n\tLacos:\t\t%d\n\tArestas rep.:\t%d\n",
        multigrafo_bool ? "Sim." : "Nao.", lacos, repeticoes);

    // printarListaAdjacencias(grafo);

    return 0;
}