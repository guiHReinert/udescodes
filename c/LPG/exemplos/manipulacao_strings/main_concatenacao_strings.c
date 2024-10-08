#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char x[20] = "Alo";
	char v[20] = "Teste";
	char y[20] = "Mundo";
	
	printf("x = '%s' e y = '%s' e v = '%s'\n", x, y, v);
	
	strcat( x, " " ); //  Concatenação com um "espaço"...
	
	printf("x = '%s' e y = '%s' e v = '%s'\n", x, y, v);
	
	strcat( x, y ); // Concatena x e y, sendo que x recebe o conteúdo.
		
	printf("x = '%s' e y = '%s' e v = '%s'\n", x, y, v);
	
	return 0;
}
