#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define LIVRE 0     
#define OCUPADA 1
#define FRACASSO 0  
#define SUCESSO 1
#define FALSO 0     
#define VERDADEIRO 1
#define NAO 0       
#define SIM 1
#define MENOR -1    
#define IGUAL 0     
#define MAIOR 1

#define TAM_LINHA 42
#define TAM_CSV 10002

typedef struct {
    char nome[30];
    int matricula;
    int ranking;
    char curso[30];
} info;

typedef struct{
    info dados;
    nodo *anterior;   // Nodo anterior
    nodo *posterior;  // Nodo posterior
} nodo;

// Descritor basico
typedef struct{
    nodo *frente;
    nodo *cauda;
    int tamInfo;    // Tamanho em bytes do tipo info
    int numRep;     // Numero de repeticoes 
} descF;

// Descritor com referencial movel
typedef struct{
    nodo *frente;
    nodo *cauda;
    nodo *ref;
    int tamInfo;    // Tamanho em bytes do tipo info
    int tamFila;    // Numero de nodos da fila
    int numRep;     // Numero de repeticoes
} descM;

//=============== FuUNCOES GERAIS ===============
/*
    Funcoes de print da filas e seus elementos
    (contidas em funcsGerais.c)
*/
void printarNodo(nodo *nodo);
void printarFilaSem(descF *desc);
void printarFilaCom(descM *desc);

/*
    Funcoes de comparacao de nodos 
    (contidas em funcsGerais.c)   
*/
int compararRank(info a, info b);
int compararMat(info a, info b);

//=============== FuUNCOES DE TRATAMENTO DE CSV ===============
/*
    (contidas em funcsCSV.c)
*/
char **criarBase(char *file, int tamBase);  
nodo *criarNodo(char **base); 

//=============== FuUNCOES DE MANIPULACAO DE FILAS ===============
/*
    Manipulacao de filas SEM referencial movel.
    (contidas em funcsFilaBasica.c)
*/
descF *criaDescF(int tamInfo);
descF *destroiDescF(descF *desc);
int inserirSem(info *novo, descF *desc, int (*compara)(info *novo, info *walker), int *count);
int remove_(info *reg, descF  *desc);
int reinicia(descF *desc);
int buscaNaFrente(info *reg, descF *desc);
int buscaNaCauda(info *reg, descF *desc);
int testaVazia(descF *desc);

/*
    Manipulacao de filas COM referencial movel
    (contidas em funcsFilaMovel.c)
*/
int inserirCom(info *novo, descM *desc, int (*compara)(info *novo, info *walker), int *count);
descM *criaDescM(int tamInfo);
descM *destroiDescM(descM *desc);
