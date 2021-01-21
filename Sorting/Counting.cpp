// 2019073027 윤다영 11802
#include<stdio.h>
#include<stdlib.h>



int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);
    
    int i;

    int* A = (int*)calloc(K, sizeof(int));
    int* B = (int*)calloc(K, sizeof(int));
    for(i = 0; i < K; i++){
        scanf("%d %d", &A[i], &B[i]);
    }
    
    int* inputKeys = (int*)calloc(N, sizeof(int));
    for(i = 0; i < N; i++){
        scanf("%d", &inputKeys[i]);
    }

    int* C = (int*)calloc(M+1, sizeof(int));
    for(i = 0; i < N; i++){
        C[inputKeys[i]] ++;
    }
    for(i = 1; i <= M; i++){
        C[i] += C[i-1];
    }

    for(i = 0; i < K; i++) {
        int answer = C[B[i]] - C[A[i]-1];
        printf("%d\n", answer);
    }
    return 0;
}