#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000

void gera_valores_ordem( int x[], int n, int limite );
void mostra_vetor( int x[], int n );
int busca_binaria( int x[], int n, int chave );

int main(int argc, char *argv[]) {
	int v[MAX];
	gera_valores_ordem( v, MAX, 100 );
	mostra_vetor( v, MAX );
	
	int chave;
	printf("Digite o valor a ser buscado: ");
	scanf("%d", &chave);
	int id = busca_binaria( v, MAX, chave );
	if( id == -1 )
		printf("Valor nao encontrado!\n");
	else
		printf("Valor encontrado no indice %d\n", id);
	
	return 0;
	
}

void gera_valores_ordem( int x[], int n, int limite ){
	int i;
	srand( time(0) );
	x[0] = rand() % limite + 1;
	for( i = 1 ; i < n ; i++ )
		x[i] = x[i-1] + rand() % 10 + 1;
}

void mostra_vetor( int x[], int n ){
	int i;
	for( i = 0 ; i < n ; i++)
		printf("[%d] %d\n", i, x[i] );
	printf("\n");
}

int busca_binaria( int x[], int n, int chave ){
	int ini = 0, fim = n-1, meio;
	int cont = 0;
	do{
		cont++;
		meio = ( ini + fim ) / 2;
		if( x[meio] == chave ){
			printf("... busca executada em %d iteracoes...\n", cont);
			return meio;
		}
		if( x[meio] < chave)
			ini = meio + 1;
		else
			fim = meio - 1;
	}while( ini <= fim );
	printf("... busca executada em %d iteracoes...\n", cont);
	return -1;
}

