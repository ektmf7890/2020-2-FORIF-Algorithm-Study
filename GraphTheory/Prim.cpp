#include "Prim.h"
// 관련 문제 - 백준17472

int V, E;
int prim(vector<pair<int, int>> adj[]);
int prim_pq(vector<pair<int, int>> adj[]);

void prim_main() {
    cin >> V >> E;

    //cost[i].first: 인접 정점 i와 연결되는 간선의 가중치, cost[i].second: 인접 정점 i의 인덱스
    vector<pair<int, int>> adj[V+1];

    int a, b, c;
    for(int i=0; i<E; i++){
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(c, b));
        adj[b].push_back(make_pair(c, a));
    }

    cout << "MST : " << prim_pq(adj) << endl;
}

int prim(vector<pair<int, int>> adj[]) {
    int mst_cost = 0;

    vector<int> cost (V+1, INF);
    vector<bool> selected (V+1, false);

    // 1번 정점에서 시작
    // 1번 정점의 거리 값은0으로 초기화하고, 인접한 정점들의 거리 값을 update한다.
    cost[1] = 0;
    selected[1] = true;
    for(auto x: adj[1]){
        int adj_node_cost = x.first;
        int adj_node = x.second;
        cost[adj_node] = adj_node_cost;
    }

    // 총 V-1 개의 간선을 선택 -> 반복문을 V-1번 반복
    for(int i=0; i<V-1; i++){
        // distance 배열에서 가장 작은 cost를 갖는 vertex를 선택
        int min_vertex = 0;
        for(int j=1; j <= V; j++){
            if(selected[j]) continue;
            if(cost[j] < cost[min_vertex]){
                min_vertex = j;
            }
        }
        selected[min_vertex] = true;
        mst_cost += cost[min_vertex];

        // 인접한 정점들 중 더 작은 cost가 발견되면 업데이트 해주기
        for(auto x: adj[min_vertex]){
            int adj_node = x.second;
            if(!selected[adj_node]) {
                int adj_node_cost = x.first;
                if (adj_node_cost < cost[adj_node]) {
                    cost[adj_node] = adj_node_cost;
                }
            }
        }
    }
    return mst_cost;
}

int prim_pq(vector<pair<int, int>> adj[]){
    int mst_cost = 0;

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > > pq;
    vector<bool> selected(V+1, false);

    // 1번 정점으로 시작
    selected[1] = true;
    for(auto x: adj[1]){
        pq.push(x);
    }

    while(!pq.empty()){
        int current_node = pq.top().second;
        int current_cost = pq.top().first;
        pq.pop();

        if(!selected[current_node]) {
            selected[current_node] = true;
            mst_cost += current_cost;

            for (auto x: adj[current_node]) {
                if (!selected[x.second]) {
                    int cost = x.first;
                    int index = x.second;
                    pq.push(make_pair(cost, index));
                }
            }
        }
    }
    return mst_cost;
}