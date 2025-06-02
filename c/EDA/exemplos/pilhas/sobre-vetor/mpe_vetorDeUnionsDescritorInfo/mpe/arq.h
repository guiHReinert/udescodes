#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESSO 1
#define FRACASSO 0

//======================MODELO DE DADOS DA APLICACAO=====================

typedef struct informacao{ 
	char nome[30];
	int idade;
}info;


//======================MODELO DE DADOS=====================
/* N� descritor de uma pilha */
typedef struct descpilha{
    int topo;
    int inicioParticao;
} DescPilha;

/* N� da Multi-Pilha */
typedef union nomp{
    DescPilha descritor;
    info* dados;
} NoMP;

/* Descritor da Multi-Pilha */
typedef struct mp {
    int N; /* N = N�mero de Pilhas*/
    int L; /* L = Tamanho m�ximo da parti��o de cada Pilha*/
    int tamInfo;
    NoMP *vet;
} MP;

//======================FUNCIONALIDADE DA APLICACAO=====================
int menu(MP *ptr, int nPilha, int lPilha);

//======================FUNCIONALIDADE DA PILHA=====================
MP * cria(MP *p, int N, int L, int tamInfo);
int insereNaPilha(MP *p, int nPilha, info* novo);
int removeDaPilha(MP *p, int nPilha, info* removido);
int consultaTopo(MP *p, int nPilha, info* consultado);
MP * destroi(MP *p);
void exibeTamanhoMP(MP *desc);


