#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, c;
        cin >> n >> c;
        vector<ll> b(n + 1);
        ll total_sum = 0;

        for (ll i = 1; i <= n; ++i) {
            cin >> b[i];
            total_sum += b[i];
        }

        sort(b.begin() + 2, b.end()); // Sort from b[2] to b[n]

        ll answer = 0;

        for (ll k = 1; k < n; ++k) {
            ll sum_small = accumulate(b.begin() + 2, b.begin() + 2 + k, 0LL);
            ll sum_large = accumulate(b.end() - k, b.end(), 0LL);

            ll val1 = (total_sum - sum_small) * sum_small;
            ll val2 = (total_sum - sum_large) * sum_large;

            if (min(val1, val2) <= c) {
                answer = k;
            }
        }

        cout << n - answer << "\n";
    }
}
