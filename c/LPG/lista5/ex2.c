#include <stdio.h>
#include <stdlib.h>


/*
2) Escreva uma função que troca os valores entre duas variáveis do tipo float. Faça um
programa que leia duas variáveis e mostre seus valores na tela. Em seguida, troque os
valores (usando a função) e mostre novamente os valores.
*/
void troca_valor(float *x, float *y){
	
	
	
}

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
