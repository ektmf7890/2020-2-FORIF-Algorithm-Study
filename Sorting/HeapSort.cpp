//2019073027 윤다영 11802
#include <stdio.h>
#include <stdlib.h>

void MaxHeapify(int* arr, int n, int i);
void BuildMaxHeap(int* arr, int n);
int ExtractMax(int* arr, int n);

int main () {
    int n, k;
    scanf("%d %d", &n, &k);
    int* arr = (int*)calloc(n + 1, sizeof(int));

    int i;
    for(i=1;i<=n;i++){
        scanf("%d", &arr[i]);
    }
    BuildMaxHeap(arr, n);
    
    for(i = 0; i < k; i++){
        printf("%d ", ExtractMax(arr, n));
        n--;
    }
    
    printf("\n");
    for(i = 1; i <= n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

void MaxHeapify(int* arr, int n, int i) {
    int largest = i;
    int leftChild = 2 * i;
    int rightChild = (2 * i) + 1;

    if(leftChild <= n && arr[leftChild] > arr[largest]){
        largest = leftChild;
    }
    if(rightChild <= n && arr[rightChild] > arr[largest]){
        largest = rightChild;
    }
    if(largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        MaxHeapify(arr, n, largest);
    }
}

void BuildMaxHeap(int* arr, int n){
    int i;
    for(i = n/2; i >= 1; i--){
        MaxHeapify(arr, n, i);
    }
}

int ExtractMax(int* arr, int n) {
    int max = arr[1];
    arr[1] = arr[n];
    n--;
    MaxHeapify(arr, n, 1);
    return max;
}