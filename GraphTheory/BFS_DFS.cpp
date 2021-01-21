#include "BFS_DFS.h"
#include "AdjList.h"

vector<bool> visited(V+1, false);

void dfs(vector<int> adj[], int root){
    if(visited[root])
        return;

    visited[root] = true;
    cout << root << " ";

    for(auto x: adj[root]){
        if(!visited[x]){
            dfs(adj, x);
        }
    }
}

void dfs_stack(vector<int> adj[], int root){
    stack<int> stack;
    stack.push(root);

    visited[root] = true;
    cout << root << " ";

    while(!stack.empty()){
        int current_node = stack.top();
        stack.pop();
        for(auto x: adj[current_node]){
            if(!visited[x]){
                cout << x << " ";
                visited[x] = true;
                stack.push(current_node);
                stack.push(x);
                break;
            }
        }
    }
}

void bfs(vector<int> adj[], int start) {
    queue<int> queue;
    queue.push(start);
    visited[start] = true;

    while(!queue.empty()){
        int currentNode = queue.front();
        queue.pop();
        cout << currentNode << " ";

        for(auto x: adj[currentNode]){
            if(!visited[x]){
                visited[x] = true;
                queue.push(x);
            }
        }
    }
}

void bfs_dfs_main(){
    vector<int> adj[V+1];

    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 6);
    addEdge(adj, 3, 7);
    addEdge(adj, 4, 8);
    addEdge(adj, 5, 9);

    dfs_stack(adj, 1);
    cout << endl;
    bfs(adj, 1);
}