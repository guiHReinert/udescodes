#include <stdio.h>
#include <math.h>

float a, b, c, ans[2];
float bhaskara(float a, float b, float c, float raizes[2]);

int main(){

    printf("Digite abaixo, respectivamente, os coeficientes a, b e c da função quadrática geral f(x) = ax^2 + bx + c:\n");
    printf("\n a = ");
    scanf("\n%f", &a);
    printf(" b = ");
    scanf("\n%f", &b);
    printf(" c = ");
    scanf("\n%f", &c);

    bhaskara(a, b, c, ans);

    printf("\nAs raízes da função f são:");
    printf("\n\n x_1 = %f\n x_2 = %f\n", ans[0], ans[1]);

    return 0;
}

float bhaskara(float a, float b, float c, float raizes[2]){
    raizes[0] = (-b-sqrt((pow(b, 2))-(4*a*c)))/(2*a);
    raizes[1] = (-b+sqrt((pow(b, 2))-(4*a*c)))/(2*a);
};