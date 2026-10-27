#ifndef ARQ_H
#define ARQ_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1024

typedef struct Grafo_s {
    int** matriz_cores;
    int num_vertices;
    int num_cores;
} Grafo;

int main(int argc, char* argv[]);

Grafo* criar_grafo(int num_vertices);
void colorir_vertice(Grafo* grafo, int cor, int x, int y);
void printar_grafo(Grafo* grafo);

void carregar_grafo(Grafo* grafo, char* path, int* num_vertices);

#endif
