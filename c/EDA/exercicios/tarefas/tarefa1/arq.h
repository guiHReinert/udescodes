#ifndef ARQ_H
#define ARQ_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

#define LIVRE 0     
#define OCUPADA 1
#define FRACASSO 0  
#define SUCESSO 1
// #define FALSO 0     
// #define VERDADEIRO 1
#define NAO 0       
#define SIM 1
#define MENOR -1    
#define IGUAL 0     
#define MAIOR 1

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

/*
    Funcoes de comparacao de nodos 
    (contidas em funcsGerais.c)   
*/
int compararRank(info *a, info *b);
int compararMat(info *a, info *b);

//=============== FUNCOES DE MANIPULACAO DE FILAS ===============
/*
    Manipulacao de filas SEM referencial movel.
    (contidas em funcsFilaBasica.c)
*/
descS *criaDescF(int tamInfo);
descS *destroiDescF(descS *desc);
int inserirSem(info *novo, descS *desc, int (*compara)(info *novo, info *old));
int reiniciaS(descS *desc);

/*
    Manipulacao de filas COM referencial movel
    (contidas em funcsFilaMovel.c)
*/
descM *criaDescM(int tamInfo);
descM *destroiDescM(descM *desc);
int inserirCom(info *novo, descM *desc, int (*compara)(info *novo, info *old));
int remove_(info *reg, descM  *desc);
int reinicia(descM *desc);
int buscaNaFrente(info *reg, descM *desc);
int buscaNaCauda(info *reg, descM *desc);
int testaVazia(descM *desc);

#endif
