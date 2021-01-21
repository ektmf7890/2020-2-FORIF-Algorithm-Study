// 2019073027 윤다영 11802
#include <iostream>
#include <vector>
using namespace std;

void matrix_chain_order(vector<int> p, vector<vector<int> > &m, vector<vector<int> > &s, int N);
void print_optimal_parens(vector<vector<int> > s, int i, int j);

int main() {
    int N;
    cin >> N;
    vector<int> p (N+1, 0);
    for(int i=0; i<=N;i++){
        cin >> p[i];
    }
    vector<vector<int> > m (N+1, vector<int> (N+1, 0));
    vector<vector<int> > s (N, vector<int> (N+1, 0));

    matrix_chain_order(p, m, s, N);
    cout << m[1][N] << endl;
    print_optimal_parens(s, 1, N);
}

void matrix_chain_order(vector<int> p, vector<vector<int> > &m, vector<vector<int> > &s, int N){
    int l, i, j, k, q;
    for(l=2; l<=N; l++) {
        for(i=1; i <=N-l+1; i++){
            j = i+l-1;
            m[i][j] = m[i][i] + m[i+1][j] + p[i-1]*p[i]*p[j];
            s[i][j] = i;
            for(k=i+1; k<=j-1; k++){
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_optimal_parens(vector<vector<int> > s, int i, int j) {
    if(i==j)
        cout << i << " ";
    else{
        cout << "( ";
        print_optimal_parens(s, i, s[i][j]);
        print_optimal_parens(s, s[i][j]+1, j);
        cout << ") ";
    }
}
