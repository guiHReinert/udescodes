#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double sen( double x, int n );
double sen_cos( double x, int n, int inicio, double termo );
double s_c_rec( double x, int n, int i, double termo );
double seno( double x );
double cosseno( double x );

int main(int argc, char *argv[]) {
	//printf("Seno: %.15lf\n", sen( M_PI_2, 10 ) );

	double x = M_PI_4;
	
	printf("Seno: %.15lf\n", seno( x ) );
	printf("Cosseno: %.15lf\n", cosseno( x ) );
	/*
	printf("Seno: %.15lf\n", sen_cos( x, 12, 1, x ) );
	printf("Cosseno: %.15lf\n", sen_cos( x, 12, 0, 1 ) );
	*/
	return 0;
}

double sen( double x, int n ){
	double s = 0, termo = x;
	int i;
	for( i = 1 ; i < 2*n ; i+= 2 ){
		s += termo;
		termo *= x/(i+1)*x/(i+2)*(-1);
	}
	return s;
}

/*
* Versão iterativa *
  x é em radianos!
  Para seno   : inicio = 1 e termo = x;
  Para cosseno: inicio = 0 e termo = 1;
*/
double sen_cos( double x, int n, int inicio, double termo ){
	double s = 0;
	int i;
	for( i = inicio ; i < 2*n ; i+= 2 ){
		s += termo;
		termo *= x/(i+1)*x/(i+2)*(-1);
	}
	return s;
}

/*
* Versão recursiva *
  x é em radianos!
  Para seno   : i = 1 e termo = x;
  Para cosseno: i = 0 e termo = 1;
*/
double s_c_rec( double x, int n, int i, double termo ){
	if( i < 2*n )
		return termo + s_c_rec( x, n, i+2, termo*x/(i+1)*x/(i+2)*(-1) );

	return 0;
}

// x é em radianos!
double seno( double x ){
	return s_c_rec( x, 12, 1, x );
	//return sen_cos( x, 12, 1, x );
}

// x é em radianos!
double cosseno( double x ){
	return s_c_rec( x, 12, 0, 1 );
	//return sen_cos( x, 12, 0, 1 );
}




