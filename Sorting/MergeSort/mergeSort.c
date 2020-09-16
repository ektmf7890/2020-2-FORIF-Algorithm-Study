# define ARRAY_SIZE 7
# include <stdio.h>
# include <stdlib.h>

int resultArr [ARRAY_SIZE] = {0, }; 

void Merge(int* arr, int l, int q, int r){
    while(l <= q && q+1 <= r){
        
    }
}

void MergeSort(int* arr, int l, int r) {
    if(l < r){
        int q = (l+r)/2;
        MergeSort(arr, l, q);
        MergeSort(arr, q+1, r);
        Merge(arr, l, q, r);
    }
}

int main(){
    int arr [ARRAY_SIZE] = {21, 10, 12, 20, 25, 13, 15};
    int count = sizeof(arr)/sizeof(int);
    MergeSort(arr, 0, count-1);
    
    int i=0;
    for(i; i < count; i++){
        printf("%d ", resultArr[i]);
    }
    return 0;
}