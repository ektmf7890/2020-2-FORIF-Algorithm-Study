// 2019073027_윤다영_11802

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

int connectedComponents;

int Find(vector<int> &parent, int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = Find(parent, parent[x]);
}

void Union(vector<int> &parent, int u, int v){
    u = Find(parent, u);
    v = Find(parent, v);

    if(u != v){
        connectedComponents --;
    }
    
    if(u < v) {
        parent[v] = u;
    }
    else{
        parent[u] = v;
    }
}


int main(){
    int V, E;
    cin >> V >> E;

    vector<int> parent (V+1, 0);
    for(int i=1;i<=V; i++){
        parent[i] = i;
    }

    connectedComponents = V;

    int u, v;
    for(int i=0; i<E; i++){
        cin >> u >> v;
        Union(parent, u, v);
    }

    cout << connectedComponents;
}