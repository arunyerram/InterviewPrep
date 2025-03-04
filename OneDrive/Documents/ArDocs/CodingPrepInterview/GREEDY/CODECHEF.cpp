#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> m >> n;

        ll b[n + 15] = {0};
        ll p1 = 0, p2 = 0;

        ll k1[n + 15] = {0}, k5[n + 15] = {0};
        ll sum_k1[n + 15] = {0}, sum_k5[n + 15] = {0};
        ll sumr_k1[n + 15] = {0}, sumr_k5[n + 15] = {0};

        for (ll i = 1; i <= n; i++) {
            cin >> b[i];
            if (b[i] == 1 || b[i] == 3) {
                p1++;
                k1[i] = i;
            }
            if (b[i] == 2 || b[i] == 3) {
                p2++;
                k5[i] = i;
            }
        }

        for (ll i = 1; i <= n; i++) {
            sum_k1[i] = k1[i] + sum_k1[i - 1];
            sum_k5[i] = k5[i] + sum_k5[i - 1];
        }

        for (ll i = n; i >= 1; i--) {
            sumr_k1[i] = k1[i] + sumr_k1[i + 1];
            sumr_k5[i] = k5[i] + sumr_k5[i + 1];
        }

        ll c1 = 0, c2 = 0;

        for (ll i = 1; i <= n; i++) {
            if (k1[i] > 0) {
                c1++;
            }

            ll d1 = i * c1 - sum_k1[i];
            ll d2 = sumr_k1[i] - i * p1;
            ll r1 = d1 + d2;

            if (k1[i] > 0) {
                p1--;
            }

            // For k5 and r5
            if (k5[i] > 0) {
                c2++;
            }

            ll d5 = i * c2 - sum_k5[i];
            ll d6 = sumr_k5[i] - i * p2;
            ll r5 = d5 + d6;

            if (k5[i] > 0) {
                p2--;
            }
            cout<<abs(r1-r5)<<" ";

            // Uncomment to print r1 and r5 for each i
            // cout << "i: " << i << " r1: " << r1 << " r5: " << r5 << "\n";
        }
        cout<<"\n";
    }

    return 0;
}
