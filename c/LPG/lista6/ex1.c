#include <stdio.h>
#include <stdlib.h>
/*
1) Escreva uma função que recebe um vetor float v e sua capacidade n, e retorne o endereço
de um vetor alocado dinamicamente, cujo conteúdo seja o mesmo de v, ou seja, a função
retorna um clone do vetor v. Faça o programa principal com a entrada de dados (ou um
vetor fixo), chame a função e mostre o vetor resultante na tela.
*/
float *clone( float *v, int n ){
    float *newV = malloc(sizeof(v[0]) * n);
    for(int c=0; c<n; c++){
        newV[c] = v[c];
    }
    return newV;
}

void main(){
    int len;
    printf(" Digite o tamanho do vetor: ");
    scanf("%d", &len);
    float arr[len];
    printf(" Digite os %d numeros do vetor: ", len);
    for(int g=0; g<len; g++){
        scanf("%f", &arr[g]);
    }

    float *newAddress;
    newAddress = clone(arr, len);
    
    printf(" Novo endereco do vetor alocado: %p\n", newAddress);
    printf(" Vetor alocado:\n {");
    for(int c=0; c<len; c++){
        printf("%f, ", *(newAddress+c));
    }
    printf("}\n");

    free(newAddress);
}
