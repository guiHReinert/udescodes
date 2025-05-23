#include "arq.h"

// Printa um unico nodo
void printarNodo(nodo *nodo){
    printf("Nome: %s\n",        nodo->dados.nome);
    printf("Matricula: %d\n",   nodo->dados.matricula);
    printf("Ranking: %d\n",     nodo->dados.ranking);
    printf("Curso: %s\n",       nodo->dados.curso);
}
/*
    Printa nodo por nodo da fila SEM referencial movel no sentido da cauda para
    a frente
*/
void printarFilaSem(descF *desc){
    if(desc->cauda != NULL){
        nodo *walker = desc->cauda;
        do{
            printarNodo(walker);
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
int compararRank(info a, info b) {
    if(a.ranking < b.ranking){
        return MENOR;
    } else if( a.ranking > b.ranking){
        return MAIOR;
    } else {
        return IGUAL;
    }
}

// Criterio de comparacao: matricula dos alunos
int compararMat(info a, info b) {
    if(a.matricula < b.matricula){
        return MENOR;
    } else if( a.matricula > b.matricula){
        return MAIOR;
    } else {
        return IGUAL;
    }
}
