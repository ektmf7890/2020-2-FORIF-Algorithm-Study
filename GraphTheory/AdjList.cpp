#include "AdjList.h"

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[]){
    for(int i=1; i<V+1; i++){
        cout << i;
        for(auto x: adj[i])
            cout << "->" << x;
        cout << endl;
    }
}

void adj_list_main(){
    // adj : 각 정점마다 간선으로 연결된(인접한) 정점들을 저장하는 연결 리스트
    vector<int> adj[V+1];

    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 4, 6);

    printGraph(adj);
}