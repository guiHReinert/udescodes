#ifndef ARQ_H
#define ARQ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER 1024

typedef struct Vertice{
    struct Vertice* posterior;
    char* palavra;
    int grau;
} Nodo, Vertice;

/*
    O grafo apresenta uma lista de adjacencias composta por todos os vertices
    encadeados ordenadamente com os vertices com arestas em comum.
*/
typedef struct{
    Vertice* lista;
    int num_vertices;
} Grafo;

Vertice* criar_vertice(char* palavra);
Grafo* criar_grafo(int max_vertices);
void inserir_vertice(Grafo* grafo, char* origem, char* nova);
void adicionar_aresta(Grafo* grafo, char* origem, char* destino);
void carregar_lista_adjacencias(Grafo** grafo, char* path);
int grau_maximo(Grafo* grafo);
int grau_minimo(Grafo* grafo);
void printar_lista_adjacencias(Grafo* grafo, int max_origens, int max_destinos);




#endif