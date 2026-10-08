#include <stdio.h>
#include <stdbool.h>

#define V 5  // N�mero de v�rtices no grafo

// Fun��o para verificar se uma cor pode ser atribu�da a um v�rtice
bool pode_colorir(int grafo[V][V], int cores[], int vertice, int cor) {
    for (int i = 0; i < V; i++) {
        if (grafo[vertice][i] == 1 && cores[i] == cor) {
            return false;  // V�rtices adjacentes n�o podem ter a mesma cor
        }
    }
    return true;
}

// Fun��o recursiva para tentar colorir o grafo
bool colorir_grafo(int grafo[V][V], int cores[], int vertice, int m) {
    if (vertice == V) {
        return true;  // Todos os v�rtices foram coloridos
    }

    // Tenta colorir o v�rtice com diferentes cores
    for (int cor = 1; cor <= m; cor++) {
        if (pode_colorir(grafo, cores, vertice, cor)) {
            cores[vertice] = cor;
            if (colorir_grafo(grafo, cores, vertice + 1, m)) {
                return true;
            }
            cores[vertice] = 0;  // Desfaz a colora��o (backtrack)
        }
    }
    return false;  // N�o � poss�vel colorir com m cores
}

int main() {
    // Grafo representado por uma matriz de adjac�ncia (1 se houver aresta, 0 se n�o houver)
    int grafo[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 0, 1, 0}
    };

    int m = 3;  // N�mero de cores permitidas
    int cores[V];  // Vetor que armazena a cor de cada v�rtice

    // Inicializa as cores como 0 (sem cor)
    for (int i = 0; i < V; i++) {
        cores[i] = 0;
    }

    // Chama a fun��o recursiva para tentar colorir o grafo
    if (colorir_grafo(grafo, cores, 0, m)) {
        printf("Colora��o do grafo encontrada: \n");
        for (int i = 0; i < V; i++) {
            printf("V�rtice %d -> Cor %d\n", i, cores[i]);
        }
    } else {
        printf("N�o � poss�vel colorir o grafo com %d cores.\n", m);
    }

    return 0;
}
