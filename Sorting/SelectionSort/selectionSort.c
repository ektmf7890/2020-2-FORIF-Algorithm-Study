#include <stdio.h>

void SelectionSort(int* arr, int count){
    // i :  오른 손의 시작 위치
    int i, j;
    // min : 매번 최솟값을 저장하는 변수
    int minIndex;
    for(i = 0; i < count; i++){
        minIndex = i;
        for(j = i + 1; j < count; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main(){
    int arr [] = {9, 6, 7, 3, 5};
    int count = sizeof(arr)/sizeof(int);    

    SelectionSort(arr, count);

    int i;
    for(i=0; i < count; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
