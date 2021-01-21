#include "17472.h"

void main_17472() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    // map을 순회하면서 bfs를 하여 각각의 섬에 고유의 정수 값을 줄 것임.
    // bfs를 수행하기 위해 visited 벡터와 queue가 필요.
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> queue;
    int numOfIslands = 0;

    // 각 섬에 해당하는 좌표들을 저장.
    vector<pair<int, int>> island_coordinates[MAX_ISLANDS+1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] && !visited[i][j]) {
                numOfIslands++;
                island_coordinates[numOfIslands].push_back(make_pair(i, j));
                visited[i][j] = true;
                map[i][j] = numOfIslands;
                queue.push(make_pair(i, j));

                while (!queue.empty()) {
                    int currentI = queue.front().first;
                    int currentJ = queue.front().second;
                    queue.pop();

                    // 위아래, 좌우의 4개 인접 좌표를 탐색
                    vector<pair<int, int>> adj;
                    if (currentI > 0)
                        adj.push_back(make_pair(currentI - 1, currentJ));
                    if (currentJ > 0)
                        adj.push_back(make_pair(currentI, currentJ - 1));
                    if (currentJ < m - 1)
                        adj.push_back(make_pair(currentI, currentJ + 1));
                    if (currentI < n - 1)
                        adj.push_back(make_pair(currentI + 1, currentJ));
                    for (auto x : adj) {
                        int i = x.first, j = x.second;
                        if (map[i][j] && !visited[i][j]) {
                            visited[i][j] = true;
                            queue.push(make_pair(i, j));
                            map[i][j] = numOfIslands;
                            island_coordinates[numOfIslands].push_back(make_pair(i, j));
                        }
                    }
                }
            }
        }
    }

    // 프림 알고리즘 수행
    // cost_pq.top().first : 최소 비용
    // cost_pq.top().second : 최소 비용 섬의 인덱스
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> cost_pq;
    vector<bool> selected(numOfIslands + 1, false);
    int mstCost = 0;
    int numOfNodesInMST = 0;

    // 1번 섬에서 시작. cost를 0으로 주고 시작.
    cost_pq.push(make_pair(0, 1));
    while (!cost_pq.empty()) {
        int current_node = cost_pq.top().second;
        int current_node_cost = cost_pq.top().first;
        cost_pq.pop();

        // 선택되지 않았던 섬이면 MST에 포함시켜준다.
        if(!selected[current_node]) {
            selected[current_node] = true;
            mstCost += current_node_cost;
            numOfNodesInMST++;
            if (numOfNodesInMST == numOfIslands) break;

            // 선택된 섬에 해당하는 좌표들에 대해 동서남북으로 탐색하며 가능한 경로들을 탐색한다.
            // MST에 포함되지 않은 섬에 대한 경로가 탐색되면 도로의 길이와 섬의 인덱스를 heap에 저장한다.
            for(auto x: island_coordinates[current_node]) {
                int currentI = x.first, currentJ = x.second;

                int i, j;
                // 서쪽 방향으로 탐색
                i  = currentI; j = currentJ-1;
                while(j >= 0){
                    if( map[i][j] ){
                        if( !selected[map[i][j]] && currentJ-j-1 > 1 ){
                            cost_pq.push(make_pair(currentJ-j-1, map[i][j]));
                        }
                        break;
                    }
                    j--;
                }
                // 동쪽 방향으로 탐색
                i  = currentI; j = currentJ + 1;
                while(j < m){
                    if( map[i][j] ){
                        if(!selected[map[i][j]] && j-currentJ-1 > 1){
                            cost_pq.push(make_pair(j-currentJ-1, map[i][j]));
                        }
                        break;
                    }
                    j++;
                }
                // 북쪽 방향으로 탐색
                i  = currentI - 1; j = currentJ;
                while(i >= 0){
                    if( map[i][j] ){
                        if(!selected[map[i][j]] && currentI-i-1 > 1){
                            cost_pq.push(make_pair(currentI-i-1, map[i][j]));
                        }
                        break;
                    }
                    i--;
                }
                // 남쪽 방향으로 탐색
                i  = currentI + 1; j = currentJ;
                while(i < n){
                    if( map[i][j] ){
                        if(!selected[map[i][j]] && i-currentI-1> 1){
                            cost_pq.push(make_pair(i-currentI-1, map[i][j]));
                        }
                        break;
                    }
                    i++;
                }
            }
        }
    }
    if(numOfNodesInMST < numOfIslands )
        cout << -1;
    else
        cout << mstCost;
}

