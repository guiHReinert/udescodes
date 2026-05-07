#ifndef ARQ_H
#define ARQ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_CSV 1000

typedef struct grafo{
    int **matriz; 
};

int main();
int **listaAdjacencias(char *path, int tamanho);

#endif