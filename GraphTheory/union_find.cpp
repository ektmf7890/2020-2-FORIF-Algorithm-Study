#include "union_find.h"

/*
int FindParent(vector<int> &parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = FindParent(parent, parent[x]);
}

void Union(vector<int> &parent, int a, int b){
    a = FindParent(parent, a);
    b = FindParent(parent, b);

    // 둘 중 작은 값을 부모 노드로 선택
    if( a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

void union_find_main(){
    vector<int> parent(V+1, 0);

    // 초기에는 각 정점이 자기자신만으로 하나의 집합을 이루고 있음.
    for(int i=1; i<=V; i++){
        parent[i] = i;
    }

    // 1이 속한 집합과 2가 속한 집합을 하나로 합쳐라
    Union(parent, 1, 2);
    Union(parent, 2, 3);
    Union(parent, 3, 4);
    Union(parent, 5, 6);
    Union(parent, 6, 7);
    Union(parent, 7, 8);
    Union(parent, 9, 10);

    for(int i=1; i<=V; i++){
        cout << parent[i] << " ";
    }
}
*/