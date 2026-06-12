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

Vertice* novoVertice(int valor);
Grafo* criar_grafo(int max_vertices);

void inserir_vertice(Grafo* grafo, int origem, int destino);
void adicionar_aresta(Grafo* grafo, int origem, int destino);

void varredura_listaLadjacencias(char* path, int* num_vertices);
void carregar_lista_adjacencias(Grafo* grafo, char* path);

int grau_maximo(Grafo* grafo);
int grau_minimo(Grafo* grafo);

int ehMultigrafo(Grafo* grafo, int* lacos, int* repeticoes);

void DFS_G(Grafo* grafo, int raiz, int* vet_marca, int* tamanho, int*componente);
int** componentesConexos(Grafo* grafo, int* num_componentes, int* tamanhos);

void printarListaAdjacencias(Grafo* grafo);


#endif