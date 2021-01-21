//https://programmers.co.kr/learn/courses/30/lessons/42586
#include "42586.h"

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<int> days_queue;
    int size = progresses.size();
    for(int i = 0; i < size; i++){
        int days_required = (100-progresses[i])/speeds[i];
        if((100-progresses[i])%speeds[i])
            days_required++;
        days_queue.push(days_required);
    }

    vector<int> answer;
    int max = days_queue.front();
    days_queue.pop();
    int dist_amount = 1;

    while(!days_queue.empty()){
        if(max >= days_queue.front()){
            dist_amount ++;
            days_queue.pop();
        }
        else {
            max = days_queue.front();
            days_queue.pop();
            answer.push_back(dist_amount);
            dist_amount = 1;
        }
    }
    answer.push_back(dist_amount);

    return answer;
}

void solution_main(){
    vector<int> answer = solution({95, 90, 99, 99, 80, 99}, {1, 1, 1, 1, 1, 1});
    for(auto i: answer) {
        cout << i << endl;
    }
}