#include <stdio.h>

void main(){
    int array[9] = {9,1,8,2,7,3,6,4,5};

    for(int c=0; c<9; c++){
        printf("%d ", array[c]);
    }
    for(int i=0; i<(sizeof(array)/sizeof(array[0])); i++){
        int min = i;
        for(int s=i+1; s<(sizeof(array)/sizeof(array[0])); s++){
            if(array[min]>array[s]){
                min = s;
                }
            }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
        }
    printf("\n");
    for(int c=0; c<9; c++){
        printf("%d ", array[c]);
    }
    }
