// solve for sHorter probblems and Ace larger problem...............


// Q....   
// q queries telĺ sum upto i from 1...

// code

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1), prefixSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << prefixSum[r] - prefixSum[l - 1] << '\n';
    }

    return 0;
}



