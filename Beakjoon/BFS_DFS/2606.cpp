#include "2606.h"

int DFS (vector<int> adj[], int root, int V){
    static vector<bool> visited(V+1, false);
    static int count = 0;

    visited[root] = true;
    if(root!=1) count++;

    for(auto x: adj[root]){
        if(!visited[x]){
            DFS(adj, x, V);
        }
    }
    return count;
}

void main_2606(){
    int V, E;
    cin >> V >> E;
    vector<int> adj[V+1];
    int u, v;
    for(int i=0;i<E;i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << DFS(adj, 1, V);
}