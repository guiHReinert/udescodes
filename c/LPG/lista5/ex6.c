#include <stdio.h>
#include <stdlib.h>


/*
6) Escreva um programa que determine o maior valor de um vetor bem como sua posição no
vetor (índice). Tal processamento deve ser feito em uma função que recebe o vetor (do
tipo float) e sua capacidade, e “retorna” o maior elemento e sua posição.
void max_vetor(float vet[], int tam, float *pMax, int *pIndice);
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
