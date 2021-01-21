#include "1260.h"

void dfs(vector<int> adj[], int root, int V);
void bfs(vector<int> adj[], int root, int V);

void main_1260() {
    int V, E, root;
    cin >> V >> E >> root;

    vector<int> adj[V+1];

    int u, v;
    for(int i=0; i<E; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // 각 adjacency 리스트를 정렬 -> 방문해야할 정점이 여러개인 경우 정점 번호가 작은 것을 먼저 방문한다는 조건을 만족하기 위해서
    for(int i=1; i<=V; i++){
        if(!adj[i].empty())
            sort(adj[i].begin(), adj[i].end());
    }

    dfs(adj, root, V);
    cout << endl;
    bfs(adj, root, V);
}

void dfs(vector<int> adj[], int root, int V){
    static vector<bool> visited(V+1, false);

    if(visited[root])
        return;

    visited[root] = true;
    cout << root << " ";

    for(auto adj_node: adj[root]) {
        if (!visited[adj_node])
            dfs(adj, adj_node, V);
    }
}

void bfs(vector<int> adj[], int root, int V){
    queue<int> queue;
    vector<bool> visited(V+1, false);

    visited[root] = true;
    queue.push(root);

    while(!queue.empty()){
        int currentNode = queue.front();
        queue.pop();
        cout << currentNode << " ";
        for(auto adj_node: adj[currentNode]){
            if(!visited[adj_node]){
                visited[adj_node] = true;
                queue.push(adj_node);
            }
        }
    }
}