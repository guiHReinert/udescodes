#include "stdio.h"
#include "stdlib.h"

/* (Slide 49)
2. Dado um vetor de números inteiros v, retorne um novo vetor de forma que cada
elemento no índice i seja o produto de todos os números na matriz original, com
exceção de i.
Exemplo 1: dado v = [1,2,3,4,5], a saída esperada é [120,60,40,30,24]
Exemplo 2: dado v = [3,2,1], a saída esperada é [2,3,6]
*/

int main(){
    int n;
    printf("Digite o tamanho de v e seus elementos:\n");
    scanf("%d", &n);
    int v[n], num;
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        v[i] = num;
    }

    int m[n];
    printf("\n[");
    for(int i=0; i<n; i++){
        num = 1;
        for(int j=0; j<n; j++){
            if(i==j){continue;}
            num *= v[j];
        }
        m[i] = num;
        printf("%d ", m[i]);
    }
    printf("]\n");

    return 0;
}