#include "arq.h"

/*
    Le o arquivo CSV e armazena <tamBase> alunos em um array de strings. Cada
    string deste array eh aleatoriamente selecionado para outro array de strings.
    Chama-se de "base" este novo array de strings.
*/
char **lerDataset(char *file){
    FILE *file = fopen(file, "dataset_v1.csv");
    if(file != NULL){
        char **pessoas = (char **) malloc(TAM_CSV * sizeof(char *));
        if(*pessoas != NULL){
            for(int p=0; p < TAM_CSV; p++){
                pessoas[p] = (char *) malloc(TAM_LINHA * sizeof(char));
                if(pessoas[p] != NULL){
                    // Le uma linha de do arquivo CSV
                    if(fgets(pessoas[p], TAM_CSV, file) != NULL){

                    }
                }
            }
        }
    }
    printf("Erro ao abrir o arquivo\n");
    return NULL;
}


/*
    Cada string contida em uma base eh convertida em um unico nodo do tipo <nodo>.
    A funcao retorna o ponteiro para este nodo.

    OBS.: O motivo da funcao criar um unico nodo, ao inves de varios neste
    momento, eh por que relacao entre todos os nodos de uma mesma base eh feita
    somente a partir de suas insercoes em cada fila.
    Ou seja, nao eh competencia dela adiantar este processo.
*/
nodo *criarNodo(char **base){

}
