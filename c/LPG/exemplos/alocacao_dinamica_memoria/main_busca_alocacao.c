#include <stdio.h>
#include <stdlib.h>

int * busca( int v[], int n, int chave );
int * busca_v2( int v[], int n, int chave ); // com realocação

int main(int argc, char *argv[]) {
	/*
	int vet[] = {3, 6, 7, -1, 3, 12, 9, 8, 3, 17, 3, -1, 3, 12 };
	int k = sizeof( vet ) / sizeof( vet[0] );
	*/
	int *vet = NULL;
	int k = 0, x, i;
	printf("Digite um valor (ou 0 para sair): ");
	scanf("%d", &x );
	
	while( x != 0 ){
		k++;
		vet = realloc( vet, sizeof( int )* k );
		vet[k-1] = x;
		printf("Digite um valor (ou 0 para sair): ");
		scanf("%d", &x );
	}
	
	printf("V = ");
	for( i = 0 ; i < k ; i++ )
		printf("%d ", vet[i] );
	printf("\n\n");	
	
	int chave;
	printf("Digite o valor a ser buscado: ");
	scanf("%d", &chave);
	
	int *indices = busca_v2( vet, k, chave );
	
	if( indices[0] == -1 )
		printf("valor nao encontrado!\n");
	else{
		int i;
		printf("Valor encontrado nos seguintes indices:\n");
		for( i = 0 ; indices[i] != -1 ; i++ )
			printf("%d\n", indices[i]);
	}
	
	free( indices );
	
	return 0;
}

int * busca( int v[], int n, int chave ){
	int cont = 0, i;
	for( i = 0 ; i < n ; i++ )
		if( v[i] == chave )
			cont++;

	int *p = malloc( sizeof(int) * (cont+1) );
	
	int j = 0;
	for( i = 0 ; i < n ; i++ )
		if( v[i] == chave ){
			p[j] = i;
			j++;
		}
		
	p[j] = -1;
	
	return p;
}


int * busca_v2( int v[], int n, int chave ){
	int cont = 1, i;
	int *p = malloc( sizeof(int) );
	
	for( i = 0 ; i < n ; i++ )
		if( v[i] == chave ){
			p = realloc( p, sizeof(int) * (cont+1) );
			p[cont-1] = i;
			cont++;
		}
		
	p[cont-1] = -1;
	
	return p;
}
