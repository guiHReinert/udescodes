#include <stdio.h>
#include <stdlib.h>

#define TAM 3

int main(int argc, char *argv[]) {
	//int *listas[TAM];
	//int qtd[TAM];
	int **listas;
	int *qtd;
	int tam, i, j;
	
	printf("Quantas listas? ");
	scanf("%d", &tam );
	
	qtd = malloc( sizeof(int) * tam );
	listas = malloc( sizeof(int*) * tam );
	
	// Alocação da estrutura e entrada de dados
	for( i = 0 ; i < tam ; i++ ){
		printf("Quantos valores para a lista %d? ", i);
		scanf("%d", &qtd[i]);
		listas[i] = malloc( sizeof(int) * qtd[i] );
		for( j = 0 ; j < qtd[i] ; j++ ){
			printf("Digite o valor na posicao %d: ", j);
			scanf("%d", &listas[i][j]);
		}
	}
		
	// Saída no console.
	for( i = 0 ; i < tam ; i++ ){
		printf("Lista %d (%d valores):", i, qtd[i]);
		for( j = 0 ; j < qtd[i] ; j++ )
			printf("%d ", listas[i][j]);
		printf("\n");
	}
	
	// Libera a memória.
	for( i = 0 ; i < tam ; i++ )
		free( listas[i] );
	free( listas );
	free( qtd );	
	return 0;
}

