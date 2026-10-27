#include "arq.h"

Grafo* criar_grafo(int num_vertices) {
    if (num_vertices <= 0) {return NULL;}
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    if (!grafo) {return NULL;}
    grafo->matriz_cores = calloc(num_vertices, sizeof(*grafo->matriz_cores));
    if (!grafo->matriz_cores) {
        free(grafo);
        return NULL;
    }
    for(int i=0; i < num_vertices; i++) {
        grafo->matriz_cores[i] = calloc(num_vertices, sizeof(**grafo->matriz_cores));
        if (!grafo->matriz_cores[i]) {
            free(grafo);
            return NULL;
        }
        for(int j=0; j < num_vertices; j++) {
            grafo->matriz_cores[i][j] = 0;
        }
    }
    grafo->num_vertices = num_vertices;
    grafo->num_cores = 0;
    return grafo;
}

void colorir_vertice(Grafo* grafo, int cor, int x, int y) {
    if (!(x >= 0 && x < grafo->num_vertices)||!(y >= 0 && y < grafo->num_vertices)) {return NULL;}
    if (cor < 0 || cor >= grafo->num_cores) {return NULL;}
    grafo->matriz_cores[x][y] = cor;
}

void printar_grafo(Grafo* grafo){
    printf("%d\n", grafo->num_vertices);
    for(int i=0; i < grafo->num_vertices; i++) {
        printf("%d: ", i);
        for(int j=0; j < grafo->num_vertices; j++) {
            printf("(%d) ", grafo->matriz_cores[i][j]);
        }
        printf("\n");
    }
}
