#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

int main(int argc, char *argv[]) {
	FILE *f = fopen( "teste.txt", "wt" );
	
	int i;
	srand( time(0) );
	for( i = 1 ; i <= N ; i++ ){
		int x = rand() % 1000 + 1;
		fprintf( f, "%d\n", x);
	}
	
	fclose( f );

	return 0;
}
