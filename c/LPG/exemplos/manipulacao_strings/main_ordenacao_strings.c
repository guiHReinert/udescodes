#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 50

void mostra_lista(char x[][N], int n );
void ordena_lista(char x[][N], int n );

int main(int argc, char *argv[]) {
	char lista[][N] = { "Joao@gmail.com", "Maria", "Fulano", "Ciclano da Silva",
						"Alo mundo", "Teste 123", "Chega!!",
						"Mais uma...", "Joao@yahoo.com"};
	int n = sizeof( lista ) / N;
	printf("Total: %d\n", n);
	
	mostra_lista( lista, n );
	ordena_lista( lista, n );
	mostra_lista( lista, n );
	
	return 0;
}

void mostra_lista(char x[][N], int n ){
	int i;
	for( i = 0 ; i < n ; i++ )
		printf("%d: '%s'\n", i, x[i] );
	printf("\n");
}

void ordena_lista(char x[][N], int n ){
	int i, j;
	for(i = 0; i < n-1; i++){
		int i_menor = i;
		for(j = i+1; j < n; j++){
			if( strcmp( x[j], x[i_menor] ) < 0 ) //vet[j] < vet[i_menor]
				i_menor = j;
		}
		char aux[N];
		strcpy(aux, x[i]); //aux = x[i];
		strcpy( x[i], x[i_menor]); //x[i] = x[i_menor];
		strcpy( x[i_menor], aux ); //x[i_menor] = aux;
	}
}


