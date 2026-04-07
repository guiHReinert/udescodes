#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

void gera_valores( int x[], int n, int limite );
void mostra_vetor( int x[], int n );
int busca_seq( int x[], int n, int chave );

int main(int argc, char *argv[]) {
	int v[MAX];
	gera_valores( v, MAX, 100 );
	mostra_vetor( v, MAX );
	int chave;
	printf("Digite o valor a ser buscado: ");
	scanf("%d", &chave);
	int id = busca_seq( v, MAX, chave );
	if( id == -1 )
		printf("Valor nao encontrado!\n");
	else
		printf("Valor encontrado no indice %d\n", id);
	
	return 0;
}

void gera_valores( int x[], int n, int limite ){
	int i;
	srand( time(0) );
	for( i = 0 ; i < n ; i++)
		x[i] = rand() % limite + 1;
}

void mostra_vetor( int x[], int n ){
	int i;
	for( i = 0 ; i < n ; i++)
		printf("%d ", x[i] );
	printf("\n");
}

int busca_seq( int x[], int n, int chave ){
	int i;
	for( i = 0 ; i < n ; i++){
		if( x[i] == chave )
			return i;
	}
	return -1;
}

