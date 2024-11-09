#include <stdio.h>
#include <stdlib.h>

/*
5) Escreva uma função que realiza a união entre dois conjuntos de inteiros contidos nos
vetores v1 e v2. A função recebe os vetores e suas respectivas capacidades (n1 e n2) como
parâmetros de entrada e retorna o endereço do vetor alocado (contendo a união entre v1
e v2). Além disso, há um parâmetro passado por referência (ponteiro p3), que serve para
“retornar” a capacidade do vetor gerado. Faça o programa principal invocando a função (a
estrutura do programa é semelhante ao exemplo dado em aula – intersecção). Protótipo
da função:
int *uniao( int *v1, int n1, int *v2, int n2, int *p3 );
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
