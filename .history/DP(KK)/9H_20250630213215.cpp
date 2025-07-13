#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

    vector<ll> dpa(n, 0), dpb(n, 0), dpc(n, 0);

    dpa[0] = a[0];
    dpb[0] = b[0];
    dpc[0] = c[0];

    if (n > 1) {
        dpa[1] = a[1] + max({a[0], b[0], c[0]});
        dpb[1] = b[1] + max({a[0], b[0], c[0]});
        dpc[1] = c[1] + max({a[0], b[0], c[0]});
    }

    for (int i = 2; i < n; i++) {
        dpa[i] = max(a[i] + max(dpb[i - 1], dpc[i - 1]), a[i] + a[i - 1] + max(dpb[i - 2], dpc[i - 2]));
        dpb[i] = max(b[i] + max(dpa[i - 1], dpc[i - 1]), b[i] + b[i - 1] + max(dpa[i - 2], dpc[i - 2]));
        dpc[i] = max(c[i] + max(dpa[i - 1], dpb[i - 1]), c[i] + c[i - 1] + max(dpa[i - 2], dpb[i - 2]));
    }

    cout << max({dpa[n - 1], dpb[n - 1], dpc[n - 1]}) << endl;
    return 0;
}
