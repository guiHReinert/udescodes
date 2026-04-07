#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Produto.h"

int main(int argc, char *argv[]) {
   	
	struct produto *v = NULL;	
	int i, op, n = 0;
	
	//carrega_arquivo( "produtos.txt", &v, &n );
	carrega_binario( "produtos.bin", &v, &n );
	
	do{
		printf("1-Cadastrar\n2-Mostrar\n3-Sair\n");
		scanf("%d", &op);
		switch( op ){
			case 1:
				n++;
				v = realloc( v, sizeof( struct produto ) * n );
				le_produto( &v[n-1] );
				break;
			
			case 2:
				printf("\nLista de produtos:\n");
				for( i = 0 ; i < n ; i++ ){
					printf("produto %d: ", i+1 );
					mostra_produto( v[i] );
				}
				break;				
		}			
	}while( op != 3 );
	
	//salva_arquivo( "produtos.txt", v, n );
	salva_binario( "produtos.bin", v, n );
	
	free( v );
	
	return 0;
}


