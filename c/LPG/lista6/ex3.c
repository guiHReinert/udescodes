#include <stdio.h>
#include <stdlib.h>

/*
3) Escreva um programa que aloca dinamicamente um vetor do tipo float e realiza a entrada
de dados. Em seguida, o programa deve calcular a média dos valores do vetor e alocar
dinamicamente um novo vetor contendo somente os valores maiores ou iguais à media. O
processo pode ser feito usando malloc(), ou seja, fazendo a contagem, alocação e cópia
dos valores. Outra alternativa consiste em usar realloc() para ir aumentando o espaço
alocado à medida que os valores vão sendo encontrados.
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
