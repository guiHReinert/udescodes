#include "arq.h"

// Printa todos os campos da MPE.
void printarMP(descMP *desc){

    printf("\ntopo1: %d\ntopo2: %d\ntamVet: %d\nNodos:",
        desc->topo1, desc->topo2, desc->tamVet);

        int p1 = printarPilhaDireta(desc),
            p2 = printarPilhaInversa(desc);

    // Caso a MPE estiver vazia
    if(p1 == VAZIA && p2 == VAZIA){
        printf(" vazio\n");
    }
    else{
        printf("\n");
    }
}

// Printa todos os nodos da pilha do sentido direto.
int printarPilhaDireta(descMP *desc){
    if(desc->topo1 > -1){

        for(int i=0; i <= desc->topo1; i++){
            if(desc->vet[i].dados){
                printf("\n 1 [%d] Num: %d", i, desc->vet[i].dados->num);
            }    
            else{
                printf("\n 1 [%d] Num: vazio", i);
            }
        }

        return SUCESSO;
    }
    else{
        return VAZIA;
    }
}

// Printa todos os nodos da pilha do sentido inverso.
int printarPilhaInversa(descMP *desc){
    if(desc->topo2 < desc->tamVet){

        for(int i=desc->topo2; i < desc->tamVet; i++){
            if(desc->vet[i].dados){
                printf("\n 2 [%d] Num: %d", i, desc->vet[i].dados->num);
            }    
            else{
                printf("\n 2 [%d] Num: vazio", i);
            }
        }

        return SUCESSO;
    }
    else{
        return VAZIA;
    }
}