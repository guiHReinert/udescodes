#include <stdio.h>
#include <stdlib.h>
#define LIN 2
#define COL 3

void gera_valores( int l, int c, int x[l][c] );
void mostra( int l, int c, int x[l][c], char id );
void soma( int l, int c, int x[l][c], int y[l][c], int z[l][c] );

int main(int argc, char *argv[]) {
	int a[LIN][COL], b[LIN][COL], c[LIN][COL];
	
	gera_valores( LIN, COL, a );
	mostra( LIN, COL, a, 'A');
	
	gera_valores( LIN, COL, b );
	mostra( LIN, COL, b, 'B' );
	
	soma( LIN, COL, a, b, c );
	
	mostra( LIN, COL, c, 'C' );
	
	return 0;
}

void gera_valores( int l, int c, int x[l][c] ){
	int i, j;
	for( i = 0 ; i < l ; i++ )
		for( j = 0 ; j < c ; j++ )	
			x[i][j] = rand() % 100 + 1;	
}

void mostra( int l, int c, int x[l][c], char id ){
	int i, j;
	printf("Matriz %c (%dx%d):\n", id, l, c);
	for( i = 0 ; i < l ; i++ ){
		for( j = 0 ; j < c ; j++ )
			printf("%d\t", x[i][j]);
		printf("\n");
	}
	printf("\n");
}

void soma( int l, int c, int x[l][c], int y[l][c], int z[l][c] ){
	int i, j;
	for( i = 0 ; i < l ; i++ )
		for( j = 0 ; j < c ; j++ )
			z[i][j] = x[i][j] + y[i][j];
}



