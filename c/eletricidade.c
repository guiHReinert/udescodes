#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int energy, day, month, year, pos_slash1 = 0, pos_slash2 = 0;
float kwh = 0.35, bill;
char banner[9], data0[10], data1[10], sliced[3][10];

int main (){

    printf("\n Bandeira: ");
    scanf("%s", banner);
    printf(" Energia consumida (kWh): ");
    scanf("%d", &energy);
    printf(" Data de Leitura: ");
    scanf("%s", data0);
    
    if ((strcmp(banner, "VERDE") == 0)||(strcmp(banner, "verde") == 0)){
        bill = energy*kwh;
    }
    else if ((strcmp(banner, "AMARELA") == 0)||(strcmp(banner, "amarela") == 0)){
        bill = energy*kwh + 1.5*(int)((energy)/100);
    }
    else if ((strcmp(banner, "VERMELHA1") == 0)||(strcmp(banner, "vermelha1") == 0)){
        bill = energy*kwh + 3*(int)((energy)/100);
    }
    else if ((strcmp(banner, "VERMELHA2") == 0)||(strcmp(banner, "vermelha2") == 0)){
        bill = energy*kwh + 4.5*(int)((energy)/100);
    }else{
        bill = 0.0;
    }

    for(int i = 0; i < strlen(data0); i++){
        if(data0[i] == '/' && pos_slash1 == 0){
            pos_slash1 = i;

            strncpy(sliced[0], data0, pos_slash1);
            day = atoi(sliced[0]);
        }
        else if(data0[i] == '/' && pos_slash1 > 0){
            pos_slash2 = i;
        
            strncpy(sliced[1], data0 + pos_slash1 + 1, pos_slash2 - pos_slash1);
            month = atoi(sliced[1]);

            strncpy(sliced[2], data0 + pos_slash2 + 1, 4);
            year = atoi(sliced[2]);
        }
    }

    if(day > 28 && month == 1){
        day = 28;
    }
    if(month + 1 > 12){
        month = 0;
        year++;
    }

    sprintf(data1, "%02d", day);
    sprintf(data1 + 2, "%c", '/');
    sprintf(data1 + 3, "%02d", month + 1);
    sprintf(data1 + 5, "%c", '/');
    sprintf(data1 + 6, "%d", year);

    printf("\n R$ %.2f\n Bandeira %s\n Vencimento: %s\n", bill, banner, data1);

    return 0;
}
