#include "../include/arvores.h"

/*
    Criacao
*/
avl_arvore_t* criar_avl() {
    avl_arvore_t* arvore = malloc(sizeof(avl_arvore_t));
    arvore->raiz = NULL;

    return arvore;                
}

avl_nodo_t* criar_nodo_avl(avl_nodo_t* pai, int valor) {
    printf("Adicionando %d\n", valor);

    avl_nodo_t* nodo = malloc(sizeof(avl_nodo_t));
    nodo->valor    = valor;
    nodo->pai      = pai;           
    nodo->esquerda = NULL;          
    nodo->direita  = NULL;         

    return nodo;                    
}

/*
    Balanceamento
*/

avl_nodo_t* rse(avl_arvore_t* arvore, avl_nodo_t* nodo) {
    avl_nodo_t* pai    = nodo->pai;
    avl_nodo_t* direita = nodo->direita;

    if (direita->esquerda != NULL) {
        direita->esquerda->pai = nodo;
    }

    nodo->direita = direita->esquerda;
    nodo->pai     = direita;

    direita->esquerda = nodo;
    direita->pai      = pai;

    if (pai == NULL) {
        arvore->raiz = direita;
    } else {
        if (pai->esquerda == nodo) {
            pai->esquerda = direita;
        } else {
            pai->direita = direita;
        }
    }

    return direita;
}

avl_nodo_t* rsd(avl_arvore_t* arvore, avl_nodo_t* nodo) {
    avl_nodo_t* pai     = nodo->pai;
    avl_nodo_t* esquerda = nodo->esquerda;

    if (esquerda->direita != NULL) {
        esquerda->direita->pai = nodo;
    }

    nodo->esquerda = esquerda->direita;
    nodo->pai      = esquerda;

    esquerda->direita = nodo;
    esquerda->pai     = pai;

    if (pai == NULL) {
        arvore->raiz = esquerda;
    } else {
        if (pai->esquerda == nodo) {
            pai->esquerda = esquerda;
        } else {
            pai->direita = esquerda;
        }
    }

    return esquerda;
}

avl_nodo_t* rde(avl_arvore_t* arvore, avl_nodo_t* nodo) {
    nodo->direita = rsd(arvore, nodo->direita);
    return rse(arvore, nodo);
}

avl_nodo_t* rdd(avl_arvore_t* arvore, avl_nodo_t* nodo) {
    nodo->esquerda = rse(arvore, nodo->esquerda);
    return rsd(arvore, nodo);
}

int altura(avl_nodo_t* nodo) {
    int esquerda = 0, direita = 0;
    if (nodo->esquerda != NULL) {
        esquerda = altura(nodo->esquerda) + 1;
    }
    if (nodo->direita != NULL) {
        direita = altura(nodo->direita) + 1;
    }
    return esquerda > direita ? esquerda : direita;
}

int fb(avl_nodo_t* nodo) {
    int esquerda = 0, direita = 0;
    if (nodo->esquerda != NULL) {
        esquerda = altura(nodo->esquerda) + 1;
    }
    if (nodo->direita != NULL) {
        direita = altura(nodo->direita) + 1;
    }
    return esquerda - direita;
}

void balanceamento_avl(avl_arvore_t* arvore, avl_nodo_t* nodo) {
    while (nodo != NULL) {
        int fator = fb(nodo);

        if (fator > 1) {
            if (fb(nodo->esquerda) > 0) {
                printf("RSD(%d)\n", nodo->valor);
                rsd(arvore, nodo);
            } else {
                printf("RDD(%d)\n", nodo->valor);
                rdd(arvore, nodo);
            }
        } else if (fator < -1) {
            if (fb(nodo->direita) < 0) {
                printf("RSE(%d)\n", nodo->valor);
                rse(arvore, nodo);
            } else {
                printf("RDE(%d)\n", nodo->valor);
                rde(arvore, nodo);
            }
        }

        nodo = nodo->pai;
    }
}

/*
    Operacoes
*/

avl_nodo_t* adicionar_nodo_avl(avl_nodo_t* nodo, int valor) {
    if (valor > nodo->valor) {
        if (nodo->direita == NULL) {
            avl_nodo_t* nodonovo = criar_nodo_avl(nodo, valor);
            nodo->direita = nodonovo;

            return nodonovo;
        } else {
            return adicionar_nodo_avl(nodo->direita, valor);
        }
    } else {
        if (nodo->esquerda == NULL) {
            avl_nodo_t* nodonovo = criar_nodo_avl(nodo, valor);
            nodo->esquerda = nodonovo;

            return nodonovo;
        } else {
            return adicionar_nodo_avl(nodo->esquerda, valor);
        }
    }
}

avl_nodo_t* adicionar_chave_avl(avl_arvore_t* arvore, int valor) {
    if (arvore->raiz == NULL) {     /* era: vazia(avl_arvore_s) */
        avl_nodo_t* nodonovo = criar_nodo_avl(NULL, valor);
        arvore->raiz = nodonovo;

        return nodonovo;
    } else {
        avl_nodo_t* nodo = adicionar_nodo_avl(arvore->raiz, valor);
        balanceamento_avl(arvore, nodo);

        return nodo;
    }
}

// REMOVER
