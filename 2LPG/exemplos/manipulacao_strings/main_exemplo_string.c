#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copia( char dest[], char orig[] );

int main(int argc, char *argv[]) {
	
	char nome[20];
	printf("Digite algo: ");
	scanf("%[^\n]", nome );
	
	printf("Voce digitou: '%s'\n", nome );
	
	char aux[20] = "123456789012345";
	
	copia( aux, nome );
	
	printf("Valor copiado: '%s'\n", aux );
	
	return 0;
}

void copia( char dest[], char orig[] ){
	int i;
	for( i = 0 ; orig[i] != '\0' ; i++ )
		dest[i] = orig[i];
		
	dest[i] = orig[i]; // Copiar '\0' ao final!
}

