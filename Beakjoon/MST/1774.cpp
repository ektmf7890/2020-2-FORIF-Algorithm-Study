//#include "1774.h"
//
//class Edge{
//public:
//    int node[2];
//    double cost;
//
//    Edge(int u, int v, double cost){
//        this->cost = cost;
//        this->node[0] = u;
//        this->node[1] = v;
//    }
//
//    bool operator < (Edge &edge){
//        return this->cost < edge.cost;
//    }
//};
//
//int Find(vector<int> &parent, int x){
//    if(parent[x] == x)
//        return x;
//    parent[x] = Find(parent, parent[x]);
//    return parent[x];
//}
//
//void Union(vector<int> &parent, int u, int v){
//    u = Find(parent, u);
//    v = Find(parent, v);
//
//    if(u < v){
//        parent[v] = u;
//    }
//    else{
//        parent[v] = u;
//    }
//}
//
//void main_1774() {
//    int N, M;
//    cin >> N >> M;
//
//    vector<pair<int, int>> locations(N+1, make_pair(0,0));
//    int x, y;
//    for(int i=1; i<=N; i++){
//        cin >> locations[i].first >> locations[i].second;
//    }
//
//    // Union find를 수행하기 위한 parent 배열
//    vector<int> parent(N+1, 0);
//    for(int i=1; i<=N; i++){
//        parent[i] = i;
//    }
//    // 이미 연결된 M개의 간선 -> Union을 통해 한 집합으로 묶어준다.
//    int u, v;
//    for(int i=0; i<M; i++) {
//        cin >> u >> v;
//        Union(parent, u, v);
//    }
//
//
//    // 총 계산해야할 간선의 갯수 : nC2 - M
//    vector<Edge> edges;
//    for(u=1; u<=N; u++){
//        for(v=u+1; v<=N; v++){
//            // 이미 연결된 간선이 아니라면...
//            if(Find(parent, u) != Find(parent, v)){
//                int x1 = locations[u].first, y1 = locations[u].second;
//                int x2 = locations[v].first, y2 = locations[v].second;
//                double cost = sqrt(pow((double)(x1-x2), 2) + pow((double)(y1-y2), 2));
//                edges.push_back(Edge(u, v, cost));
//            }
//        }
//    }
//    sort(edges.begin(), edges.end());
//
//    // 사이클을 만들지 않는 N-1개의 간선을 선택
//    int numOfEdges = M;
//    double minCost = 0;
//    for(auto edge: edges){
//        if(numOfEdges == N-1) break;
//
//        int u = edge.node[0];
//        int v = edge.node[1];
//
//        // 사이클이 발생하는 경우
//        if(Find(parent, u) == Find(parent, v)){
//            continue;
//        }
//        // 사이클이 발생하지 않는 경우
//        else{
//            Union(parent, u, v);
//            minCost += edge.cost;
//            numOfEdges ++;
//            printf("%d->%d \n", u, v);
//        }
//    }
//
//    printf("Min cost: %.2f\n", minCost);
//}