#include "2437.h"

void main_2437() {
    int n;
    cin >> n;

    vector<int> weights(n, 0);
    for(int i=0; i<n; i++){
        cin >> weights[i];
    }
    sort(weights.begin(), weights.end());

    int min = 1;

    for (int i = 0; i < n; i++) {
        if (min < weights[i] ) {
            break;
        }
        min += weights[i];
    }
    cout << min;
}