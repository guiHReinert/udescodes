#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * concatena( char *str1, char *str2 );

int main(int argc, char *argv[]) {
	char a[] = "Alguma";
	char b[] = "Coisa";
	
	char *c;
	c = concatena( a, b );
	
	printf("'%s'\n", c);
	
	free( c );
		
	return 0;
}

char * concatena( char *str1, char *str2 ){
	int n1 = strlen( str1 );
	int n2 = strlen( str2 );
	
	char *p = malloc( n1 + n2 + 1 ); // char p[n1 + n2 + 1];
	
	strcpy( p     , str1 );
	strcpy( p + n1, str2 );
	
	return p;	
}
