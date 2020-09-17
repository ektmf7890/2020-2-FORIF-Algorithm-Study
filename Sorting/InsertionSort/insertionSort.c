//ctrl alt c : compile
//ctrl alt r : execute (run)
#include <stdio.h>

void InsertionSort (int* arr, int count){
    int i, j;
    for (i=1; i< count; i++){
        int newNum = arr[i];
        for(j=i-1; j>=0; j--){
            if(arr[j] > newNum){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = newNum;
    }

    for(int i=0; i < count; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr [] = {4, 3, 2, 10, 12, 1, 5, 6};
    int count = sizeof(arr)/sizeof(int);
    InsertionSort(arr, count);
    for(int i=0;i<count;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}