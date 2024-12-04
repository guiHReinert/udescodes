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
	struct produto x;
	
	x.codigo = 123;
	strcpy( x.descricao, "Caderno" );
	x.preco = 10;
	
	mostra_produto( x );
	
	le_produto( &x );
	mostra_produto( x );
		
	struct produto y = x;	
	mostra_produto( y );
	
	
	struct produto z;
	z.codigo = 1;
	mostra_produto( z );
	

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

