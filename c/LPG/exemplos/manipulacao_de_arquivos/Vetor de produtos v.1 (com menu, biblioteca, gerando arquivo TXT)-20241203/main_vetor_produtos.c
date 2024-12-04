#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Produto.h"

int main(int argc, char *argv[]) {
	/*
	//struct data x = { 14, 11, 2024 };
	struct data x;
	x.dia = 14;
	x.mes = 11;
	x.ano = 2024;	
	
	mostra_data( x );
	*/
	
	//struct produto v[3];
    	
	struct produto *v = NULL;	
	int i, op, n = 0;
	
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
	
	FILE *f = fopen( "produtos.txt", "wt" );
	fprintf( f, "\nLista de produtos:\n");
	for( i = 0 ; i < n ; i++ ){
		fprintf( f, "produto %d: ", i+1 );
		fprintf( f, "(%d, '%s', R$%.2f, %d/%d/%d)\n",
			v[i].codigo, v[i].descricao, v[i].preco,
			v[i].validade.dia, v[i].validade.mes, v[i].validade.ano);
	}
	
	fclose ( f );
	
	free( v );
	
	return 0;
}


