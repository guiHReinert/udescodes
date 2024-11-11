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
    int len=0;
    printf(" Quantos numeros deseja inserir no vetor? ");
    scanf("%d", &len);
    float *arr1 = malloc(sizeof(float) * len);
    printf(" Digite os numeros a serem inseridos:\n > ");
    for(int g=0; g<len; g++){
        scanf("%f", &arr1[g]);
    }

    float media=0.0;
    for(int u=0; u<len; u++){
        media += arr1[u];
    }
    media /= len;
    int pos2=0;
    float *arr2 = malloc(sizeof(float) * len);
    for(int i=0; i<len; i++){
        if(arr1[i] >= media){
            arr2[pos2++] = arr1[i];
        }
    }

    printf(" Media = %f\n Vetor final:\n { ", media);
    for(int c=0; c<pos2; c++){
        printf("%.2f ", arr2[c]);
    }
    printf("}\n");
}
