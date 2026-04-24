#include "stdio.h"
#include "stdlib.h"

/* (Slide 58)
Dado um vetor de inteiros v, retorne a maior soma dos números não adjacentes. Os
números podem incluir 0 ou negativos no vetor.
Exemplo 1, dado v = [2,4,6,2,5], a saída esperada é 13, considerando 2 + 6 + 5
Exemplo 2, dado v = [5,1,1,5], a saída esperada é 10, considerando 5 + 5
*/

int maior_soma(int *v, int tam){
    // int rep=0, soma=0, maior_soma=0;
    // for(int passo=2; passo<tam; passo++){
    //     for(int inicio=0; passo+inicio<tam; inicio++){
    //         while(rep*passo + inicio < tam){
    //             soma += v[rep*passo + inicio];
    //             // printf("(p=%d;b=%d;r=%d: %d (%d))\n", passo, inicio, rep, v[rep*passo+inicio], soma);
    //             rep++;
    //         }
    //         if (soma>maior_soma) maior_soma = soma;
    //         soma = 0;
    //         rep = 0;
    //     }
    // }
    // return maior_soma;

    /*
    Intercala entre a lógica de imparidade da soma (primeiro valores de indices
    impares ou pares) de modo que a soma aceita serah a maior entre as duas pos
    siveis
    */
    int soma = v[0], ant=0, novo=0;
    for (int i = 1; i < tam; i++) {
        novo = soma > ant ? soma : ant;
        soma = ant + v[i];
        ant = novo;
        printf("i=%d: (v=%d)\n\tnovo=%d\n\tsoma=%d\n\tant=%d\n",i,v[i],novo,soma,ant);
    }
    return soma > ant ? soma : ant;
}

int main(){
    int n;
    printf("Digite o tamanho de v e seus elementos:\n");
    scanf("%d", &n);
    int v[n], num;
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        v[i] = num;
    }

    printf("%d\n", maior_soma(v, n));
}