#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calcula_raizes( float a, float b, float c, float *p1, float *p2 );

int main(int argc, char *argv[]) {
	float a, b, c, x1, x2;
	printf("Digite o coeficiente A: ");
	scanf("%f", &a);
	printf("Digite o coeficiente B: ");
	scanf("%f", &b);
	printf("Digite o coeficiente C: ");
	scanf("%f", &c);
	
	switch( calcula_raizes( a, b, c, &x1, &x2 ) ){
		case 0:
			printf("nao eh equacao de 2o grau!\n");
			break;		
		case 1:
			printf("Nao ha raizes reais!\n");
			break;			
		case 2:
			printf("As raizes sao %.3f e %.3f\n", x1, x2 );
			break;
	}	
	return 0;
}

/*
Retorna 0 : nao eh equaaco de 2o grau (a == 0);
Retorna 1 : nao ha raizes reais (delta < 0);
Retorna 2 : ha raizes reais (delta >= 0;
*/
int calcula_raizes( float a, float b, float c, float *p1, float *p2 ){
	if( a == 0 )
		return 0;
	
	float delta = b*b - 4*a*c;
	if( delta < 0 )
		return 1;
	
	*p1 = ( -b + sqrt( delta ) ) / ( 2 * a ) ;
	*p2 = ( -b - sqrt( delta ) ) / ( 2 * a ) ;
	return 2;
}

