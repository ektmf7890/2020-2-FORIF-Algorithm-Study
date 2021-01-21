// 2019073027_윤다영_11802
#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#define BLACK 1
#define GRAY 2
#define WHITE 3
using namespace std;

int V, E;
int time_;
bool hasCycle = false;

class Vertex{
public:
    int num;
    int color;
    //discovery time
    int d;
    //finish time
    int f;
    vector<int> adj;

    Vertex(int d ,int f, int color){
        this->d = d;
        this->f = f;
        this->color = color;
    }
};

bool compare(Vertex v1, Vertex v2){
    return v1.f < v2.f;
}

void DFS_Visit(vector<Vertex> &vertices, int u){
    vertices[u].color = GRAY;
    time_++;
    vertices[u].d = time_;

    int num;
    for(int i=0; i<vertices[u].adj.size(); i++){
        num = vertices[u].adj[i];
        Vertex *adjVertex = &vertices[num];
        if(adjVertex->color == GRAY){
            hasCycle = true;
            return;
        }
        else if(adjVertex->color == WHITE){
            DFS_Visit(vertices, num);
        }
    }

    vertices[u].color = BLACK;
    time_++;
    vertices[u].f = time_;
    // printf("Vertex%d-> d:%d, f:%d\n", vertices[u].num, vertices[u].d, vertices[u].f);
}

void DFS(vector<Vertex> &vertices){
    time_ = 0;
    for(int i=1; i<=V; i++){
        if(vertices[i].color == WHITE){
            DFS_Visit(vertices, i);
            if(hasCycle) return;
        }
    }
}

void topologicalSort(vector<Vertex> vertices){
    sort(vertices.begin(), vertices.end(), compare);
    for(int i=V; i>=1; i--){
        printf("%d ", vertices[i].num);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V >> E;

    vector<Vertex> vertices(V+1, Vertex(0, 0, WHITE));
    for(int i=1; i<=V; i++){
        vertices[i].num = i;
    }

    int u, v;
    for(int i=0;i<E;i++){
        cin >> u >> v;
        vertices[u].adj.push_back(v);
    }

    for(int i=1; i<=V; i++){
        sort(vertices[i].adj.begin(), vertices[i].adj.end());
    }

    // DFS: ends if cycle is detected
    DFS(vertices);

    if(hasCycle){
        printf("0\n");
    }
    else{
        printf("1\n");
        topologicalSort(vertices);
    }
}