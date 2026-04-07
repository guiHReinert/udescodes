#include <stdio.h>
#include <stdlib.h>
/*
4) Faça um programa que leia uma certa quantidade de inteiros que são armazenados num
vetor v. A quantidade deve ser definida pelo usuário, e o programa aloca espaço para v. O
programa deve armazenar os valores positivos em um vetor vp e o valores negativos no
vetor vn. Como as quantidades de valores positivos e negativos são desconhecidas, o
espaço para vp e vn deve ser alocado dinamicamente. Os vetores vp e vn não devem
conter zeros. Ao final, imprima os três vetores. Pode ser feito com malloc() ou com
realloc().
*/

void printar(int *arr, int size){
    printf(" { ");
    for(int c=0; c < size; c++){
        printf("%d ", arr[c]);
    }
    printf("}\n");
}

void main(){
    int len=0;
    printf(" Quantos numeros deseja inserir no vetor? ");
    scanf("%d", &len);
    int *v = malloc(sizeof(int) * len);
    printf(" Digite os numeros a serem inseridos:\n > ");
    for(int g=0; g<len; g++){
        scanf("%d", &v[g]);
    }

    int *vn = malloc(sizeof(v[0])), *vp = malloc(sizeof(v[0]));
    int  posN=0, posP=0;
    for(int u=0; u<len; u++){
        if(v[u] < 0){
            vn = realloc(vn, sizeof(v[0]) * posN+1);
            vn[posN++] = v[u];
        }
    }
    for(int i=0; i<len; i++){
        if(v[i] > 0){
            vp = realloc(vp, sizeof(v[0]) * posP+1);
            vp[posP++] = v[i];
        }
    }

    printf(" Vetor original:");
    printar(v, len);
    printf(" Valores negativos:");
    printar(vn, posN);
    printf(" Valores positivos:");
    printar(vp, posP);

    free(v);
    free(vn);
    free(vp);
}
