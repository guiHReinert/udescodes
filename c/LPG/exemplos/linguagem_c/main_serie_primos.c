#include <stdio.h>
#include <math.h>

int main() {
	int x, a, b;
	printf("Digite A: ");
	scanf("%d", &a);
	printf("Digite B: ");
	scanf("%d", &b);
	int cont_p = 0;
	for( x = a ; x <= b ; x++ ){
		int i, eh_primo = 1;
		float r = sqrt( x );
		for( i = 2 ; i <= r && eh_primo ; i++ ){
			if( x % i == 0 )
				eh_primo = 0;
		}
		if( eh_primo ){
			cont_p++;
			printf("%d: %d\n", cont_p, x );
		}
	}
	
	return 0;
}

