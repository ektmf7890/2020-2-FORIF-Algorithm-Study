//
// Created by alisa on 2020-11-06.
//

#include "AdjMatrix.h"

void addEdge(vector<vector<int>> &adj, int u, int v){
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void printGraph(vector<vector<int>> &adj) {
    for(int u=1; u <V+1; u++){
        cout << u;
        for(int v=1; v<V+1; v++)
            if(adj[u][v])
                cout << "->" << v;
        cout << endl;
    }
}

void adj_matrix_main() {
    // adj : 0으로 초기화된 2차원 배열
    vector<vector<int>> adj(V+1, vector<int>(V+1, 0));

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