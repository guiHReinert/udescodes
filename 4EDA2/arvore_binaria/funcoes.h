#include <stdio.h>
#include <stdlib.h>

// Busca

int pesquisaBinaria(int chave, int v[], int n) {
    int inicio = 0, meio, fim = n - 1;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (chave == v[meio]) {
            return meio;
        } else if (chave < v[meio]) {
            fim = meio - 1;
        } else {
        inicio = meio + 1;
        }
    }
    return -1; // Indice invalido
}

// Definicao de arvore

typedef struct nodo {
    struct nodo* pai;       // Ponteiro para o nó pai
    struct nodo* esquerda;  // Ponteiro para o nó filho a esquerda
    struct nodo* direita;   // Ponteiro para o nó filho a direita
    float v;                // Conteúdo de um nó arbitrário da árvore
} Nodo;

typedef struct arvore {
    struct nodo* raiz;
} Arvore;

// Algoritmos de arvore binaria

Arvore *cria() {
    Arvore *arvore;
    arvore = (Arvore*) malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

int vazia(Arvore* arvore) {
    return (arvore->raiz == NULL);
}

Nodo* adiciona(Arvore* arvore, Nodo* pai, float valor) {
    Nodo *no = (Nodo*) malloc(sizeof(Nodo));
    no->pai = pai;
    no->esquerda = NULL;
    no->direita = NULL;
    no->v = valor;
    if (pai == NULL) {
        arvore->raiz = no;
    }
    return no;
}


