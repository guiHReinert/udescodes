#include "stdio.h"
#include "stdlib.h"

/* (Slide 58)
Dado um vetor de inteiros v, retorne a maior soma dos números não adjacentes. Os
números podem incluir 0 ou negativos no vetor.
Exemplo 1, dado v = [2,4,6,2,5], a saída esperada é 13, considerando 2 + 6 + 5
Exemplo 2, dado v = [5,1,1,5], a saída esperada é 10, considerando 5 + 5
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

    int rep=0, soma=0, maior_soma=0;
    for(int passo=2; passo<n; passo++){
        for(int inicio=0; passo+inicio<n; inicio++){
            while(rep*passo + inicio < n){
                soma += v[rep*passo + inicio];
                // printf("(p=%d;b=%d;r=%d: %d (%d))\n", passo, inicio, rep, v[rep*passo+inicio], soma);
                rep++;
            }
            if (soma>maior_soma) maior_soma = soma;
            soma = 0;
            rep = 0;
        }
    }
    printf("%d\n", maior_soma);
}