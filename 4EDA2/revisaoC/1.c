#include "stdio.h"
#include "stdlib.h"

/*  (Slide 49)
1. Dado um vetor de números inteiros v de tamanho n e um número k,
retorne verdadeiro se a soma de qualquer par de números em v for igual a k.
Exemplo: dado v = [10,15,3,7] e k = 17, a saída deve ser true, pois 10 + 7 é 17
*/

int main(){
    int n;
    printf("Digite o tamanho e os valores de v:\n");
    scanf("%d", &n);
    int v[n], num;
    for(int i=0; i<n; i++){
        scanf("%d", &num);
        v[i] = num;
    }

    int k, ans=0;
    printf("Digite o valor de k: ");
    scanf("%d", &k);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){ // Evita repetição de elementos
            if(v[i]+v[j] == k){
                ans = 1;
                break;
            }
        }
    }
    ans ? printf("true\n") : printf("false\n");

    return 0;
}