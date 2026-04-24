#include "stdio.h"
#include "stdlib.h"

/* (Slide 50)
3. Dado um vetor de números inteiros v, encontre o primeiro inteiro positivo ausente no
vetor. Em outras palavras, deve ser retornado o menor inteiro positivo que não existe no
vetor. A matriz pode conter duplicados e números negativos também. O algoritmo deve
apresentar complexidade de tempo linear e de espaço constante (pode desconsiderar
o esforço para ordenação do vetor).
Exemplo 1, dado v = [3,4,-1,1], a saída esperada é 2
Exemplo 2, dado v = [1,2,0], a saída esperada é 3
*/

int bubble_sort(int *v, int tam){
    for(int i=0; i<tam-1; i++){         // O ultimo loop eh irrelevante
        for(int j=0; j<tam-i-1; j++){   // i eh o numero de pares jah ordenados
            if(v[j] > v[j+1]){          // Se o proximo valor for menor
                int aux = v[j];         // troque o atual pelo proximo
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }    
}

int primeiro_int(int *vet, int tam){
    // Copia do vetor
    int v[tam], p = 1;
    for(int i=0; i<tam; i++){
        v[i] = vet[i];
    }

    /*
    Usa o tamanho do vetor para realizar a contagem otima e "elimina" os valores
    inuteis
    */
    for(int i=0; i<tam; i++) {
        if(v[i] > tam+1){
            v[i] == -1;
        }
    }
    bubble_sort(v, tam);
    for (int i=0; i<tam; i++) {
        if (v[i] > 0 && v[i] == p){
            p++;
        }
    }
    return p;
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

    printf("%d\n", primeiro_int(v, n));
    
    return 0;
}