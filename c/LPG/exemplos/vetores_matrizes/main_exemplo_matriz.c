#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIN 2
#define COL 3

void mostra_vetor( int *x, int n );

int main(int argc, char *argv[]) {
	/*
	int v[COL] = { 2, 4, 6, 8, 10, 12 };
	mostra_vetor( v, COL );
	*/
		
	int m[LIN][COL];
	int i, j;
	srand( time(0) );
	for( i = 0 ; i < LIN ; i++ )
		for( j = 0 ; j < COL ; j++ )
			m[i][j] = rand() % 1000 + 1;
			
	for( i = 0 ; i < LIN ; i++ ){
		for( j = 0 ; j < COL ; j++ )
			printf("%4d ", m[i][j]);
		printf("\n");
	}
	
	for( i = 0 ; i < LIN ; i++ ){
		printf(" Dados da linha %d:\n", i );
		mostra_vetor( m[i], COL );
	}
	
	printf("Matriz vista como um vetor:\n");
	mostra_vetor( m, LIN*COL);
	
	return 0;
}

void mostra_vetor( int *x, int n ){
	int i;
	for( i = 0 ; i < n ; i++ )
		printf("[%d] %d\n", i, x[i]);
	printf("\n");
}

