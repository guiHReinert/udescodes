#include <stdio.h>
#include <stdlib.h>
/*
5) Escreva uma função que recebe um vetor e sua capacidade como parâmetros e precisa
“retornar” o maior e o menor valores do vetor.
*/
void max_min(int vet[], int tam, int *pMin, int *pMax){
    *pMin = vet[0];
    *pMax = vet[0];
    for(int g=0; g<tam; g++){
        if(vet[g] < *pMin){
            *pMin = vet[g];
        }
        if(vet[g] > *pMax){
            *pMax = vet[g];
        }
    }
}

void main(){
    int cap=0, min=0, max=0;
    printf(" Digite a capacidade do vetor: ");
    scanf("%d", &cap);
    int  arr[cap], elem;
    printf(" Digite os seus %d elementos: ", cap);
    for(int c=0; c<cap; c++){
        scanf("%d", &elem);
        arr[c] = elem;
    }
    max_min(arr, cap, &min, &max);
    printf(" Menor = %d\n Maior = %d\n", min, max);
}
