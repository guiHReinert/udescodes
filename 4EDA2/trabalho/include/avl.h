#ifndef AVL_H
#define AVL_H

/*
    Definicao
*/
typedef struct avl_nodo{
    struct avl_nodo* pai;
    struct avl_nodo* esquerda;
    struct avl_nodo* direita;
    int valor;
    int altura;
} avl_nodo_t;

typedef struct avl_arvore{
    avl_nodo_t* raiz;
} avl_arvore_t;

/*
    Funcoes
*/
avl_arvore_t* criar_avl(void);
avl_nodo_t*   criar_nodo_avl(avl_nodo_t* pai, int valor);
avl_nodo_t*   rse(avl_arvore_t* arvore, avl_nodo_t* nodo);
avl_nodo_t*   rsd(avl_arvore_t* arvore, avl_nodo_t* nodo);
avl_nodo_t*   rde(avl_arvore_t* arvore, avl_nodo_t* nodo);
avl_nodo_t*   rdd(avl_arvore_t* arvore, avl_nodo_t* nodo);
int           altura(avl_nodo_t* nodo);
int           fb(avl_nodo_t* nodo);
void          balanceamento_avl(avl_arvore_t* arvore, avl_nodo_t* nodo);
avl_nodo_t*   adicionar_nodo_avl(avl_nodo_t* nodo, int valor);
avl_nodo_t*   adicionar_chave_avl(avl_arvore_t* arvore, int valor);

#endif