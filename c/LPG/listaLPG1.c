#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Questão 1
void quadrante(){
    float x, y;
    char quad[9];

    printf("Digite dois valores para x e y: \n");
    scanf("%f %f", &x, &y);
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
        int num = 0;
        scanf("%f", &num);
        lados[i] = num;
    };
    
    if(a==b==c){
        printf("TRIANGULO EQUILATERO \n");
    }
    else{
        if(((a==b)||(b==c)||(a==c))){
            printf("TRIANGULO ISOSCELES");
        }
        else{}
    }
}

void main(){
    unsigned int ans;

    printf("Escolha uma questão das listas: \
    \n >> Lista 1 - Selecao e Repeticao: \
    \n1) Coordenadas de um ponto \
    \n2) Tipos de Triangulos \
    \n3) Tempo de Jogo \
    \n4) Pares, Impares, Positivos e Negativos \
    \n5) Medias Ponderadas \
    \n6) Soma de Impares Consecutivos I \
    \n7) Soma de Impares Consecutivos II \
    \n\n >> Lista 2 - Geracao de Series: \
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
        default: printf("Digite um índice correto!\n");
    }

}