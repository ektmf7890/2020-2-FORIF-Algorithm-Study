//https://www.acmicpc.net/problem/2667
#include "2667.h"

void main_2667() {
    int N;
    cin >> N;
    vector<vector<int>> map(N, vector<int>(N, 0));
    for(int i=0;i<N;i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    vector<int> answer;

    // map을 순회, visited면 패스. unvisited 노드의 값이 1이면 bfs를 진행하여 count값을 answer 벡터에 저장.
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<tuple<int, int>> queue;

    //(0, 0) 부터 순회
    for(int i=0;i<N;i++){
        for(int j=0; j<N; j++){
            if(!visited[i][j] && map[i][j]){
                // 방문되지 않았고 값이 1인 요소를 찾으면 거기서부터 bfs 시작
                visited[i][j] = true;
                queue.push(make_tuple(i, j));
                int count = 0;
                while(!queue.empty()){
                    count ++;
                    int currentI = get<0>(queue.front());
                    int currentJ = get<1>(queue.front());
                    queue.pop();

                    vector<tuple<int, int>> adj;
                    if(currentI > 0)
                        adj.push_back(make_tuple(currentI-1, currentJ));
                    if(currentJ > 0)
                        adj.push_back(make_tuple(currentI, currentJ-1));
                    if(currentJ < N-1 )
                        adj.push_back(make_tuple(currentI, currentJ+1));
                    if(currentI < N-1)
                        adj.push_back(make_tuple(currentI+1, currentJ));
                    for(auto x : adj){
                        if(!visited[get<0>(x)][get<1>(x)] && map[get<0>(x)][get<1>(x)]){
                            visited[get<0>(x)][get<1>(x)] = true;
                            queue.push(make_tuple(get<0>(x), get<1>(x)));
                        }
                    }
                }
                answer.push_back(count);
            }
        }
    }
    cout << answer.size() << endl;
    sort(answer.begin(), answer.end());
    for(auto x: answer){
        cout << x << endl;
    }
}
