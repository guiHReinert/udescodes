#include "../include/arvores.h"

/*
    Criacao
*/

b_arvore_t* criar_arvore_b(int ordem) {
    b_arvore_t* a = malloc(sizeof(b_arvore_t));
    a->ordem = ordem;
    a->raiz = criar_nodo_b(a);
    return a;
}

b_nodo_t* criar_nodo_b(b_arvore_t* arvore) {
    int max = arvore->ordem * 2;
    b_nodo_t* nodo = malloc(sizeof(b_nodo_t));
    nodo->pai = NULL;
    nodo->chaves = malloc(sizeof(int) * (max + 1));
    nodo->filhos = malloc(sizeof(b_nodo_t) * (max + 2));
    nodo->total = 0;
    for (int i = 0; i < max + 2; i++)
    nodo->filhos[i] = NULL;
    return nodo;
}

/*
    Operacoes
*/

int pesquisa_binaria_b(b_nodo_t* nodo, int chave) {
    int inicio = 0, fim = nodo->total - 1, meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (nodo->chaves[meio] == chave) {
            return meio; //encontrou
        } else if (nodo->chaves[meio] > chave) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }
    return inicio; //não encontrou
}

// Percorre todos os nodos da arvore.
void percorrer_arvore_b(b_nodo_t* nodo, void (visita)(int chave)) {
    if (nodo != NULL) {
        for (int i = 0; i < nodo->total; i++){
            percorrer_arvore_b(nodo->filhos[i], visita);
            printf("(%d)\n", nodo->chaves[i]);
        }
        percorrer_arvore_b(nodo->filhos[nodo->total], visita);
    }
}

// Busca uma chave.
int localizar_chave_b(b_arvore_t* arvore, int chave) {
    b_nodo_t *nodo = arvore->raiz;
    while (nodo != NULL) {
        int i = pesquisa_binaria_b(nodo, chave);
        if (i < nodo->total && nodo->chaves[i] == chave) {
            return 1; //encontrou
        } else {
            nodo = nodo->filhos[i];
        }
    }
    return 0; //não encontrou
}

// Busca um nodo a partir de uma chave.
b_nodo_t* localizar_nodo_b(b_arvore_t* arvore, int chave) {
    b_nodo_t *nodo = arvore->raiz;
    while (nodo != NULL) {
        int i = pesquisa_binaria_b(nodo, chave);
    if (nodo->filhos[i] == NULL)
        return nodo; //encontrou nó
    else
        nodo = nodo->filhos[i];
    }
    return NULL; //não encontrou nenhum nó
}

// Split: divide as chaves de um nodo.
b_nodo_t* dividir_nodo_b(b_arvore_t* arvore, b_nodo_t* nodo) {
    int meio = nodo->total / 2;
    b_nodo_t* novo = criar_nodo_b(arvore);
    novo->pai = nodo->pai;
    for (int i = meio + 1; i < nodo->total; i++) {
        novo->filhos[novo->total] = nodo->filhos[i];
        novo->chaves[novo->total] = nodo->chaves[i];
        if (novo->filhos[novo->total] != NULL) novo->filhos[novo->total]->pai = novo;
            novo->total++;
    }
    novo->filhos[novo->total] = nodo->filhos[nodo->total];
    if (novo->filhos[novo->total] != NULL) novo->filhos[novo->total]->pai = novo;
    nodo->total = meio;
    return novo;
}

// Verifica overflow em um nodo
int transbordo_b(b_arvore_t *arvore, b_nodo_t *nodo) {
    return nodo->total > arvore->ordem * 2;
}

// Adiciona uma chave em um nodo.
void adicionar_chave_nodo_b(b_nodo_t* nodo, b_nodo_t* direita, int chave) {
    int i = pesquisa_binaria_b(nodo, chave);
    for (int j = nodo->total - 1; j >= i; j--) {
        nodo->chaves[j + 1] = nodo->chaves[j];
        nodo->filhos[j + 2] = nodo->filhos[j + 1];
    }
    nodo->chaves[i] = chave;
    nodo->filhos[i + 1] = direita;
    nodo->total++;
}

// Adicionar uma chave.
void adicionar_chave_b(b_arvore_t* arvore, int chave) {
    b_nodo_t* nodo = localizar_nodo_b(arvore, chave);
    adicionar_chave_recursivo_b(arvore, nodo, NULL, chave);
}
void adicionar_chave_recursivo_b(b_arvore_t* arvore, b_nodo_t* nodo, b_nodo_t* novo, int chave) {
adicionar_chave_nodo_b(nodo, novo, chave);
if (transbordo_b(arvore, nodo)) {
    int promovido = nodo->chaves[arvore->ordem];
    b_nodo_t* novo = dividir_nodo_b(arvore, nodo);
    if (nodo->pai == NULL) {
        b_nodo_t* raiz = criar_nodo_b(arvore);
        raiz->filhos[0] = nodo;
        adicionar_chave_nodo_b(raiz, novo, promovido);
        nodo->pai = raiz;
        novo->pai = raiz;
        arvore->raiz = raiz;
    } else
    adicionar_chave_recursivo_b(arvore, nodo->pai, novo, promovido);
    }
}