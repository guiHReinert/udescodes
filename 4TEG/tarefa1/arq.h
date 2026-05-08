#ifndef ARQ_H
#define ARQ_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARESTAS 1000

typedef struct{
    int *matriz; 
} grafo;

int main();


// Grafo como uma matriz de adjacencias
int *criarGrafo(int numVertices){

}

//  Carrega o arquivo CSV em uma matriz de adjacencias no grafo.
int **matrizAdjacencias(grafo graf, char *path, int *tamanho);
int **matrizAdjacencias(grafo graf, char *path, int *tamanho){
    
    // Verifica se o arquivo foi aberto
    FILE *file = fopen(path, "r");
    if(!file){
        printf("Erro ao abrir o arquivo\n");
        return NULL;
    }

    // Buffer para cada linha do arquivo e calcula o tamanho do arquivo
    char buffer[MAX_ARESTAS];
    *tamanho = 0;
    while(fgets(buffer, MAX_ARESTAS, file)){
        (*tamanho)++;
    }
    // Reposiciona o ponteiro de leitura do arquivo para a primeira linha
    rewind(file);

    int pos = 0;
    /*
        Alocar dinamicamente a matriz, pois a declaracao da matriz em main.c nao
        conhece previsamente o tamanho maximo da matriz
    */
    char **matriz = (char**) malloc((*tamanho)*sizeof(char*));
    if(!matriz){
        printf("Nao foi possivel alocar a matriz.\n");
        return NULL;
    }

    /*
        Aloca dinamicamente cada linha da matriz e copia as linhas do arquivo
    */
    while(fgets(buffer, MAX_ARESTAS, file)){
        matriz[pos] = (char*) malloc(MAX_ARESTAS);
        if(!matriz[pos]){
            printf("Nao foi possivel alocar memoria para a linha %d", pos);
            return NULL;
        }
        strcpy(matriz[pos++], buffer);
    }



    fclose(file);
}

//  - Adicionar
//  - Remover


// Grau maximo
// Grau minimo

// Eh um grafo simples?
// Eh um multigrafo?

// Quantidade, distribuição e tamanhos dos componentes conexos existentes no
// grafo



#endif