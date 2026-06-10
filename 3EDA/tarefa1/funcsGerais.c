#include "arq.h"

// Printa um unico nodo
void printarNodo(nodo *nodo){
    printf("{\tNome: %s, ",     nodo->dados.nome);
    printf("\tMatricula: %d, ", nodo->dados.matricula);
    printf("\tRanking: %d, ",   nodo->dados.ranking);
    printf("\tCurso: %-13s%3s}\n",    nodo->dados.curso, "");
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
            printf("[%d]\t", i + 1);
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
            printf("[%d]\t", i);
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

        /*
            A o criterio de ranking serah considerado por ordem decrescente. Ou
            seja, serao trocadas as constantes de MENOR com MAIOR.
        */
        case RANKING:
            if      (a->ranking < b->ranking){return MAIOR;}
            else if (a->ranking == b->ranking){return IGUAL;}
            else    {return MENOR;}

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

    // Aloca dinamicamente a base de dados com <range> strings.
    char **base = criarBase(arquivo, tamanhoDataset, range);
    if(base == NULL){
        printf("Erro ao criar base\n");
        return;
    }

    /*
        Para cada linha de base, aloca dinamicamente um novo struct <info> desta
        linha e insere na fila sem referencial movel.
    */
    for(int l=0; l < range; l++){
        if(base[l] != NULL){
            info *dados = criarDados(base[l]);
            if(dados == NULL){
                printf("Erro ao criar dados\n");
                return;
            }

            // Prints de debug do comportamento da fila na insercao de nodos.
            // printf("\n NOVO NODO: ");
            // printarNodo(criarNodo(dados));

            inserirSem(dados, desc, comparar, tag);
            // printarFilaSem(desc);
        }
    }
}

/*
    Utilizada em main.c para implementar uma base em uma fila COM referencial
    movel. Para tal seguem-se os parâmetros adotados:
        - <arquivo>:       array de strings contendo todas as linhas do dataset;
        - <tamanhoDataset> quantidade de linhas do dataset;
        - <range>:         quantidade nodos a serem inseridos na fila;
        - <desc>:          descritor da fila com referencial movel;
        - <tag>:           criterio de comparacao.
*/
void implementarBaseCom(char **arquivo, int tamanhoDataset, int range, descM *desc, char tag) {

    // Aloca dinamicamente a base de dados com <range> strings.
    char **base = criarBase(arquivo, tamanhoDataset, range);
    if(base == NULL){
        printf("Erro ao criar base\n");
        return;
    }

    /*
        Para cada linha de base, aloca dinamicamente um novo struct <info> desta
        linha e insere na fila com referencial movel.
    */
    for(int l=0; l < range; l++){
        if(base[l] != NULL){
            info *dados = criarDados(base[l]);
            if(dados == NULL){
                printf("Erro ao criar dados\n");
                return;
            }

            // Prints de debug do comportamento da fila na insercao de nodos.
            // printf("\n NOVO NODO: ");
            // printarNodo(criarNodo(dados));
            // if(desc->ref){
            //     printf(" REF. MOVEL:");
            //     printarNodo(desc->ref);
            // }

            inserirCom(dados, desc, comparar, tag);
            // printarFilaCom(desc);
        }
    }
}