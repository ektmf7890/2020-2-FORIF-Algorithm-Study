//https://programmers.co.kr/learn/courses/30/lessons/64061
#include "64061.h"

int solution(vector<vector<int>> boards, vector<int> moves) {
    int n = boards.size();
    stack<int> basket;
    int answer = 0;

    vector<int> searchRow;
    for(int i=0; i < n; i++){
        int j = 0;
        while(j < n && boards[j][i]==0){
            j++;
        }
        searchRow.push_back(j);
    }

    for(int i = 0; i < moves.size(); i++){
        //boards[][moves[i-1]]에서 0이 아닌 값이 있는지 확인
        int col = moves[i]-1;
        int row = searchRow[col];
        if(row != n){
            if(!basket.empty() && basket.top() == boards[row][col]){
                answer += 2;
                basket.pop();
            }
            else basket.push(boards[row][col]);
            searchRow[col] ++;
        }
    }

    return answer;
}

void main_64061() {
    int a = solution({{0,0,0,0,0}, {0,0,1,0,3}, {0,2,5,0,1}, {4,2,4,4,2}, {3,5,1,3,1}}, {1,5,3,5,1,2,1,4});
    cout << a << endl;
}

