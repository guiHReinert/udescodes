#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Questão 1
int fatIter(int num){
    if(num%2==0 || num<0){return 0;}
    else{
        int fat=1;
        for(int g=1 ; g<=num; g++){
            if(g%2!=0){
                fat *= g;
            }
        }
        return fat;
    }
    
}
int fatRecur(int num){
    if(num%2==0){
        return 0;
    }
    else if(num>0){
        return num*fatRecur(num-2);
    }
    else{return 1;}

}
// Questão 2
void vetSep(int len, int v[], int vi[], int vp[]){
    for(int g=0; g<len; g++){
        
    }
    }
    // printf("\n");
}


int main(){
    // int num;
    // scanf("%d", &num);
    // printf("%d\n", fatRecur(num));
    #define MAX 20
    int vetImp[MAX], vetPar[MAX], vet[MAX]=
    {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}; 
    int lenVet = sizeof(vet)/sizeof(vet[0]);

    vetSep(lenVet, vet, vetImp, vetPar);
    for(int c=0; c<lenVet; c++){
        printf("%d ", vet[c]);
    }
    printf("\n");
    vetSep(lenVet, vet, vetImp, vetPar);
    for(int c=0; c<lenVet; c++){
        printf("%d ", vetImp[c]);
    }
    printf("\n");
    for(int c=0; c<lenVet; c++){
        printf("%d ", vetPar[c]);
    }
    printf("\n");
    return 0;
}