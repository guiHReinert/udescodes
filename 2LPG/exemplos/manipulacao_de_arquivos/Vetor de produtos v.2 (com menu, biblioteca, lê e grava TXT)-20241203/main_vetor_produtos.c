#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Produto.h"

int main(int argc, char *argv[]) {
   	
	struct produto *v = NULL;	
	int i, op, n = 0;
	
	FILE *f = fopen( "produtos.txt", "rt" );
	if( f == NULL ){
		printf("Cadastro nao encontrado!\n");
	}
	else{
		fscanf( f, "%d", &n);
		v = malloc( sizeof( struct produto ) * n );		
		for( i = 0 ; i < n ; i++ ){
			fscanf( f, "%d", &v[i].codigo );
			fscanf( f, " %[^\n]", v[i].descricao );
			fscanf( f, "%f", &v[i].preco );
			fscanf( f, "%d %d %d", &v[i].validade.dia, &v[i].validade.mes, &v[i].validade.ano);
		}
		fclose ( f );
		printf("%d registros carregados!\n", n );
	}
	
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
	
	f = fopen( "produtos.txt", "wt" );
	fprintf( f, "%d\n", n);
	for( i = 0 ; i < n ; i++ ){
		fprintf( f, "%d\n",	v[i].codigo );
		fprintf( f, "%s\n",	v[i].descricao );
		fprintf( f, "%.2f\n", v[i].preco );
		fprintf( f, "%d %d %d\n", v[i].validade.dia, v[i].validade.mes, v[i].validade.ano);
	}
	
	fclose ( f );
	
	free( v );
	
	return 0;
}


