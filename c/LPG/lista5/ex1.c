#include <stdio.h>
#include <stdlib.h>
/*
1) Faça uma função que recebe dois números, a e b. A função deve incrementar a e
decrementar b.
*/
void inc_dec (int *a, int *b){
	*a++;
	*b--;
}

void main(){
    int num1, num2;
    printf("\n Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("\n Digite o segundo numero: ");
    scanf("%d", &num2);
    inc_dec(&num1, &num2);
    printf(" Numero 1: %d\n Numero 2: %d", num1, num2);
}
