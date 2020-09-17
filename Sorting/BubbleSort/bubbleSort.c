#include <stdio.h>

void BubbleSort(int* arr, int count) { 
    int i = count - 1;
    int j;
    for (i; i >= 0; i--) {
        for (j = 0; j < i; j++) {
            if ( arr[j] > arr[j+1] ){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() { 
    int arr [] = {7, 4, 5, 1, 3};
    int count = sizeof(arr)/sizeof(int);
    BubbleSort(arr, count);
    
    int i;
    for(i = 0; i < count; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}