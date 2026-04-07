#include <stdio.h>
#include <stdlib.h>

int fat( int x );

int main(int argc, char *argv[]) {
	printf("%d\n", fat( 10 ) );
	
	return 0;
}

int fat( int x ){
	if( x == 0 ){
		printf("[Caso base: retorna 1.]\n");
		return 1;
	}
	printf("[Calculando %d!...]\n", x - 1 );
	int y = fat( x - 1 );
	printf("[Retorno da recursao: %d! eh %d]\n", x - 1, y );
	return x * y;
}