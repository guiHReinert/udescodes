struct data{
	int dia, mes, ano;
};

void mostra_data( struct data d );
void le_data( struct data *p );

struct produto{
	int codigo;
	char descricao[20];
	float preco;
	struct data validade;
};

void mostra_produto( struct produto p );
void le_produto( struct produto *p );
void carrega_arquivo( char *nome_arq, struct produto **p, int *p_n );
void salva_arquivo( char *nome_arq, struct produto *v, int n );
void salva_binario( char *nome_arq, struct produto *v, int n );

