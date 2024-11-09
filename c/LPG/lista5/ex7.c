#include <stdio.h>
#include <stdlib.h>

/*
7) Faça um programa que determine o menor valor de uma matriz 3x4, bem como suas
coordenadas (linha e coluna). Tal processamento deve ser feito por uma função que
recebe a matriz e “retorna” o menor elemento e suas coordenadas (i e j).
void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ);
*/

void main(){
    printf("Escolha uma questao da lista: \
    \n1) Tipo de triangulo \
    \n2) Maior de Tres Valores \
    \n3) Verificacao 0 a 9 \
    \n4) Soma de Impares \
    \n5) N Primeiros Numeros Primos \
    \n6) N Primeiros Termos de Fibonacci \
    \n7) Soma Especial \
    \n8) Soma Simples \
    \n9) Serie Harmonica \
    \n10) Somatorio Numero de Euler \
    \n\n > ");
    int ans; scanf("%d", &ans);
    switch(ans){
        case 1: triangleType(); break;
        default: printf("Digite um índice correto! (entre 1 e 10)\n");
    }
}
