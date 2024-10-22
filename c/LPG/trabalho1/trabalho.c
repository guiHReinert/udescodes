#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXM 8
#define MAXN 10

// Funcoes Auxiliares
int arrSum(int arr[], int len){
    int sum=0;
    for(int c=0; c<len; c++){
        sum += arr[c];
    }
    return sum;
}
int seqSearch(int arr[], int len, int x){
    for(int c=0; c<len; c++){
        if(arr[c]==x){
            return c;
        }
    }
    return -1;
}
int lenSet(int set[], int len){ // Quantos elementos diferentes de 0 tem
    int count=0;
    for(int g=0; g<len; g++){
        if(set[g]!=0){
            count++;
        }
    }
    return count;
}

void addElem(int arr[], int set[], int len){  
    int newArr[MAXN]={0}, newPos=0; 
    for(int g=0; g<len; g++){
        if(set[g]==0){
            newPos = g;
            break;
        }
    }
    for(int u=0; u<len; u++){
        if(seqSearch(set, arr[u], len)<0 && newPos+1<len){
            set[newPos] = arr[u];
            newPos++;
        }
    }
}

int main(int argc, char *argv[]){
    // int maxM, maxN;
    // printf(" Digite o numero maximo de matrizes aceitas: ");
    // scanf("%d", &maxM);
    // printf(" Digite o tamanho maximo de cada matriz: ");
    // scanf("%d", &maxN);
    // #define MAXM maxM
    // #define MAXN maxN

    int matL=-1, matriz[MAXM][MAXN]={{0}};
    char ans=0;

    printf("\n< GERENCIAMENTO DE CONJUNTOS >\n");
    while(ans!='9'){
        ans = 0;
        printf("\n >> Menu de Entrada \
        \n1 - Criar um novo conjunto vazio \
        \n2 - Inserir dados em um conjunto \
        \n3 - Remover um conjunto \
        \n4 - Fazer a uniao entre dois conjuntos \
        \n5 - Fazer a interseccao entre dois conjuntos \
        \n6 - Mostrar um cojunto \
        \n7 - Mostrar todos os conjuntos \
        \n8 - Busca por um valor \
        \n9 - Sair do programa \
        \n > ");
        scanf(" %c", &ans);

        switch(ans){
            case '1':
                if(matL+1<MAXM){
                    matL++;
                    printf("\n Novo conjunto criado. (%d conjunto(s))\n", matL+1);
                    }
                else{
                    printf("\n Quantidade maxima de %d conjunto(s) alcancada.\n", MAXM);
                }
            break;
            case '2':
                if(matL>=0){
                    char idRaw=0;
                    int idCooked=0, dentroInter=0;
                    while(!dentroInter){
                        printf(" Escolha um conjunto (entre 0 e %d): ", matL);
                        scanf(" %c", &idRaw);
                        dentroInter = idRaw>='0' && idRaw<=('0'+matL);
                        if(!dentroInter){
                            printf("  Digite um valor entre 0 e %d!\n", matL);
                        }
                    }
                    idCooked = idRaw - '0';
                    int elementos[MAXN]={0};
                    printf(" Digite os inteiros a inserir no conjunto %d (separe cada um somente com espaços):\n", idCooked);
                    int elem, cElem=0, count=0;
                    while(count<MAXN){
                        scanf("%d", &elem);
                        if(elem==0 || lenSet(matriz[idCooked], MAXN)+cElem>=MAXN){
                            break;
                        }
                        if(seqSearch(elementos, MAXN, elem)<0 && seqSearch(matriz[idCooked], MAXN, elem)<0){
                            elementos[cElem++] = elem;
                        }
                        count++;
                    }
                    addElem(elementos, matriz[idCooked], MAXN);

                    for(int c=0; c<MAXN; c++){
                        printf(" %d", elementos[c]);
                    }
                    printf("\n");
                    for(int c=0; c<MAXN; c++){
                        printf(" %d", matriz[idCooked][c]);
                    }
                }

                else{printf("\n Nenhum conjunto foi criado.\n");}
            break;
            case '7':
                printf("\n Total de %d conjuntos: \n", matL+1);
                for(int g=0; g<=matL; g++){
                    printf(" Conj. %d =", g);
                    if(arrSum(matriz[g], MAXN)==0){
                        printf(" vazio");
                    }
                    else{
                        for(int u=0; u<MAXN; u++){
                            printf(" %d", matriz[g][u]);
                        }
                    }
                    printf("\n");
                }
            break;
            default:
                printf("\n Por favor, insira um indice correto!\n");
            break;
        }
    }
    return 0;
}