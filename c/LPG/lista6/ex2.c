#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
2) Escreva uma função que recebe como parâmetros uma string s e um inteiro n, e retorna
nova string nova contendo s repetida n vezes. Por exemplo, s = “Abc” e n = 4 tem como
resultado a string “AbcAbcAbcAbc”. Faça o programa principal chamando a função.
*/
char *repetidor( char *s, int n ){
    int len=0;
    while(1){
        if(s[len] == '\0'){
            break;
        }
        else{
            len++;
        }
    }
    char *sAloc = malloc(sizeof(s[0]) * len * n);
    for(int g=0; g<n; g++){
        for(int u=0; u<len; u++){
            sAloc[g*len + u] = s[u];
        }
    }
    return sAloc;
}

void main(){
    char str[99];
    printf(" Digite uma palavra ou um texto:\n > ");
    scanf("%[^\n]", str);
    int rep; 
    printf(" Digite quantas vezes o texto acima será repetido: ");
    scanf("%d", &rep);

    char *newStr;
    newStr = repetidor(str, rep);
    printf("%s\n", newStr);

    free(newStr);

}
