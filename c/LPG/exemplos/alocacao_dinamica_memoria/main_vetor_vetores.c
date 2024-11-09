#include <stdio.h>
#include <stdlib.h>

#define LIN 3

int main(int argc, char *argv[]) {
	int *vp[LIN];
	int i, j, n;
	
	
	int col;
	printf("Quantas colunas? ");
	scanf("%d", &col);
	
	for( i = 0 ; i < LIN ; i++ )
		vp[i] = malloc( sizeof(int) * col );
		
	// Entrada de dados.
	for( i = 0 ; i < LIN ; i++ )
		for( j = 0 ; j < col ; j++ ){
			printf("Digite o valor para %dx%d: ", i, j);
			scanf("%d", &vp[i][j]);
		}
	// Saída no console.
	for( i = 0 ; i < LIN ; i++ ){
		for( j = 0 ; j < col ; j++ )
			printf("%d\t", vp[i][j]);
		printf("\n");
	}
	// Libera a memória.
	for( i = 0 ; i < LIN ; i++ )
		free( vp[i] );
	
	return 0;
}
