#include "arq.h"

// Grafo como uma matriz de adjacencias
int **criarGrafo(int numVertices){

}

//  - Adicionar
//  - Remover

//  Carrega o arquivo CSV em uma lista de adjacencias
int **listaAdjacencias(char *path, int tamanho){
    FILE *file = fopen(path, 'r');
    if(!file){
        printf("Erro ao abrir o arquivo\n");
        return NULL;
    }

    for(int i=0; tamanho; i++){
        printf("%s", file[i]);
    }
}


// Grau maximo
// Grau minimo

// Eh um grafo simples?
// Eh um multigrafo?

// Quantidade, distribuição e tamanhos dos componentes conexos existentes no
// grafo

