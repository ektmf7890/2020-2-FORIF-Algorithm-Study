//2019073027 윤다영 11802
#include<stdio.h>
#include<stdlib.h>

void MergeSort(int*, int l, int r);
void Merge(int*, int l, int q, int r);
int FindCommonNumbers(int* A, int* B, int N, int M);

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int* A = (int*)malloc(N*sizeof(int));
    int* B = (int*)malloc(M*sizeof(int));
    int i;
    for(i = 0; i < N; i++){
        scanf("%d", &A[i]);
    }
    for(i = 0; i < M; i++){
        scanf("%d", &B[i]);
    }
    MergeSort(A, 0, N-1);
    MergeSort(B, 0, M-1);
    
    printf("%d", FindCommonNumbers(A, B, N, M));
    return 0;
}

void MergeSort(int* arr, int l, int r){
    if(l < r){
        int q = (l + r)/2;
        MergeSort(arr, l, q);
        MergeSort(arr, q+1, r);
        Merge(arr, l, q, r);
    }
}

void Merge(int* arr, int l, int q, int r){
    int n1 = q - l + 1;
    int n2 = r - q;
    int* L = (int*)malloc(n1*sizeof(int));
    int* R = (int*)malloc(n2*sizeof(int));

    int k;
    for(k=0;k<n1;k++){
        L[k] = arr[l + k];
    }
    for(k=0;k<n2;k++){
        R[k] = arr[q + 1 + k];
    }
    
    int i= 0;
    int j = 0;
    for(k=l;k<=r;k++){
        if(L[i] <= R[j]){
            arr[k]  = L[i];
            i++;
            if(i == n1){
                k++;
                break;
            }
        }
        else {
            arr[k] = R[j];
            j++;
            if(j == n2){
                k++;
                break;
            }
        }
    }
    if(j == n2){
        while(k <= r){
            arr[k] = L[i];
            i++;
            k++;
        }
    }

    if(i == n1) {
        while(k <= r){
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    free(L);
    free(R);
}
 
int FindCommonNumbers(int* A, int* B, int N, int M){
    int commonNumbers = 0;
    int i = 0;
    int j = 0;
    while(i < N && j < M){
        if(A[i] > B[j]) {
            j ++;
        }
        else if(A[i] < B[j]) {
            i ++;
        }
        else{
            commonNumbers ++;
            i++;
            j++;
        }
    }
    return commonNumbers;
}