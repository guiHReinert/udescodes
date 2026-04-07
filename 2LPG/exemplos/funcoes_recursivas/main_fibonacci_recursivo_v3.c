#include <stdio.h>
#include <stdlib.h>

long long int fibo( int n, long long int x[] );

int main(int argc, char *argv[]) {
	long long int v[100] = { 0 };
	int n, i;
	printf("Quantos termos? ");
	scanf("%d", &n );
	
	for( i = 1; i <= n ; i++ )	
		printf("%d: %lld\n", i, fibo( i, v ));
	
	return 0;
}

long long int fibo( int n, long long int x[] ){
	if(x[n-1] != 0 ) // Valor já calculado.
		return x[n-1];
	
	if( n == 1 || n == 2 ){
		x[n-1] = 1;
		return 1;
	}
	
	x[n-1] = fibo( n-1, x ) + fibo( n-2, x );	
	return x[n-1];
}

