#include <stdio.h>
#include <stdlib.h>

int raiz( int x );
int eh_primo( int x );

int main(int argc, char *argv[]) {
	int k, n;
	printf("Digite o valor de K: ");
	scanf("%d", &k );
	printf("Digite o valor de N: ");
	scanf("%d", &n );
	int cont = 0;
	while( cont < n ){
		if( eh_primo( k ) ){
			cont++;
			printf("%d: %d\n", cont, k);
		}
		k++;
	}
	return 0;
}


int eh_primo( int x ){
	int i;
	float r = raiz( x );
	for( i = 2 ; i <= r ; i++ ){
		if( x % i == 0 )
			return 0;
	}
	return 1;
}


int raiz( int x ){
	int cont = 0, i = 1;
	while( x >= i ){
		cont++;
		x -= i;
		i += 2;
	}
	return cont;
}

