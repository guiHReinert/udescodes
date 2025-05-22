#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define LIVRE 0     #define OCUPADA 1
#define FRACASSO 0  #define SUCESSO 1
#define FALSO 0     #define VERDADEIRO 1
#define NAO 0       #define SIM 1
#define MENOR -1    #define IGUAL 0     #define MAIOR 1

typedef struct {
    char nome[30];
    int matricula;
    int idade;
    char curso[30];
} info;

typedef struct{
    info dados;
    dados *atras;
    dados *frente;
} dados;

// Descritor como referencial estatico
typedef struct{
    dados *frente;
    dados *cauda;
    int tamInfo;
} descF;

// Descritor como referencial movel
typedef struct{
    dados *frente;
    dados *cauda;
    int tamInfo;
    int tamArray;
    dados *ref;
} descM;

int comparar(info *a, info *b);
