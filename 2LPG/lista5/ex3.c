#include <stdio.h>
#include <stdlib.h>
/*
3) Faça uma função que calcula o perímetro e a área de um círculo, dado o raio.
*/
#define PI 3.141592

void calcula_circulo(float raio, float *pPerimetro, float *pArea){
    *pPerimetro = 2*PI*raio;
    *pArea = PI*raio*raio;
}

void main(){
    float r, per, area;
    printf(" Digite o raio do circulo: ");
    scanf("%f", &r);
    calcula_circulo(r, &per, &area);
    printf(" circunferencia = %f\n area = %f\n", per, area);
}
