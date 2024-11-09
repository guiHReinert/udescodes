#include <stdio.h>
#include <stdlib.h>


/*
4) Faça uma função que receba um parâmetro (por valor) com o total de minutos passados
ao longo do dia e receba também dois parâmetros (referência) no qual deve preencher
com o valor da hora e do minuto corrente. Faça um programa que leia do teclado quantos
minutos se passaram desde meia-noite e imprima a hora corrente (use a sua função).
void cacula_hora(int totalMinutos, int *ph, int *pm);
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
