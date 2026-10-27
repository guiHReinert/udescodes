#include "arq.h"

void carregar_grafo(Grafo *grafo, char* path, int* num_vertices){
    FILE* file = fopen(path, "r");
    if(!file){
        printf("Erro ao abrir o arquivo\n");
    }
    char buffer[BUFFER];
    while(fgets(buffer, BUFFER, file)){
        char* token = strtok(buffer, ", \n");
        int tamanho;
        if(token == NULL){continue;}
        while(token != NULL){
            tamanho++;
            token = strtok(NULL, ", \n");     
        }
    }
    fclose(file);
}

