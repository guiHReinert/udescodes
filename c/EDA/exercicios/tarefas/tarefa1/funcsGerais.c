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
    Funcao de comparacao com criterio especificado a partir das tags (definidas
    em arq.h): MATRICULA e RANKING.
*/
int comparar(info *a, info *b, char tag) {
    switch(tag) {
        case MATRICULA:
            if      (a->matricula < b->matricula){return MENOR;}
            else if (a->matricula == b->matricula){return IGUAL;}
            else    {return MAIOR;}

        case RANKING:
            if      (a->ranking < b->ranking){return MENOR;}
            else if (a->ranking == b->ranking){return IGUAL;}
            else    {return MAIOR;}

        default:
            return FRACASSO;
    }
}

/*
    Utilizada em main.c para implementar uma base em uma fila SEM referencial
    movel. Para tal seguem-se os parâmetros adotados:
        - <arquivo>:       array de strings contendo todas as linhas do dataset;
        - <tamanhoDataset> quantidade de linhas do dataset;
        - <range>:         quantidade nodos a serem inseridos na fila;
        - <desc>:          descritor da fila sem referencial movel;
        - <tag>:           criterio de comparacao.
*/
void implementarBaseSem(char **arquivo, int tamanhoDataset, int range, descS *desc, char tag) {
    char **base = criarBase(arquivo, tamanhoDataset, range);
    if(base == NULL){
        printf("Erro ao criar base\n");
        return;
    }

    for(int l=0; l < range; l++){
        if(base[l] != NULL){
            info *dados = criarDados(base[l]);
            if(dados == NULL){
                printf("Erro ao criar dados\n");
                return;
            }
            inserirSem(dados, desc, comparar, tag);
        }
    }
}