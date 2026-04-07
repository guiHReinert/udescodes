#include <stdio.h>
#include <stdlib.h>
/*
7) Faça um programa que determine o menor valor de uma matriz 3x4, bem como suas
coordenadas (linha e coluna). Tal processamento deve ser feito por uma função que
recebe a matriz e “retorna” o menor elemento e suas coordenadas (i e j).
*/
void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ){
    *pMin = mat[0][0];
    for(int g=0; g<3; g++){
        for(int u=0; u<4; u++){
            if(mat[g][u] < *pMin){
                *pMin = mat[g][u];
                *pI = g;
                *pJ = u;
            }
        }
    }
}

void main(){
    float matriz[3][4]={{0}}, elem, min;
    int i=0, j=0;
    for(int g=0; g<3 ; g++){
        printf(" Digite os 4 elementos da linha %d: ", g);
        for(int u=0; u<4; u++){
            scanf("%f", &elem);
            matriz[g][u] = elem;
        }
    }
    min_matriz(matriz, &min, &i, &j);
    printf(" Menor elemento = %f\n Linha = %d\n Coluna = %d\n", min, i, j);
}
