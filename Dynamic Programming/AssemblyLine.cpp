//2019073027 윤다영 11802
#include <iostream>
#include <vector>
using namespace std;

void fastest_way(vector<vector<int> > &a, vector<vector<int> > &t, vector<vector<int> > &l, vector<int> e, vector<int> x, int N);
void print_stations(vector<vector<int> > &l, int l_, int N);
int s_, l_;

int main() {
    int N;
    vector<int> e(3, 0);
    vector<int> x(3, 0);
    cin >> N;
    cin >> e[1] >> e[2];
    cin >> x[1] >> x[2];

    vector<vector<int> > a(3, vector<int>(N+1, 0));
    vector<vector<int> > t(3, vector<int>(N, 0));

    for(int i=1; i<=2; i++){
        for(int j=1; j<=N; j++){
            cin >> a[i][j];
        }
    }
    for(int i=1; i<=2; i++){
        for(int j=1; j<=N-1; j++){
            cin >> t[i][j];
        }
    }

    vector<vector<int> > l(3, vector<int>(N+1, 0));

    fastest_way(a, t, l, e, x, N);
    cout << s_ << endl;
    print_stations(l, l_, N);
}

void fastest_way(vector<vector<int> > &a, vector<vector<int> > &t, vector<vector<int> > &l, vector<int> e, vector<int> x, int N){
    vector<vector<int> > s(3, vector<int>(N+1, 0));
    s[1][1] = e[1] + a[1][1];
    s[2][1] = e[2] + a[2][1];

    for(int j=2; j<=N; j++){
        if(s[1][j-1] + a[1][j] <= s[2][j-1] + t[2][j-1] + a[1][j]){
            s[1][j] = s[1][j-1] + a[1][j];
            l[1][j] = 1;
        }
        else{
            s[1][j] = s[2][j-1] + t[2][j-1] + a[1][j];
            l[1][j] = 2;
        }

        if(s[2][j-1] + a[2][j] <= s[1][j-1] + t[1][j-1] + a[2][j]){
            s[2][j] = s[2][j-1] + a[2][j];
            l[2][j] = 2;
        }
        else{
            s[2][j] = s[1][j-1] + t[1][j-1] + a[2][j];
            l[2][j] = 1;
        }
    }
    if(s[1][N] + x[1] <= s[2][N] + x[2]){
        s_ = s[1][N] + x[1];
        l_ = 1;
    }
    else{
        s_ = s[2][N] + x[2];
        l_ = 2;
    }
}

void print_stations(vector<vector<int> > &l, int line, int N){
    if(N > 1)
        print_stations(l, l[line][N], N-1);
    cout << line << " " << N << endl;
}