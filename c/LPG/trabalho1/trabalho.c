#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXM 8
#define MAXN 10

// Funcoes Auxiliares
int arrSum(int arr[], int len){
    int sum=0;
    for(int c; c<len; c++){
        sum += arr[c];
    }
    return sum;
}

int addElem(char str[], int *set){  
    int setLen=sizeof(set)/sizeof(set)[0];
    char numRaw[MAXN]; 
    int arrNums[MAXN]={0}, cRaw=0, cNums=0;
    for(int g=0; g<MAXN*4 && cNums<=MAXN-setLen; g++){ // Quantidade de elementos a adicionar menor ou igual a quantidade de espaços vazios no conjunto
        if(str[g]>='0' && str[g]<='9' || str[g]=='-'){
            printf("\ng=%d, str[g]=%c, ascii=%d", g, str[g], str[g]-'0');
            numRaw[cRaw++] = str[g];
        }
        else{
            if(cRaw>0){
                arrNums[cNums++] = atoi(numRaw);
                cRaw = 0;
            }
        }
        if(cNums>MAXN-setLen){
            printf("\n Quantidade maxima de elementos excedida!");
            return 0;
        }
    }
    printf("\n");
    for(int u=0; u<MAXN; u++){
        printf(" u=%d, %d\n", u, arrNums[u]);
    }
    printf("\n");
    return 1;

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

    while(ans!='9'){
        ans = 0;
        printf("\n< GERENCIAMENTO DE CONJUNTOS > \
        \n\n >> Menu de Entrada \
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
                    char elementos[MAXN*4]; /* Considerando um caso pouco extremo onde se insere um conjunto completo de numeros negativos
                                            e cada um separado por uma virgula e um espaço entre elementos.
                                            */
                    printf(" Digite os elementos a inserir no conjunto %d (separe com virgulas cada um):\n", idCooked);
                    scanf(" %[^\n]", elementos);
                    // printf("(%s) e len = %ld", elementos, sizeof(elementos)/sizeof(elementos)[0]);
                    if(elementos[0]>='0' && elementos[0]<='9'){
                        addElem(elementos, matriz[idCooked]);
                    }
                    else{
                        printf(" Digite valores validos!\n");
                    }
                }

                else{printf("\n Nenhum conjunto foi criado.\n");}
            break;
            case '7':
                printf("\n Total de %d conjuntos: \n", matL+1);
                for(int g=0; g<=matL; g++){
                    printf(" Conj. %d =", g);
                    if(arrSum(matriz[g], MAXN)>0){ // caso arrSum=<0, logo o conjunto nao possui elementos
                        for(int u=0; u<MAXN; u++){
                            printf(" %d", matriz[g][u]);
                        }
                    }
                    else{
                        printf(" vazio");
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