#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Funções auxiliares
float* arrSort(float* array, int arr_size){ // The array and size parameters must be diffent
    for(int i=0; i<arr_size; i++){
        int min = i;
        for(int s=i+1; s<arr_size; s++){
            if(array[min]>array[s]){
                min = s;
                }
            }
        float temp = array[i];
        array[i] = array[min];
        array[min] = temp;
        }
    return array;
}

// Questão 1
void quadrante(){
    float coord[2];
    char quad[9];
    printf("Digite dois valores para x e y: \n");
    for(int c=0; c<2; c++){
        scanf("%f", &coord[c]);
    }
    float x = coord[0], y = coord[1];
    if(x==0){
        if(y==0){
            strcpy(quad, "Origem");
        }
        else{
            strcpy(quad, "Eixo Y");
        };
    }
    else if(y==0){
        strcpy(quad, "Eixo X");
    }
    else {
        if (x>0){
            if(y>0){
                strcpy(quad, "Q1");
            }
            else{
                strcpy(quad, "Q4");
            }
        }
        else{
            if(y>0){
                strcpy(quad, "Q2");
            }
            else{
                strcpy(quad, "Q3");
            } 
        }
    }
    printf("%s\n", quad);
}
//Questão 2
void triangulo(){
    float lados[3];
    for(int i=0; i<3; i++){
        float num = 0;
        scanf("%f", &num);
        lados[i] = num;
    };
    arrSort(lados, sizeof(lados)/sizeof(lados[0]));
    int a=lados[2], b=lados[1], c=lados[0];
    if(a>=b+c){
        printf("NAO FORMA TRIANGULO\n");
    }
    else{
        if(a*a==b*b+c*c){
            printf("TRIANGULO RETANGULO\n");
        }
        else if(a*a>b*b+c*c){
            printf("TRIANGULO OBTUSANGULO\n");
        }
        else if(a*a<b*b+c*c){
            printf("TRIANGULO ACUTANGULO\n");
        }
        if((a==b)&&(b==c)){
            printf("TRIANGULO EQUILATERO\n");
        }
        else if(((a==b)||(b==c)||(a==c))){
                printf("TRIANGULO ISOSCELES\n");
            }
    }
}
// Questão 3
void tempoJogo(){
    int tempos[2], durac;
    for(int i=0; i<2; i++){
            scanf("%d", &tempos[i]);
    }
    if(tempos[0]<24 && tempos[1]<24){
        durac = tempos[1]-tempos[0];
        if(tempos[0]==0 && tempos[1]==0){
            durac = 24;
        }
        else if(tempos[0]>tempos[1]){
            durac += 24;
        }
        printf("O JOGO DUROU %d HORAS(S)\n", durac);
    }
    else{
        printf("Digite os horarios certo!\n");
    }
}
// Questão 4
void PIPN(){
    int qntNum=0, cPar=0, cImp=0, cPos=0, cNeg=0;
    scanf("%d", &qntNum);
    int nums[qntNum];
    for(int c=0; c<qntNum; c++){
        scanf("%d", &nums[c]);
        if(nums[c]%2==0){
            cPar += 1;
        }
        else{
            cImp += 1;
        }
        if(nums[c]>0){
            cPos += 1;
        }
        else if(nums[c]<0){
            cNeg += 1;
        }
    }
    printf("%d valor(es) par(es) \
    \n%d valor(es) impar(es) \
    \n%d valor(es) positivo(s) \
    \n%d valor(es) negativo(s)\n", cPar, cImp, cPos, cNeg);
}
// Questão 5
void mediaPond(){
    int qntMed;
    scanf("%d", &qntMed);
    float notas[qntMed][3], medias[qntMed];
    for(int g=0; g<qntMed; g++){
        for(int u=0; u<3; u++){
            scanf("%f", &notas[g][u]);
        }
        medias[g] = (2*notas[g][0] + 3*notas[g][1] + 5*notas[g][2])/10;
    }
    for(int i=0; i<qntMed; i++){
        printf("%.1f\n", medias[i]);
    }
}
// Questão 6
void somaImparesCon_1(){
    float range0[2];
    int range[2], soma=0;
    for(int g=0; g<2; g++){
        scanf("%f", &range0[g]);
    }
    range[0] = (int)arrSort(range0, sizeof(range0)/sizeof(range0[0]))[0];
    range[1] = (int)arrSort(range0, sizeof(range0)/sizeof(range0[0]))[1];
    for(int u=range[0]+1; u<range[1]; u++){
        if(u%2!=0){
            soma += u;
        }
    }
    printf("%d\n", soma);
}
// Questão 7
void somaImparesCon_2(){
    int qntTestes=0;
    scanf("%d", &qntTestes);
    int somas[qntTestes];
    for(int g=0; g<qntTestes; g++){
        float range0[2];
        int range[2], soma=0;
        for(int u=0; u<2; u++){
            scanf("%f", &range0[u]);
        }
        range[0] = (int)arrSort(range0, sizeof(range0)/sizeof(range0[0]))[0];
        range[1] = (int)arrSort(range0, sizeof(range0)/sizeof(range0[0]))[1];
        for(int i=range[0]+1; i<range[1]; i++){
            if(i%2!=0){
                soma += i;
            }
        }
        somas[g] = soma;
    }
    printf("\n");
    for(int c=0; c<qntTestes; c++){
        printf("%d\n", somas[c]);
    }
}
// Questão 8
void serieHarmonica(){
    unsigned int terms=0;
    float soma=0;
    scanf("%d", &terms);
    for(int g=1; g<=terms; g++){
        soma += 1.0/g;
    }
    printf("\n%f\n", soma);
}
// Questão 9
void logNeperianoB2(){
    unsigned int terms=0;
    float soma=0;
    scanf("%d", &terms);
    for(int g=1; g<=terms; g++){
        soma += pow(-1, g+1)/(float)g;
    }
    printf("\n%lf\n", soma);
}
//Questão 10
float regressao(int k, float div, int coef){ 
    if(k>0){
        return coef*(4/div) + regressao(k-1, div+2, -coef);
    }
    else{
        return 0;
    }
}
void serieGregLeib(){
    unsigned int terms=0;
    scanf("%d", &terms);
    printf("\n%f\n", regressao(terms, 1, 1));
}
// Questão 11
void serieNilak(){
    
}

