#ifndef RUBRO_NEGRA_H
#define RUBRO_NEGRA_H

/*
    Definicao
*/
typedef enum coloracao_e { Vermelho, Preto } Cor_t;

typedef struct rn_nodo {
    struct rn_nodo* pai;
    struct rn_nodo* esquerda;
    struct rn_nodo* direita;
    Cor_t cor;
    int valor;
} rn_nodo_t;

typedef struct rn_arvore{
    rn_nodo_t* raiz;
    rn_nodo_t* nulo;
} rn_arvore_t;

/*
    Funcoes
*/


#endif