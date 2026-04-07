#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct produto{
	int codigo;
	char descricao[20];
	float preco;
};

void mostra_produto( struct produto p );
void le_produto( struct produto *p );

int main(int argc, char *argv[]) {
	//struct produto v[3];
	
	struct produto *v;
	
	int i, n;
	printf("Quantos produtos? ");
	scanf("%d", &n);
	
	v = malloc( n * sizeof( struct produto ) );
	
	for( i = 0 ; i < n ; i++ ){
		printf("Entrada do produto %d:\n", i+1 );
		le_produto( v + i ); // &v[i]
	}
	printf("\nLista de produtos:\n");
	for( i = 0 ; i < n ; i++ ){
		printf("produto %d: ", i+1 );
		mostra_produto( v[i] );
	}
	
	free( v );
	
	return 0;
}


void mostra_produto( struct produto p ){
	printf("(%d, '%s', R$%.2f)\n", p.codigo, p.descricao, p.preco);
}

void le_produto( struct produto *p ){
	printf("Digite o codigo: ");
	scanf("%d", &p->codigo);
	printf("Digite a descricao: ");
	scanf(" %[^\n]", p->descricao);
	printf("Digite o preco: ");
	scanf("%f", &(*p).preco);
}

