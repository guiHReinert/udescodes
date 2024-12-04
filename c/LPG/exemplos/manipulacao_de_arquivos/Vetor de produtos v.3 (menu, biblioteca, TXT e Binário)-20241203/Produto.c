#include "Produto.h"
#include <stdio.h>
#include <stdlib.h>

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

void carrega_arquivo( char *nome_arq, struct produto **p, int *p_n ){
	FILE *f = fopen( nome_arq, "rt" );
	if( f == NULL ){
		printf("Cadastro nao encontrado!\n");
	}
	else{
		int i;
		fscanf( f, "%d", p_n);
		*p = malloc( sizeof( struct produto ) * *p_n );		
		for( i = 0 ; i < *p_n ; i++ ){
			fscanf( f, "%d", &(*p)[i].codigo );
			fscanf( f, " %[^\n]", (*p)[i].descricao );
			fscanf( f, "%f", &(*p)[i].preco );
			fscanf( f, "%d %d %d", &(*p)[i].validade.dia, &(*p)[i].validade.mes, &(*p)[i].validade.ano);
		}
		fclose ( f );
		printf("%d registros carregados!\n", *p_n );
	}
}

void salva_arquivo( char *nome_arq, struct produto *v, int n ){
	FILE *f = fopen( nome_arq, "wt" );
	fprintf( f, "%d\n", n);
	int i;
	for( i = 0 ; i < n ; i++ ){
		fprintf( f, "%d\n",	v[i].codigo );
		fprintf( f, "%s\n",	v[i].descricao );
		fprintf( f, "%.2f\n", v[i].preco );
		fprintf( f, "%d %d %d\n", v[i].validade.dia, v[i].validade.mes, v[i].validade.ano);
	}
	fclose ( f );
}

void salva_binario( char *nome_arq, struct produto *v, int n ){
	FILE *f = fopen( nome_arq, "wb" );
	fwrite( &n, sizeof(int), 1, f );
	fwrite( v, sizeof(struct produto), n, f );
	fclose ( f );
}

void carrega_binario( char *nome_arq, struct produto **p, int *p_n ){
	FILE *f = fopen( nome_arq, "rb" );
	if( f == NULL ){
		printf("Cadastro nao encontrado!\n");
	}
	else{
		fread( p_n, sizeof(int), 1, f ); // Lendo n
		*p = malloc( sizeof( struct produto ) * *p_n );
		fread( *p, sizeof(struct produto), *p_n, f ); // Lendo vetor v.
		fclose ( f );
		printf("%d registros carregados!\n", *p_n );
	}
}



