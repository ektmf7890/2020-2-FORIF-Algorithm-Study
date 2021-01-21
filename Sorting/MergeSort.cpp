// 2019073027 윤다영 11802
#include <stdio.h>
#include <stdlib.h>

void MergeSort(int*, int l, int r);
void Merge(int*, int l, int q, int r);

int main(void) {
    int n;
    scanf("%d", &n);
    int* arr = (int*)calloc(n, sizeof(int));
    int i;
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    MergeSort(arr, 0, n-1);
    
    for(i=0;i<n;i++){
        printf("%d\n", arr[i]);
    }
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
        if(L[i] >= R[j]){
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