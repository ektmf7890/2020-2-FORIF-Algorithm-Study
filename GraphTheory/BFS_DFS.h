
#ifndef ALGOSTUDY_BFS_DFS_H
#define ALGOSTUDY_BFS_DFS_H

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define V 10
using namespace std;

void addEdge(vector<int> adj[], int u, int v);
void printGraph(vector<int> adj[]);
void bfs(vector<int> adj[], int start);
void dfs(vector<int> adj[], int start);
void bfs_dfs_main();

#endif //ALGOSTUDY_BFS_DFS_H
