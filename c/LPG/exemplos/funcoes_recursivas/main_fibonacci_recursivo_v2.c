#include <stdio.h>
#include <stdlib.h>

long long int v[100];

long long int fibo( int n );

int main(int argc, char *argv[]) {
	int n, i;
	printf("Quantos termos? ");
	scanf("%d", &n );
	
	for( i = 1; i <= n ; i++ )	
		printf("%d: %lld\n", i, fibo( i ));
	
	return 0;
}

long long int fibo( int n ){
	if( v[n-1] != 0 ) // Valor já calculado.
		return v[n-1];
	
	if( n == 1 || n == 2 ){
		v[n-1] = 1;
		return 1;
	}
	
	v[n-1] = fibo( n-1 ) + fibo( n-2 );	
	return v[n-1];
}

