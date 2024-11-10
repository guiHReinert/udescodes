#include <stdio.h>
#include <stdlib.h>
/*
6) Escreva um programa que determine o maior valor de um vetor bem como sua posição no
vetor (índice). Tal processamento deve ser feito em uma função que recebe o vetor (do
tipo float) e sua capacidade, e “retorna” o maior elemento e sua posição.
*/
void max_vetor(float vet[], int tam, float *pMax, int *pIndice){
    *pMax = vet[0];
    for(int g=0; g<tam; g++){
        if(*pMax < vet[g]){
            *pMax = vet[g];
            *pIndice = g;
        }
    }
}

void main(){
    int len=0, pos=0;
    printf(" Digite o tamanho do vetor: ");
    scanf("%d", &len);
    float arr[len], elem=0, max=0;
    printf(" Digite os %d elementos do vetor: ", len);
    for(int c=0; c<len; c++){
        scanf("%f", &elem);
        arr[c] = elem;
    }
    max_vetor(arr, len, &max, &pos);
    printf(" Maior numero = %f\n Posicao = %d\n", max, pos);
}
