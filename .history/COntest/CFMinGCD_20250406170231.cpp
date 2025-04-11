#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solve() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n); 
        ll x = 1e18;
        unordered_map <ll,ll> d;
        for (ll i = 0; i < n; ++i) {
            cin >> arr[i]; x = min(x,arr[i]);d[arr[i]]++;
        }
        if(d[x]>=2){
        	cout<<"Yes"<<"\n";
        	continue;
        }

        vector<ll> multiples;
        for (ll num : arr) {
            if (num % x == 0 && num!=x) {
                multiples.push_back(num);
            }
        }

        if (multiples.size() < 2) {
            cout << "No" << endl;
            continue;
        }

        vector<ll> divided;
        for (ll num : multiples) {
            divided.push_back(num / x);
        }

        ll overall_gcd = divided[0];
        for (size_t i = 1; i < divided.size(); ++i) {
            overall_gcd = gcd(overall_gcd, divided[i]);
            if (overall_gcd == 1) {
                break;
            }
        }

        if (overall_gcd == 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}