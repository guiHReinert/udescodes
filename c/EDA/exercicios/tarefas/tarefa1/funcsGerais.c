#include "arq.h"

// Printa um unico nodo
void printarNodo(nodo *nodo){
    printf("{\tNome: %s, ",     nodo->dados.nome);
    printf("\tMatricula: %d, ", nodo->dados.matricula);
    printf("\tRanking: %d, ",   nodo->dados.ranking);
    printf("\tCurso: %s}\n",    nodo->dados.curso);
}
/*
    Printa nodo por nodo da fila SEM referencial movel no sentido da cauda para
    a frente
*/
void printarFilaSem(descS *desc){
    if(desc->cauda != NULL){
        int i = 0;
        nodo *walker = desc->cauda;
        do{
            printf("[%d]", i + 1);
            printarNodo(walker);
            i++;
            walker = walker->posterior;
        }while(walker != NULL);
    }
}

/*
    Printa nodo por nodo da fila COM referencial movel no sentido da cauda para
    a frente
*/
void printarFilaCom(descM *desc){
    nodo *walker = desc->cauda;
    do{
        printarNodo(walker);
        walker = walker->posterior;
    }while(walker != NULL);
}

// Criterio de comparacao: ranking dos alunos
int compararRank(info *a, info *b) {
    if(a->ranking < b->ranking){
        return MENOR;
    } else if( a->ranking > b->ranking){
        return MAIOR;
    } else {
        return IGUAL;
    }
}

// Criterio de comparacao: matricula dos alunos
int compararMat(info *a, info *b) {
    if(a->matricula < b->matricula){
        return MENOR;
    } else if( a->matricula > b->matricula){
        return MAIOR;
    } else {
        return IGUAL;
    }
}
