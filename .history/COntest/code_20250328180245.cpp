#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        ll n, m;
        cin >> m >> n;
        
        unordered_map<ll, ll> g;
        vector<ll> prefix(m + 1, 0);

        // Count frequency of numbers
        for (ll i = 0; i < n; i++) {
            ll y;
            cin >> y;
            g[y]++;
        }

        // Compute prefix sum
        prefix[1] = n;
        for (ll i = 2; i <= m; i++) {
            prefix[i] = prefix[i - 1] - g[i - 1];
        }

        ll c = 0;
        for (const auto& itr : g) {
            ll number = itr.first, frequency = itr.second;
            ll limit = min(number, m - 1);  
            ll u = (limit >= 1) ? prefix[limit] - 1 : 0;
            
            c += u * frequency;
        }

        cout << c << "\n";
    }

    return 0;
}
