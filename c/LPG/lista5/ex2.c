#include <stdio.h>
#include <stdlib.h>
/*
2) Escreva uma função que troca os valores entre duas variáveis do tipo float. Faça um
programa que leia duas variáveis e mostre seus valores na tela. Em seguida, troque os
valores (usando a função) e mostre novamente os valores.
*/
void troca_valor(float *x, float *y){
	float a=*x, b=*y;
    *x = b;
    *y = a;
}

void main(){
    float num1, num2;
    printf("\n Digite o primeiro numero: ");
    scanf("%f", &num1);
    printf(" Digite o segundo numero: ");
    scanf("%f", &num2);
    printf(" a = %f\n b = %f\n", num1, num2);
    troca_valor(&num1, &num2);
    printf(" Alternados a e b:");
    printf("\n a = %f\n b = %f\n", num1, num2);
}
