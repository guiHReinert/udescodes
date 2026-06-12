#include "funcoes.h"

/*
    Como compilar este projeto:

clear && gcc main.c funcoes.c -o main && ./main

*/

void main(){
    char* arquivo = "palavras_filtradas_4letras.txt";
    Grafo** grafo;
    carregar_lista_adjacencias(grafo, arquivo);
    int num_vertices = (*grafo)->num_vertices;

    printar_lista_adjacencias(*grafo, 20, 10);
    printf("%d\n", (*grafo)->num_vertices);
}