void main(){
    unsigned int ans;

    printf("Escolha uma questão das listas: \
    \n >> Lista 1.1 - Selecao e Repeticao: \
    \n1) Coordenadas de um ponto \
    \n2) Tipos de Triangulos \
    \n3) Tempo de Jogo \
    \n4) Pares, Impares, Positivos e Negativos \
    \n5) Medias Ponderadas \
    \n6) Soma de Impares Consecutivos I \
    \n7) Soma de Impares Consecutivos II \
    \n\n >> Lista 1.2 - Geracao de Series: \
    \n(1) 8) Serie Harmonica \
    \n(2) 9) Logaritmo Natural de 2 \
    \n(3a) 10) Serie de Gregory-Leibniz \
    \n(3b) 11) Serie de Nilakantha \
    \n(4) 12) Valor do Numero de Euler \
    \n(5) 13) Serie de Taylor \
    \n(6) 14) Valor Aprox. de sen(x) \
    \n(7) 15) Valor Aprox. de cos(x) \
    \n(8) 16) Somatoria dos termos: digite 16, e entao um numero entre 8 e 15 para calcular a somatoria do termos da funcao respectiva. \
    \n\n > ");
    scanf("%d", &ans);
    switch(ans){
        case 1: quadrante(); break;
        case 2: triangulo(); break;
        case 3: tempoJogo(); break;
        case 4: PIPN(); break;
        case 5: mediaPond(); break;
        case 6: somaImparesCon_1(); break;
        case 7: somaImparesCon_2(); break;
        case 8: serieHarmonica(); break;
        case 9: logNeperianoB2(); break;
        case 10: serieGregLeib(); break;
        default: printf("Digite um índice correto! (entre 1 e 16)\n");
    }
}