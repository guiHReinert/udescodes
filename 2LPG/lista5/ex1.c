#include <stdio.h>
#include <stdlib.h>
/*
1) Faça uma função que recebe dois números, a e b. A função deve incrementar a e
decrementar b.
*/
void inc_dec (int *a, int *b){
	(*a)++;
	(*b)--;
}

void main(){
    int num1, num2;
    printf("\n Digite o numero a: ");
    scanf("%d", &num1);
    printf(" Digite o numero b: ");
    scanf("%d", &num2);
    inc_dec(&num1, &num2);
    printf(" a = %d\n b = %d\n", num1, num2);
}
