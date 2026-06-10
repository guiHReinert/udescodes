#ifndef B_H
#define B_H

/*
    Definicao
*/
typedef struct b_nodo {
    int total;
    int* chaves;
    struct b_nodo** filhos;
    struct b_nodo* pai;
} b_nodo_t;

typedef struct b_arvore {
    b_nodo_t* raiz;
    int ordem;
} b_arvore_t;

/*
    Funcoes
*/
b_arvore_t* criar_arvore_b(int ordem);
b_nodo_t*   criar_nodo_b(b_arvore_t* arvore);
int         pesquisa_binaria_b(b_nodo_t* nodo, int chave);
void        percorrer_arvore_b(b_nodo_t* nodo, void (visita)(int chave));
int         localizar_chave_b(b_arvore_t* arvore, int chave);
b_nodo_t*   localizar_nodo_b(b_arvore_t* arvore, int chave);
b_nodo_t*   dividir_nodo_b(b_arvore_t* arvore, b_nodo_t* nodo);
int         transbordo_b(b_arvore_t* arvore, b_nodo_t* nodo);
void        adicionar_chave_nodo_b(b_nodo_t* nodo, b_nodo_t* direita, int chave);
void        adicionar_chave_b(b_arvore_t* arvore, int chave);
void        adicionar_chave_recursivo_b(
    b_arvore_t* arvore, b_nodo_t* nodo, b_nodo_t* novo, int chave);

#endif