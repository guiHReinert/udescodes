#include <stdio.h>

void main(){
    int array[9] = {9,1,8,2,7,3,6,4,5};

    for(int i=0; i<(sizeof(array)/sizeof(array[0])-1); i++){
        int min = i;
        for(int s=i+1; s<(sizeof(array)/sizeof(array[0])-1); s++){
            if(array[min]>array[s]){
                min = s;
                }
            
            }
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
        }
    }
