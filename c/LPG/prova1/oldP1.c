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
    int posVI=0, posVP=0;
    for(int g=0; g<len; g++){
        if(v[g]%2!=0){
            vi[posVI] = v[g]; 
            posVI++;
        }
        else{
            vp[posVP] = v[g]; 
            posVP++;
        }
    }
    vi[posVI] = -1;
    vp[posVP] = -1;
}
// Questão 3
void maiorLinha(int lin, int col, int mat[lin][col], int arr[col]){
    int maior, posLine;
    for(int g=0; g<lin; g++){
        for(int u=0; u<col; u++){
            if(mat[g][u]>=maior){
                maior = mat[g][u];
                posLine = g;
            }
        }
    }
    for(int i=0; i<col; i++){
        arr[i] = mat[posLine][i];
    }

}
// Questão 4
void substring(char* oldStr, char* newStr, int beg, int end){
    int len = sizeof(oldStr)/sizeof(oldStr)[0], posNew=0;
    if(beg>len){
        printf("primeiro caso\n");
        newStr = "";
    }
    else{
        for(int g=0; g<=len; g++){
            if(beg<=end){
                if(beg<=g && g<=end){
                    printf("segundo caso\n");
                    newStr[posNew] = oldStr[g];
                    posNew++;
                }
            }
            else{
                printf("terceiro caso\n");
                for(int u=0; u<=len; u++){
                    newStr[u] = oldStr[u];
                }
            }
        }
    }
}

int main(){
    /* QUESTÃO 1
    int num;
    scanf("%d", &num);
    printf("%d\n", fatRecur(num));
    */
    /* QUETÃO 2
    #define MAX 5
    int vetImp[MAX+1]={0}, vetPar[MAX+1]={0}, vet[MAX]=
    {2,4,6,8,10}; 
    int lenVet = sizeof(vet)/sizeof(vet[0]);

    vetSep(lenVet, vet, vetImp, vetPar);
    for(int c=0; c<lenVet; c++){
        printf("%d ", vet[c]);
    }
    printf("\n");
    for(int c=0; c<lenVet+1; c++){
        printf("%d ", vetImp[c]);
    }
    printf("\n");
    for(int c=0; c<lenVet+1; c++){
        printf("%d ", vetPar[c]);
    }
    printf("\n");
    return 0;
    */
    /* QUESTÃO 3
    #define LIN 3
    #define COL 5
    int arr[COL], matriz[LIN][COL] ={
    {3, 4, -1, 0, 180},
    {12, 6, 99, -5, 2070},
    {1, 14, -8, 2, 6666}};
    maiorLinha(LIN, COL, matriz, arr);
    for(int c=0; c<COL; c++){
        printf("%d ", arr[c]);
    }
    printf("\n");
    */
   /* QUESTÃO 4 */
   int ini, fim;
   char orig[] = "GuilhermeHoerningReinert", nova[sizeof(orig)/sizeof(orig)[0]]; 
   scanf("%d", &ini);
   scanf("%d", &fim);
   substring(orig, nova, ini, fim);
   printf("%s\n", nova);


}