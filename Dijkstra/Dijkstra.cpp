#include "Dijkstra.h"

struct Edge{
    int destVertex;
    int cost;
};

struct Vertex {
    int vertexNum;
    int d;
};
struct compare{
    bool operator() (Vertex v1, Vertex v2){
        return v1.d > v2.d;
    }
};

void Dijkstra(vector<Edge> adjList[], vector<int> &d);

int v, e, startVertex;

void dijkstra_main () {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e;
    cin >> startVertex;

    vector<Edge> adjList [v+1];
    for(int i=0; i<e; i++) {
        int _u, _v, _w;
        cin >> _u >> _v >> _w;
        adjList[_u].push_back({.destVertex = _v, .cost=_w});
    }

    vector<int> d (v+1, INFINITE);
    Dijkstra(adjList, d);
}

void Dijkstra(vector<Edge> adjList[], vector<int> &d){
    priority_queue<Vertex, vector<Vertex>, compare> pq;

    d[startVertex] = 0;
    pq.push({.vertexNum = startVertex, .d = d[startVertex]});

    while(!pq.empty()) {
        int vertex = pq.top().vertexNum;
        int dist = d[vertex];
        pq.pop();

        for(auto adjEdge: adjList[vertex]){
            int adjVertex = adjEdge.destVertex;
            int adjCost = adjEdge.cost;

            if (dist + adjCost < d[adjVertex]) {
                d[adjVertex] = dist + adjCost;
                pq.push({.vertexNum = adjVertex, .d = d[adjVertex]});
            }
        }
    }

    for(int i=1; i<=v; i++){
        if(d[i] == INFINITE){
            cout << "INF" << endl;
        }
        else{
            cout << d[i] << endl;
        }
    }
}