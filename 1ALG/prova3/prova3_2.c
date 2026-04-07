#include <stdio.h>

int entry, quant, newNum;
int primo(int num){
	for(int c=(num-1); c>1; c--){
		if(num % c == 0){
		  return 1;
		}
	}
	return 0;
}

int main(){
	printf("(inicio) ");
	scanf("%d", &entry);
	printf("(quantidade de primos) ");
	scanf("%d", &quant);
	
	newNum = entry;
	while(quant){
		if(primo(newNum) == 0){
			printf("%d\n", newNum);
			quant--;
		}
	  newNum++;
	}
	
	return 0;
}
