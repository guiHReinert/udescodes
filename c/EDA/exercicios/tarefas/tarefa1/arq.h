#ifndef ARQ_H
#define ARQ_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#define FRACASSO 0  
#define SUCESSO 1
#define MENOR -1    
#define IGUAL 0     
#define MAIOR 1

// #define NOME 'n'
#define MATRICULA 'm'
#define RANKING 'r'
// #define CURSO 'c'

#define PELA_ESQUERDA 'e'
#define PELA_DIREITA 'd'

#define TAM_LINHA 42

typedef struct {
    char *nome;
    int matricula;
    int ranking;
    char *curso;
} info;

typedef struct nodo{
    info dados;
    struct nodo *anterior;   // Nodo anterior
    struct nodo *posterior;  // Nodo posterior
} nodo;

// Descritor basico
typedef struct{
    nodo *cauda;
    nodo *frente;
    int tamInfo;    // Tamanho em bytes do tipo info
    int numRep;     // Numero de repeticoes 
} descS;

// Descritor com referencial movel
typedef struct{
    nodo *cauda;
    nodo *frente;
    nodo *ref;
    int tamInfo;    // Tamanho em bytes do tipo info
    int tamFila;    // Numero de nodos da fila
    int numRep;     // Numero de repeticoes
} descM;

//=============== FUNCOES DE INTERACAO ===============
/*
    (contidas em main.c)
*/
int main();
void printarBase(char **base, int *range);
void compararDesempenho(char **arquivo, int *tamanhoDataset, char tag);

//=============== FuUNCOES DE TRATAMENTO DE CSV ===============
/*
    (contidas em funcsCSV.c)
*/
char **lerDataset(char *path, int *tamanho);  
char **criarBase(char **pessoas, int tamanho, int tamanhoBase);
info *criarDados(char *linha); 
nodo *criarNodo(info *dados);

//=============== FUNCOES GERAIS ===============
/*
    Funcoes de print da filas e seus elementos
    (contidas em funcsGerais.c)
*/
void printarNodo(nodo *nodo);
void printarFilaSem(descS *desc);
void printarFilaCom(descM *desc);
void implementarBaseSem(char **arquivo, int tamanhoDataset, int range,
    descS *desc, char tag);
void implementarBaseCom(char **arquivo, int tamanhoDataset, int range,
    descM *desc, char tag);

/*
    Funcoes de comparacao de nodos 
    (contidas em funcsGerais.c)   
*/
int comparar(info *a, info *b, char tag);

//=============== FUNCOES DE MANIPULACAO DE FILAS ===============
/*
    Manipulacao de filas SEM referencial movel.
    (contidas em funcsFilaBasica.c)
*/
descS *criaDescF(int tamInfo);
descS *destroiDescF(descS *desc);
int inserirSem(info *novo, descS *desc,
    int (*compara)(info *novo, info *old, char tag), char tag);

/*
    Manipulacao de filas COM referencial movel
    (contidas em funcsFilaMovel.c)
*/
descM *criaDescM(int tamInfo);
descM *destroiDescM(descM *desc);
char menorCaminho(nodo *start, nodo *end, nodo *newNodo,
    int (*compara)(info *novo, info *old, char tag), char tag);
int inserirCom(info *novo, descM *desc,
    int (*compara)(info *novo, info *old, char tag), char tag);
int removerNodoM(descM  *desc);
int buscaNaCauda(info *reg, descM *desc);  
int buscaNaFrente(info *reg, descM *p);  
int reinicia(descM *desc);

#endif
