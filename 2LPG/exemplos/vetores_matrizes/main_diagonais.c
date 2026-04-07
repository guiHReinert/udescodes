#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

int main(int argc, char *argv[]) {
	
	int m[N][N];
	int i, j;
	srand( time(0) );
	for( i = 0 ; i < N ; i++ )
		for( j = 0 ; j < N ; j++ )
			m[i][j] = rand() % 1000 + 1;
			
	for( i = 0 ; i < N ; i++ ){
		for( j = 0 ; j < N ; j++ )
			printf("%4d ", m[i][j]);
		printf("\n");
	}
	
	printf("\nDiagonal Principal: ");
	/*
	for( i = 0 ; i < N ; i++ )
		for( j = 0 ; j < N ; j++ )
			if( i == j )
				printf("%d ", m[i][j]);
	*/
	for( i = 0 ; i < N ; i++ )
		printf("%d ", m[i][i]);
	printf("\n");
	
	printf("\nDiagonal Secundaria: ");
	/*
	for( i = 0 ; i < N ; i++ )
		for( j = 0 ; j < N ; j++ )
			if( i + j == N-1 )
				printf("%d ", m[i][j]);
	*/
	for( i = 0 ; i < N ; i++ )
		printf("%d ", m[i][N-1-i]);
	printf("\n");

	return 0;
}

