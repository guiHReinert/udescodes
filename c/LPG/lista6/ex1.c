#include <stdio.h>
#include <stdlib.h>


/*
1) Escreva uma função que recebe um vetor float v e sua capacidade n, e retorne o endereço
de um vetor alocado dinamicamente, cujo conteúdo seja o mesmo de v, ou seja, a função
retorna um clone do vetor v. Faça o programa principal com a entrada de dados (ou um
vetor fixo), chame a função e mostre o vetor resultante na tela. Protótipo da função:
float *clone( float *v, int n );
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
