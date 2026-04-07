#include "Produto.h"
#include <stdio.h>

void mostra_produto( struct produto p ){
	printf("(%d, '%s', R$%.2f, ", p.codigo, p.descricao, p.preco);
	mostra_data( p.validade );
	printf(")\n");
}

// V2 mostra o tratamento de todos os campos (não é recomendado...)
void mostra_produto_v2( struct produto p ){
	printf("(%d, '%s', R$%.2f, %d/%d/%d)\n",
			p.codigo, p.descricao, p.preco,
			p.validade.dia, p.validade.mes, p.validade.ano);
}


void le_produto( struct produto *p ){
	printf("Digite o codigo: ");
	scanf("%d", &p->codigo);
	printf("Digite a descricao: ");
	scanf(" %[^\n]", p->descricao);
	printf("Digite o preco: ");
	scanf("%f", &(*p).preco);
	printf("Digite a data de validade:\n");
	le_data( &p->validade );
}

void mostra_data( struct data d ){
	printf("%d/%d/%d", d.dia, d.mes, d.ano);
}

void le_data( struct data *p ){
	printf("Digite o dia: ");
	scanf("%d", &p->dia);
	printf("Digite o mes: ");
	scanf("%d", &p->mes);
	printf("Digite o ano: ");
	scanf("%d", &p->ano);
}

