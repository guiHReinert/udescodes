#include <stdio.h>

float matriz[4][99] = {{1,1,1},{1,1,1},{1,1,1},{1,1,1}};

float somat(int nColumns){
    float sum = 0;
    for(int l=0; l<4; l++){
        for(int c=0; c<nColumns; c++){
            sum += matriz[l][c];
        }
    }
    return sum;
}

int main(){
    printf("soma %f\n", somat(4));
    printf("size %ld\n", sizeof(matriz) / sizeof(float));

    return 0;
}