#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

//<=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=>
//              -=FUNCIONADOR INTEGRADOR MATEMATICO-COMPUTACIONAL=-
//<=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=>

// Aluno: Guilherme Hoerning Reinert
// Data: 08/12/2022
// Professor: Edson Hiroshi Watanabe
// Disciplina: Lógica e Progamação I
// Curso: Técnico Integrado em Eletroeletrõnica
// Módulo VI

float h, x, sum, res, x0, xn;
int i, trap, isIt, ansFunci, ansDnvi = 1;
char ansFuncs[2], ansDnvs[2];

// funcao de inversao de sinal
int inv(int numInv){
    if(numInv == 0){numInv = 1;}
    else{numInv = 0;}
    return numInv;
}

// funcoes matematicas de teste
float funcTeste1(float xFunc){
    float yFunc = 5*xFunc - 7;
    return yFunc;
    }

float funcTeste2(float xFunc){
    float yFunc = 2 * pow(xFunc, 2) - 3*xFunc + 1;
    return yFunc;
}

float funcTeste3(float xFunc){
    float yFunc = 4 * pow(xFunc, 3) - pow(xFunc, 2) + 3*xFunc + 8;
    return yFunc;
}

float funcTeste4(float xFunc){
    float yFunc = pow(xFunc, 4) -2*pow(xFunc, 3) + pow(xFunc, 2) + 9*xFunc;
    return yFunc;
}

float funcTeste5(float xFunc){
    float yFunc = sin(xFunc) + 3;
    return yFunc;
}

float funcTeste6(float xFunc){
    float yFunc = 2*cos(xFunc - 1);
    return yFunc;
}

// funcao da integral
float integral(int numInt, float ix0, float ixn, float (*func)(float)){ // func e um parametro de uma funcao qualquer
    //int num = 0;
    h = (ixn - ix0)/numInt;
    x = ix0 + h;
    sum = 0;

    for(i=1; i<numInt; i++){
        sum = sum + func(x);
        x = x + h;
    }

    res = h*((func(ix0) + func(ixn))/2 + sum);

    return res;
}

int main() {
    while((ansDnvi == 1)&(ansFunci != 11)) {
        char interface[99][999] = {
                "\n<=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=>\0",
                "\n              -=FUNCIONADOR INTEGRADOR MATEMATICO-COMPUTACIONAL=-\0",
                "\n<=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=>\0",
                "\n\n > Escolha uma das funcoes abaixo para calcular a vossa integral.\0",
                "\n [01] 5x -7\0",
                "\n [02] 2x^2 -3x +1\0",
                "\n [03] 4x^3 -x^2 +3x + 8\0",
                "\n [04] x^4 - 2x^3 + x^2 +9x\0",
                "\n [05] sen(x) + 3\0",
                "\n [06] 2cos(x - 1)\0",
                "\n\n [11] Sair do FIMC\0"
        };
        for (i = 0; i < 99; i++) {
            printf("%s", interface[i]);
        }
        // validacao de resposta da interface. Apenas nao digite caracteres
        do {
            printf("\n  >> ");
            scanf("%s", ansFuncs);
            ansFunci = atoi(ansFuncs);

            isIt = (ansFunci != 1) & (ansFunci != 2) & (ansFunci != 3) & (ansFunci != 4) &
                   (ansFunci != 5) & (ansFunci != 6) & (ansFunci != 11) & (ansFunci != 12);

            if (isIt) {printf(" > Opcao invalida. Por favor, digite um dos indices acima."); }
        } while (isIt == 1);

        // apos escolher uma funcao
        if ((ansFunci != 11)&(ansFunci != 12)) {
            printf(" Digite o numero de trapezios para o calculo da integral.");
            // validacao de resposta
            do {
                printf("\n  >> ");
                scanf("%d", &trap);

                if (trap == 0) { printf("  > Divisao por zero. Por favor, insira um numero inteiro positivo."); }
                if (trap < 0) { printf("  > Numero negativo. Por favor, insira um numero inteiro positivo."); }
            } while (inv(trap > 0));

            // intervalo admitido
            printf(" Digite o ponto inicial do intervalo considerado.");
            printf("\n  >> ");
            scanf("%f", &x0);
            printf(" Digite o ponto final do intervalo considerado.");
            printf("\n  >> ");
            scanf("%f", &xn);

            // calculo da integral com base na funcao escolhida
            if(ansFunci == 1){printf(" Resultado da integral pelo metodo dos trapezios e %.2f.",
                                     integral(trap, x0, xn, funcTeste1));}
            if(ansFunci == 2){printf(" Resultado da integral pelo metodo dos trapezios e %.2f.",
                                     integral(trap, x0, xn, funcTeste2));}
            if(ansFunci == 3){printf(" Resultado da integral pelo metodo dos trapezios e %.2f.",
                                     integral(trap, x0, xn, funcTeste3));}
            if(ansFunci == 4){printf(" Resultado da integral pelo metodo dos trapezios e %.2f.",
                                     integral(trap, x0, xn, funcTeste4));}
            if(ansFunci == 5){printf(" Resultado da integral pelo metodo dos trapezios e %.2f.",
                                     integral(trap, x0, xn, funcTeste5));}
            if(ansFunci == 6){printf(" Resultado da integral pelo metodo dos trapezios e %.2f.",
                                     integral(trap, x0, xn, funcTeste6));}

            // recomecar FIMC
            printf("\n\n  Desejas recomecar? Digite 1 para sim ou 0 para finalizar o FIMC.");
            // validacao de resposta
            do {
                printf("\n  >> ");
                scanf("%s", &ansDnvs);
                ansDnvi = atoi(ansDnvs);

                if ((ansDnvi != 0) & (ansDnvi != 1)) {
                    printf("\n > Opcao invalida. Por favor, digite 1 pra recomecar ou"
                           " 0 para sair do FIMC.");
                }
            } while ((ansDnvi != 0) & (ansDnvi != 1));
        }
        // apos escolher sair do programa
        else{
            printf(" > Voce escolheu sair.");
        }
    }
}
