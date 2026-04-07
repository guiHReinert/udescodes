#include <stdio.h>
#include <stdlib.h>

void mostra_valores( int x );

int main(int argc, char *argv[]) {

	int n = 5;
	
	mostra_valores( n );
	
	return 0;
}

void mostra_valores( int x ){
	printf("%d\n", x);
	if( x > 0 ){
		printf("[x = %d (antes da recursao)...]\n", x);
		mostra_valores( x-1 );
		printf("[x = %d (depois da recursao)...]\n", x);
	}
}


