#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        long long mn = LLONG_MAX;  // Use LLONG_MAX for long long

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mn = min(mn, a[i]);
        }

        sort(a.begin(), a.end());

        int mc = count(a.begin(), a.end(), mn);  // Count occurrences of mn

        vector<long long> Help;
        for (int i = 0; i < n; i++) {
            if (a[i] != mn && a[i] % mn == 0) {
                Help.push_back(a[i] / mn);
            }
        }

        int m = Help.size();
        if (m < 2) {
            cout << "No\n";
            continue;
        }

        long long ans = Help[0];
        for (auto it : Help) {
            ans = std::gcd(ans, it); 
        }

        if (ans == 1 || mc > 1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
