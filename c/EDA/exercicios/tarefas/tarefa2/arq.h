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

// Pilhas do sentiod direto e inverso da MPE, respectivamente.
#define PILHA_DIRETA 'd'
#define PILHA_INVERSA 'i'

/*
    TAM_LINHA rege o tamanho dos nomes dos nodos da MPE do menu, enquanto
    TAM_TAG eh exclusiva ah analise de aninhamento de HTML. No enunciado eh dito
    que o nome de uma tag eh limitada ah 50 caracteres, porem aqui se considera
    51, pois a string com o nome da tag tambem pode possuir o caractere '/'.
*/
#define TAM_LINHA 128
#define TAM_TAG 51

// Informacoes da pilha
typedef struct dados{
    char *nome;
}info;

// Nodo de uma pilha e, por consequencia, da multipilha.
typedef union nodoPilha{
    info *dados;
} nodo;

/*
    Descritor da multipilha estatica (MPE).
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
descMP *criarDescMP(int L);
descMP* destruirDescMP(descMP *desc);
int reiniciarPilha(descMP *desc, char pilha);
int empilhar(descMP *desc, info *novo, char pilha);
int desempilhar(descMP *desc, char pilha);

// =============== FUNCOES DE LEITURA E ANALISE DE HTML POR MPE ===============
/*
    (contidas em funcsMPE_HTML.c)
*/
char **lerHTML(char *path, int *tamanho);
char *lerTag(char* linha);
int analisarHTML(char **html, int tamanho);

#endif