#include <stdio.h>

float* arrSort(float* array, int arr_size){ // The array and size parameters must be diffent
    for(int c=0; c<arr_size; c++){ // Printing unchanged array
        printf("%f ", array[c]);
    }
    for(int i=0; i<arr_size; i++){
        int min = i;
        for(int s=i+1; s<arr_size; s++){
            if(array[min]>array[s]){
                min = s;
                }
            }
        float temp = array[i];
        array[i] = array[min];
        array[min] = temp;
        }
    printf("\n");
    for(int c=0; c<arr_size; c++){ // Printing changed array
        printf("%f ", array[c]);
    }
    printf("\n");
    return array;
}

void main(){
    int arr1[] = {9,1,8,2,7,3,6,4,5};
    int* arr2 = (int*)arrSort((float*)arr1, sizeof(arr1)/sizeof(arr1[0]));
    for(int g=0; g<9; g++){
        printf("%d ", arr2[g]);
    }
}
