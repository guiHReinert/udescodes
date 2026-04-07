#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	double x;
	int n, i, j;
	printf("Digite o valor de X: ");
	scanf("%lf", &x);
	printf("Digite o valor de N: ");
	scanf("%d", &n);
	
	double e_x = 0;
	
	for( i = 0 ; i <= n ; i++ ){
		double termo = 1;
		for( j = 1 ; j <= i ; j++ ){
			termo *= x/j; // termo = termo * x/j;
		}
		e_x += termo; // e_x = e_x + termo;
	}
	printf("E elevado a %.3lf : %.15lf\n", x, e_x);	
	
	return 0;
}

