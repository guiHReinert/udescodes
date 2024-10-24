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
int seqSearch(int arr[], int x){
    for(int c=0; c<MAXN; c++){
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

void unir(int set1[], int set2[], int newSet[]){
    int newPos=0; 
    for(int g=0; g<MAXN; g++){
        if(set1[g]!=0){
            newSet[g] = set1[g];
            newPos = g+1;
        }
    }
    for(int u=0; u<MAXN; u++){
        if(seqSearch(newSet, set2[u])<0){
            newSet[newPos++] = set2[u];
        }
    }
}

void intersec(int set1[], int set2[], int newSet[]){
    int pos=0;
    for(int g=0; g<MAXN; g++){
        if(seqSearch(set1, set1[g])>=0 && seqSearch(set2, set1[g])>=0){
            newSet[pos++] = set1[seqSearch(set1, set1[g])];
        }
    }
}

int main(int argc, char *argv[]){
    // int maxM, maxN;
    // printf(" Digite o numero maximo de matrizes aceitas: ");
    // scanf("%d", &maxM);
    // printf(" Digite o tamanho maximo de cada matriz: ");
    // scanf("%d", &maxN);arr[g] = set1[g];
    // #define MAXM maxM
    // #define MAXN maxN

    int matL=-1, matriz[MAXM][MAXN]={{0}};
    char ans=0;

    char idRaw=0;
    int idCooked=0, dentroInter=0;

    printf("\n< GERENCIAMENTO DE CONJUNTOS >\n");
    while(ans!='9'){
        ans = 0;
        printf("\n >> Menu de Entrada \
        \n1 - Criar um novo conjunto vazio \
        \n2 - Inserir dados em um conjunto \
        \n3 - Remover um conjunto \
        \n4 - Fazer a uniao entre dois conjuntos \
        \n5 - Fazer a intersecçao entre dois conjuntos \
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
                    printf(" Novo conjunto criado. (%d conjunto(s))\n", matL+1);
                    }
                else{
                    printf(" Quantidade maxima de %d conjunto(s) alcancada.\n", MAXM);
                }
            break;
            case '2':
                if(matL>=0){
                    idCooked = 0;
                    dentroInter = 0;
                    printf(" Escolha um conjunto (entre 0 e %d): ", matL);
                    while(!dentroInter){
                        scanf(" %c", &idRaw);
                        dentroInter = idRaw>='0' && idRaw<=('0'+matL);
                        if(!dentroInter){
                            printf("  Digite um valor entre 0 e %d!\n", matL);
                        }
                    }
                    idCooked = idRaw - '0';
                    printf(" Digite os inteiros a inserir no conjunto %d (separe cada um somente com espaços):\n", idCooked);
                    int count=0, elem=-1, cElem=lenSet(matriz[idCooked], MAXN);
                    while(1){
                        count++;
                        if(elem==0 || count>=MAXN || lenSet(matriz[idCooked], MAXN)>MAXN){
                            break;
                        }
                        scanf("%d", &elem);
                        if(seqSearch(matriz[idCooked], elem)<0){
                            matriz[idCooked][cElem++] = elem;
                        }
                        
                    }
                }

                else{printf(" Nenhum conjunto foi criado.\n");}
            break;
            case '3':
                if(matL>=0){
                    idRaw = 0;
                    idCooked = 0;
                    dentroInter = 0;
                    printf(" Escolha um conjunto (entre 0 e %d): ", matL);
                    while(!dentroInter){
                        scanf(" %c", &idRaw);
                        dentroInter = idRaw>='0' && idRaw<=('0'+matL);
                        if(!dentroInter){
                            printf("  Digite um valor entre 0 e %d!\n", matL);
                        }
                    }
                    idCooked = idRaw - '0';
                    for(int g=idCooked; g<matL; g++){
                        for(int u=0; u<MAXN; u++){
                            matriz[g][u] = matriz[g+1][u];
                        }
                    }
                    memset(matriz[matL], 0, sizeof(matriz[matL]));
                    matL--;
                }
                else{
                    printf(" Nenhum conjunto foi criado.\n");
                }
            break;
            case '4':
                if(matL>0){
                    char idSet1=0, idSet2=0;
                    printf(" Digite o primeiro conjunto (entre 0 e %d): ", matL);
                    while(1){
                        scanf(" %c", &idSet1);
                        if(idSet1>='0' && idSet1<=('0'+matL)){
                            break;
                        }
                        else{
                            printf("  Digite um valor valido! ");
                        }
                    } 
                    printf(" Digite o segundo conjunto (entre 0 e %d): ", matL);
                    while(1){
                        scanf(" %c", &idSet2);
                        if(idSet2>='0' && idSet2<=('0'+matL) && idSet1!=idSet2){
                            break;
                        }
                        else{
                            printf("  Digite um valor valido! ");
                        }
                    }
                    idSet1 -= '0';
                    idSet2 -= '0';
                    matL++;
                    if(lenSet(matriz[idSet1], MAXN)+lenSet(matriz[idSet2], MAXN)<=MAXN){
                        unir(matriz[idSet1], matriz[idSet2], matriz[matL]);
                    }
                    else{
                        printf("\n  Os conjuntos %d e %d ultrapassam a capacidade maxima de %d elementos.\n", idSet1, idSet2, MAXN);
                    }
                }
                else{
                    printf("  Nao ha conjuntos o suficiente para realizar a uniao.\n");
                }

            break;
            case '5':
                if(matL>0){
                    char idSet1=0, idSet2=0;
                    printf(" Digite o primeiro conjunto (entre 0 e %d): ", matL);
                    while(1){
                        scanf(" %c", &idSet1);
                        if(idSet1>='0' && idSet1<=('0'+matL)){
                            break;
                        }
                        else{
                            printf("  Digite um valor valido! ");
                        }
                    } 
                    printf(" Digite o segundo conjunto (entre 0 e %d): ", matL);
                    while(1){
                        scanf(" %c", &idSet2);
                        if(idSet2>='0' && idSet2<=('0'+matL) && idSet1!=idSet2){
                            break;
                        }
                        else{
                            printf("  Digite um valor valido! ");
                        }
                    }
                    idSet1 -= '0';
                    idSet2 -= '0';
                    matL++;
                    intersec(matriz[idSet1], matriz[idSet2], matriz[matL]);                    
                }
                else{
                    printf("  Nao ha conjuntos o suficiente para realizar a intersecçao.\n");
                }
            break;
            case '6':
                idRaw = 0;
                idCooked = 0;
                dentroInter = 0;
                printf(" Escolha um conjunto (entre 0 e %d): ", matL);
                while(!dentroInter){
                    scanf(" %c", &idRaw);
                    dentroInter = idRaw>='0' && idRaw<=('0'+matL);
                    if(!dentroInter){
                        printf("  Digite um valor entre 0 e %d! ", matL);
                    }
                }
                idCooked = idRaw - '0';
                printf(" Conjunto %d:", idCooked);
                for(int c=0; c<MAXN; c++){
                    if(matriz[idCooked][c]){
                        printf(" %d", matriz[idCooked][c]);
                    }
                }
            break;
            case '7':
                printf(" Total de %d conjuntos: \n", matL+1);
                for(int g=0; g<=matL; g++){
                    printf(" Conj. %d =", g);
                    if(arrSum(matriz[g], MAXN)==0){
                        printf(" vazio");
                    }
                    else{
                        for(int u=0; u<MAXN; u++){
                            if(matriz[g][u]!=0){
                                printf(" %d", matriz[g][u]);
                            }
                        }
                    }
                    printf("\n");
                }
            break;
            case '8':
                int num=0, id=0, found=0, sets[MAXN]={0};
                printf(" Escreva o numero a ser buscado: ");
                scanf("%d", &num);
                for(int g=0; g<MAXM; g++){
                    if(seqSearch(matriz[g], num)>-1){
                        sets[id++] = g;
                        found = 1;
                    }
                }
                if(found){
                    printf(" Conjuntos com o numero %d:", num);
                    for(int c=0; c<=lenSet(sets, MAXN);c++){
                        printf(" %d", sets[c]);
                    }
                    printf("\n");
                }
                else{
                    printf("  Nao ha conjuntos com o numero %d", num);
                }
                
            break;
            case '9': break;
            default:
                printf(" Por favor, insira um indice correto!\n");
            break;
        }
    }
    return 0;
}