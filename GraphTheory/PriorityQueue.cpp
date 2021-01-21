// 2019073027 윤다영 11802
#define MAX_LENGTH 100000
#include<stdio.h>
#include<stdlib.h>
#include <queue>
using namespace std;

void MaxHeapify(int* heap, int n, int i);
void Insert(int* heap, int n, int key);
int ExtractMax(int* heap, int n);
void ReplaceKey(int* heap, int n, int index, int key);

int main() {
    int n = 0;
    int* heap = (int*)calloc(MAX_LENGTH+1, sizeof(int));

    queue <int> extractedElements;

    int op = 1;
    while(op){
        scanf("%d", &op);
        switch (op)
        {
            case 0:
            {
                int i;

                while(!extractedElements.empty()){
                    printf("%d ", extractedElements.front());
                    extractedElements.pop();
                }
                printf("\n");
                for(i = 1; i <= n; i++){
                    printf("%d ", heap[i]);
                }
                break;
            }
            case 1:
            {
                int newKey;
                scanf("%d", &newKey);
                if(n < MAX_LENGTH){
                    n++;
                    Insert(heap, n, newKey);
                }
                break;
            }
            case 2:
            {
                int max = ExtractMax(heap, n);
                n --;
                extractedElements.push(max);
                break;
            }
            case 3:
            {
                int index, key;
                scanf("%d %d", &index, &key);
                ReplaceKey(heap, n, index, key);
                break;
            }
            default:
                break;
        }
    }
    free(heap);
    return 0;
}

void MaxHeapify(int* heap, int n, int i) {
    int largest = i;
    int leftChild = 2 * i;
    int rightChild = (2 * i) + 1;

    if(leftChild <= n && heap[leftChild] > heap[largest]){
        largest = leftChild;
    }
    if(rightChild <= n && heap[rightChild] >= heap[largest]){
        largest = rightChild;
    }
    if(largest != i) {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;
        MaxHeapify(heap, n, largest);
    }
}

int ExtractMax(int* heap, int n) {
    int max = heap[1];
    heap[1] = heap[n];
    n--;
    MaxHeapify(heap, n, 1);
    return max;
}

void Insert(int* heap, int n, int key) {
    int i = n;
    while(i > 1 && heap[i/2] < key){
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i] = key;
}

void ReplaceKey(int* heap, int n, int i, int key) {
    heap[i] = key;
    while(i > 0) {
        MaxHeapify(heap, n, i);
        if(heap[i/2] < heap[i]){
            i /= 2;
        }
        else{
            break;
        }
    }
}