#include <stdio.h>
#include <stdlib.h>

float pot( float b, int e );

int main(int argc, char *argv[]) {
	
	printf("%f\n", pot( 10, 5 ));
	
	return 0;
}

float pot( float b, int e ){
	if( e == 0 )
		return 1;
	
	if( e < 0 )
		return pot( 1/b, -e );
	
	return b * pot( b, e-1 );
}


