#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        string st;
        cin >> st;

        string ans = st;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(st[i], st[j]);
                ans = min(ans, st);
                swap(st[i], st[j]); // backtrack
            }
        }
        cout << ans << endl;
    }

    return 0;
}
