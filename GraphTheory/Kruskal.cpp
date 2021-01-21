//#include "Kruskal.h"
//
//// 간선의 정보를 배열에 저장하기 쉽도록 간선 클래스 Edge를 사용
//class Edge{
//public:
//    int node[2];
//    int cost;
//
//    // Edge 객체 생성자.
//    Edge(int x, int y, int cost){
//        // 정점1
//        this->node[0] = x;
//        // 정점2
//        this->node[1] = y;
//        // 간선의 가중치
//        this->cost = cost;
//    }
//
//    // 간선들을 오름차순으로 정렬할 수 있도록 < 연산자를 오버라이딩하였음.
//    bool operator < (Edge &edge){
//        return this->cost < edge.cost;
//    }
//};
//
//int FindParent(vector<int> &parent, int x){
//    if(parent[x] == x){
//        return x;
//    }
//    parent[x] = FindParent(parent, parent[x]);
//    return parent[x];
//}
//
//void Union(vector<int> &parent, int u, int v){
//    u = FindParent(parent, u);
//    v = FindParent(parent, v);
//
//    // 둘 중 숫자가 작은 값을 대푯값으로 하여
//    // 하나의 집합으로 합친다.
//    if(u < v){
//        parent[v] = u;
//    }
//    else{
//        parent[u] = v;
//    }
//}
//
//void kruskal_main() {
//    // 정점의 개수 -> 나중에 parent 배열 초기화할 때 사용
//    int V = 7;
//
//    // 간선들을 저장하는 배열
//    vector<Edge> edges;
//
//    // 정점1과 정점7이 12의 비용으로 연결
//    edges.push_back(Edge(1, 7, 12));
//    edges.push_back(Edge(1, 2, 26));
//    edges.push_back(Edge(1, 4, 23));
//    edges.push_back(Edge(2, 3, 36));
//    edges.push_back(Edge(2, 4, 21));
//    edges.push_back(Edge(2, 5, 45));
//    edges.push_back(Edge(3, 5, 29));
//    edges.push_back(Edge(3, 6, 37));
//    edges.push_back(Edge(3, 7, 55));
//    edges.push_back(Edge(4, 7, 20));
//    edges.push_back(Edge(5, 6, 30));
//
//    // 간선들을 가중치에 따라 오름차순으로 정렬
//    // Edge 클래스의 '<' 연산자를 오버라이딩 -> 가중치에 따라 정렬 가능
//    sort(edges.begin(), edges.end());
//
//    // parent 배열 초기화
//    vector<int> parent(V+1, 0);
//    // 각 정점은 자기자신만으로 이루어진 집합에 속해있음.
//    for(int i=1; i <=V; i++){
//        parent[i] = i;
//    }
//
//    int mst_cost = 0;
//    // kruskal 시작
//    for(auto edge: edges){
//        // 간선의 양끝 정점이 다른 집합 소속이면 간선을 추가. -> mst_cost에 더하고 간선 출력
//        int u = edge.node[0];
//        int v = edge.node[1];
//
//        // 두 정점이 같은 집합에 속함. -> 해당 간선 제외
//        if(FindParent(parent, u) == FindParent(parent, v)){
//            continue;
//        }
//        // 두 정점이 다른 집합에 속함 -> 간선 추가 & 두 집합을 union
//        else{
//            cout << u << "->" << v << endl;
//            mst_cost += edge.cost;
//            Union(parent, u, v);
//        }
//    }
//
//    cout << "MST cost: " << mst_cost << endl;
//}