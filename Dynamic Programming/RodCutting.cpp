// 2019073027 윤다영 11802
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bottom_up_cut_rod(vector<int> p, vector<int> &r, vector<int> &s, int N);
void print_cut_rod(vector<int> s, int N);

int main() {
    int N;
    cin >> N;
    vector<int> p(N+1, 0);
    for(int i=1; i<=N; i++){
        cin >> p[i];
    }

    vector<int> r(N+1, 0);
    vector<int> s(N+1, 0);
    bottom_up_cut_rod(p, r, s, N);
    cout << r[N] << endl;
    print_cut_rod(s, N);
}

void bottom_up_cut_rod(vector<int> p, vector<int> &r, vector<int> &s, int N){
    int q;
    
    for(int j=1; j<=N; j++){
        q = -1;
        for(int i=1; i<=j; i++){
            if(q < p[i] + r[j-i]){
                q = p[i] + r[j-i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
}

void print_cut_rod(vector<int> s, int N){
    vector<int> answer;
    while(N > 0) {
        answer.push_back(s[N]);
        N -= s[N];
    }
    sort(answer.begin(), answer.end());
    for(int i=0; i<answer.size(); i++)
        cout << answer[i] << " ";
}