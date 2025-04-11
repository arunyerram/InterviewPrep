#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> b(n + 1);
    unordered_map<int, int> y;
    
    // Input array b
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    // First loop to count sums of pairs (k, l)
    for (int k = 3; k <= n; k++) {
        for (int l = k + 1; l <= n; l++) {
            y[b[k] + b[l]]++;
        }
    }

    long long r = 0;

    // Second loop to count results
    for (int j = 2; j <= n - 2; j++) {
        for (int i = 1; i < j; i++) {
            int d = b[i] + b[j];
            int u = -(b[i] + b[j]);
            r += y[u];  // count of (k, l) whose sum = u
        }

        for (int j1 = j + 2; j1 <= n; j1++) {
            y[b[j + 1] + b[j1]]--;
        }
    }

    cout << r << endl;
    
    return 0;
}
