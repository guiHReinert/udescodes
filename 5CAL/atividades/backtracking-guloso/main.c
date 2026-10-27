#include "arq.h"

int main(int argc, char* argv[]) {
    char* arquivo = "grafo_25anos.csv";

    Grafo* grafo = criar_grafo(10);

    grafo ? printf("Sim\n") :  printf("Nao\n");
    grafo ? printf("%ld\n", sizeof(grafo->matriz_cores)/sizeof(int)) :  printf("Vazio\n");

    printar_grafo(grafo);

    return 0;
}
