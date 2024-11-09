#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int **listas = NULL;
	int *qtd = NULL;
	int tam = 0, i, j, op, x, id;
	
	do{
		printf("1-Criar lista\n2-Inserir valores\n3-Mostrar listas\n4-Sair\n");
		scanf("%d", &op);
		switch( op ){
			case 1:
				tam++;
				listas = realloc( listas, sizeof(int*)*tam );
				listas[tam-1] = NULL;
				qtd = realloc( qtd, sizeof(int)*tam );
				qtd[tam-1] = 0;
				printf("Lista cirada com sucesso!\n");
				break;
				
			case 2:
				printf("Qual o numero da lista? ");
				scanf("%d", &id);
				
				printf("Digite o %do valor: ", qtd[id]+1);
				scanf("%d", &x);
				
				while( x != 0 ){
					qtd[id]++;
					listas[id] = realloc( listas[id], sizeof(int)*qtd[id] );
					listas[id][qtd[id]-1] = x;
					printf("Digite o %do valor: ", qtd[id]+1);
					scanf("%d", &x);
				}
				
				break;
				
			case 3:
				// Saída no console.
				for( i = 0 ; i < tam ; i++ ){
					printf("Lista %d (%d valores): ", i, qtd[i]);
					if( qtd[i] == 0 )
						printf("vazia");
					else
						for( j = 0 ; j < qtd[i] ; j++ )
							printf("%d ", listas[i][j]);
					printf("\n");
				}	
				break;
		}
	}while( op != 4 );
	

	// Libera a memória.
	for( i = 0 ; i < tam ; i++ )
		free( listas[i] );
	free( listas );
	free( qtd );	
	return 0;
}

