#include <stdio.h>
#include <stdlib.h>
/*
5) Escreva uma função que realiza a união entre dois conjuntos de inteiros contidos nos
vetores v1 e v2. A função recebe os vetores e suas respectivas capacidades (n1 e n2) como
parâmetros de entrada e retorna o endereço do vetor alocado (contendo a união entre v1
e v2). Além disso, há um parâmetro passado por referência (ponteiro p3), que serve para
“retornar” a capacidade do vetor gerado. Faça o programa principal invocando a função (a
estrutura do programa é semelhante ao exemplo dado em aula – intersecção).
*/
int search(int *arr, int len, int num){
    for(int c=0; c<len; c++){
        if(arr[c]==num){
            return c;
        }
    }
    return -1;
}

int *uniao( int *v1, int n1, int *v2, int n2, int *p3){
    int *v3=malloc(sizeof(v1[0]));
    *p3 = 0;
    for(int i=0; i<n1; i++){
        if(search(v3, *p3, v1[i]) < 0){
            v3 = realloc(v3, sizeof(v3[0]) * ((*p3)+1));
            v3[(*p3)++] = v1[i];
        }
    }
    for(int l=0; l<n2; l++){
        if(search(v3, *p3, v2[l]) < 0){
            v3 = realloc(v3, sizeof(v3[0]) * ((*p3)+1));
            v3[(*p3)++] = v2[l];
        }
    }
    return v3;
}

void printar(int *arr, int len){
    printf(" { ");
    for(int c=0; c < len; c++){
        printf("%d ", arr[c]);
    }
    printf("}\n");
}

void main(){
    int *arr1 = malloc(sizeof(int)), *arr2 = malloc(sizeof(int));
    int len1, len2;

    printf(" Qual o tamanho do conjunto 1? ");
    scanf("%d", &len1);
    arr1 = realloc(arr1, sizeof(arr1[0]) * len1);
    printf(" Digite os %d valores do conjunto 1:\n > ", len1);
    for(int g=0; g<len1; g++){
        scanf("%d", &arr1[g]);
    }

    printf(" Qual o tamanho do conjunto 2? ");
    scanf("%d", &len2);
    arr2 = realloc(arr2, sizeof(arr2[0]) * len2);
    printf(" Digite os %d valores do conjunto 2:\n > ", len2);
    for(int g=0; g<len2; g++){
        scanf("%d", &arr2[g]);
    }

    int len3=0;
    int *arrFinal={0};
    arrFinal = uniao(arr1, len1, arr2, len2, &len3);

    printf(" Conjunto 1:");
    printar(arr1, len1);
    printf(" Conjunto 2:");
    printar(arr2, len2);
    printf(" Uniao dos conjuntos 1 e 2:");
    printar(arrFinal, len3);

    free(arr1);
    free(arr2);
    free(arrFinal);
}
