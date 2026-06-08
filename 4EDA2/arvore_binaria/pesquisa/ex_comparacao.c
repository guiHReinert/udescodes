#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmos.h"

int main(){ 
    srand(time(NULL));

    int tam = 10;
    for(int teste=1; teste<2; teste++){

        // Popular o vetor com inteiros aleatorios
        tam = tam * teste * 10;
        int v[tam];
        populaVetor(v, tam);
        
        printf("\n");
        for(int c=0; c<tam; c++){
            printf("%d: %d\n", c, v[c]);
        }

        
    }
}