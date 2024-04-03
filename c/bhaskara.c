#include <stdio.h>
#include <math.h>

float a, b, c, delta, ans[2];
float bhaskara(float a, float b, float c, float delta, float raizes[2]);

int main(){

    printf("Digite abaixo, respectivamente, os coeficientes a, b e c da função quadrática geral f(x) = ax² + bx + c:\n");
    printf("\n a = ");
    scanf("\n%f", &a);
    printf(" b = ");
    scanf("\n%f", &b);
    printf(" c = ");
    scanf("\n%f", &c);

    delta = bhaskara(a, b, c, 0, ans);
    
    //printf("\nDelta: %f\n", delta);

    if(delta >= 0){
        printf("\nAs raízes da função f(x) = %.2fx² + %.2fx + %.2f são:", a, b, c);
        printf("\n\n x_1 = %f\n x_2 = %f\n", ans[0], ans[1]);
    }else{
        printf("\nComo \u0394 = %.3f, a função f(x) = %.2fx² + %.2fx + %.2f não possui raízes reais.\n", delta, a, b, c);
    }
    return 0;
}

float bhaskara(float a, float b, float c, float delta, float raizes[2]){
    delta = pow(b, 2)-(4*a*c);
    //printf("\ndelta: %f", delta);

    raizes[0] = (-b-sqrt((delta)))/(2*a);
    //printf("\nRaiz 1: %f", raizes[0]);
    raizes[1] = (-b+sqrt((delta)))/(2*a);
    //printf("\nRaiz 2: %f", raizes[1]);
    
    return delta;
};
