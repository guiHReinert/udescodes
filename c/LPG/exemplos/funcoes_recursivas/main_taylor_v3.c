#include <stdio.h>
#include <stdlib.h>

double e_na_x( double x, int n );
double e_rec( double x, int n, int i, double termo );

int main(int argc, char *argv[]) {
	double x;
	int n;
	printf("Digite o valor de X: ");
	scanf("%lf", &x);
	printf("Digite o valor de N: ");
	scanf("%d", &n);

	printf("E elevado a %.3lf : %.15lf\n", x, e_na_x( x, n ) );
	printf("E elevado a %.3lf : %.15lf\n", x, e_rec( x, n, 0, 1 ) );
	
	return 0;-
}

double e_na_x( double x, int n ){
	double e_x = 0;
	double termo = 1;
	int i;
	for( i = 0 ; i <= n ; i++ ){
		e_x += termo; // e_x = e_x + termo;
		termo *= x / (i+1);
	}
	return e_x;
}

double e_rec( double x, int n, int i, double termo ){
	if( i <= n )	
		return termo + e_rec( x, n, i+1, termo*x/(i+1) );
	
	return 0;
}

