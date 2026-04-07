#include <stdio.h>
#include <stdlib.h>
/*
4) Faça uma função que receba um parâmetro (por valor) com o total de minutos passados
ao longo do dia e receba também dois parâmetros (referência) no qual deve preencher
com o valor da hora e do minuto corrente. Faça um programa que leia do teclado quantos
minutos se passaram desde meia-noite e imprima a hora corrente (use a sua função).
*/
void calcula_hora(int totalMinutos, int *ph, int *pm){
    *ph = totalMinutos/60;
    *pm = totalMinutos - 60*(*ph);
}

void main(){
    int min, hours, acMin;
    printf(" Digite os minutos decorridos: ");
    scanf("%d", &min);
    calcula_hora(min, &hours, &acMin);
    printf(" Hora corrente = %dh %dmin\n", hours, acMin);
}
