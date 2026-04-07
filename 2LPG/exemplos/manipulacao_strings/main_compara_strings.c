#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char x[30], y[30];
	printf("Digite alguma coisa: ");
	scanf("%[^\n]", x);
	
	printf("Digite mais alguma coisa: ");
	scanf(" %[^\n]", y);
	
	printf("x = '%s' e y = '%s'\n", x, y);
	
	int n = strcmpi( x, y );
	printf("n: %d\n", n);
	if( n == 0 )
		printf("'%s' == '%s'\n", x, y );
	else
		if( n > 0 )
			printf("'%s' > '%s'\n", x, y );
		else
			printf("'%s' < '%s'\n", x, y );
	
	return 0;
}
