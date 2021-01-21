//2019073027 윤다영 11802
#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int* arr, int n);

int main(void) {
    int n;
    scanf("%d", &n);
    int* arr = (int*)calloc(n, sizeof(int));
    int i;
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    InsertionSort(arr, n);
    for(i=0;i<n;i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}

void InsertionSort(int* arr, int n){
    int j;
    for(j=1;j<n;j++){
        int i = j -1;
        int key = arr[j];
        while(i>=0 && arr[i] < key){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}