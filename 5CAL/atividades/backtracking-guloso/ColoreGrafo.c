#include <stdio.h>
#include <stdbool.h>

#define V 5  // Numero de vertices no grafo

// Funcao para verificar se uma cor pode ser atribuida a um vertice
bool pode_colorir(int grafo[V][V], int cores[], int vertice, int cor) {
    for (int i = 0; i < V; i++) {
        if (grafo[vertice][i] == 1 && cores[i] == cor) {
            return false;  // Vertices adjacentes nao podem ter a mesma cor
        }
    }
    return true;
}

// Funcao recursiva para tentar colorir o grafo
bool colorir_grafo(int grafo[V][V], int cores[], int vertice, int m) {
    if (vertice == V) {
        return true;  // Todos os vertices foram coloridos
    }

    // Tenta colorir o vertice com diferentes cores
    for (int cor = 1; cor <= m; cor++) {
        if (pode_colorir(grafo, cores, vertice, cor)) {
            cores[vertice] = cor;
            if (colorir_grafo(grafo, cores, vertice + 1, m)) {
                return true;
            }
            cores[vertice] = 0;  // Desfaz a coloracao (backtrack)
        }
    }
    return false;  // Nao e possivel colorir com m cores
}

int main() {
    // Grafo representado por uma matriz de adjacencia (1 se houver aresta, 0 se nao houver)
    int grafo[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };

    int m = 3;  // Numero de cores permitidas
    int cores[V];  // Vetor que armazena a cor de cada vertice

    // Inicializa as cores como 0 (sem cor)
    for (int i = 0; i < V; i++) {
        cores[i] = 0;
    }

    // Chama a funcao recursiva para tentar colorir o grafo
    if (colorir_grafo(grafo, cores, 0, m)) {
        printf("Coloracao do grafo encontrada: \n");
        for (int i = 0; i < V; i++) {
            printf("Vertice %d -> Cor %d\n", i, cores[i]);
        }
    } else {
        printf("Nao e possAAAvel colorir o grafo com %d cores.\n", m);
    }

    return 0;
}
