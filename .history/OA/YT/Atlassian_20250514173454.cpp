#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// ................ COMPLETE - GRAPH.........................
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, c;
        cin >> n >> c;
        vector<ll> b(n + 1);
        ll sum = 0;

        for (ll i = 1; i <= n; ++i) {
            cin >> b[i];
            sum += b[i];
        }
        sort(b.begin() + 2, b.end()); 
        ll rmv = 0;

        for (ll k = 1; k < n; ++k) {
            ll sum_small = accumulate(b.begin() + 2, b.begin() + 2 + k, 0LL);
            ll sum_large = accumulate(b.end() - k, b.end(), 0LL);

            ll val1 = (sum - sum_small) * sum_small;
            ll val2 = (sum - sum_large) * sum_large;

            if (min(val1, val2) <= c) {
                rmv = k;
            }
        }
        cout << n - rmv << "\n";
    }
}
