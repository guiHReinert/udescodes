#ifndef ARQ_H
#define ARQ_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define SIM 1
#define NAO 0
#define SUCESSO 1
#define FRACASSO 0
#define VAZIA 0
#define CHEIA 0
#define PILHA_DIRETA 'd'
#define PILHA_INVERSA 'i'

// Informacoes da pilha
typedef struct dados{
    int num;
}info;

// Noh de uma pilha e, por consequencia, da multipilha.
typedef union nodoPilha{
    info *dados;
} nodo;

/*
    Descritor da multipilha (union).
        <N> numero de pilhas da MPE (N == 2, por ser uma MP estatica);
        <L> numero de elementos de cada pilha (estabelecido na criacao).
*/
typedef struct descritorMultiPilha{
    int topo1;
    int topo2;
    int tamVet;
    nodo *vet;
} descMP;

// =============== FUNCOES GERAIS ===============
/*
    (contidas em funcsGerais.c)
*/
void printarMP(descMP *desc);
int printarPilhaDireta(descMP *desc);
int printarPilhaInversa(descMP *desc);

// =============== FUNCOES DE INTERACAO ===============
/*
    (contidas em main.c)
*/
int main();

// =============== FUNCOES DE MULTIPILHA ESTATICA ===============
/*
    (contidas em funcsMPE.c)
*/
descMP *criarDescMP(descMP *desc, int L);
descMP* destruirDescMP(descMP *desc);
int reiniciarPilha(descMP *desc, char pilha);
int empilhar(descMP *desc, info *novo, char pilha);
int desempilhar(descMP *desc, char pilha);

// =============== FUNCOES ===============
/*
    (contidas em funcsMPE_HTML.c)
*/


#endif