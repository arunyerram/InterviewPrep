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

/*************  ✨ Windsurf Command ⭐  *************/
/**
 * @brief Solves the problem of finding whether it is possible to divide all
 *        numbers in the array into two groups such that the GCD of numbers
 *        in the first group is equal to the GCD of the numbers in the second
 *        group.
 *
 * The idea is to first find the minimum number in the array and then count
 * how many times it occurs in the array. If it occurs more than once, then
 * the answer is "Yes" as we can divide the array into two groups - one
 * containing the minimum number and the other containing all the other
 * numbers.
 *
 * If the count of the minimum number is 1, then we need to find the
 * multiples of the minimum number in the array and then divide them by the
 * minimum number. Then we find the GCD of the divided numbers. If the GCD
 * is 1, then the answer is "Yes", otherwise the answer is "No".
 *
 * @param[in] t The number of testcases.
 * @param[in] n The size of the array.
 * @param[in] arr The array of numbers.
 */
/*******  ee23d00e-ccee-4b83-a023-73959d2daeae  *******/
void solve() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> arr(n); 
        ll x = 1e18;

        for (ll i = 0; i < n; ++i) {
            cin >> arr[i]; 
            x = min(x,arr[i]);
        }

        int mc = 0;
        for (ll i = 0; i < n; ++i) {
            if (arr[i] == x) {
                mc++;
            }
        }

        if (mc >= 2) {
            cout << "Yes" << endl;
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
            if (overall_gcd == 1)
                break;
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