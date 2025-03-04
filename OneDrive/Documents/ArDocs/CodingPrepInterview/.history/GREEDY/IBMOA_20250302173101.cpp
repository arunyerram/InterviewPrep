#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll lower(vector <ll> & a1,ll g){
    
    
    auto mg = upper_bound(a1.begin(), a1.end(), g);
    ll kf = mg - a1.begin();

    
    return kf-1;
}
int main() {
    ll n;
    cin >> n;

    vector<ll> b(n + 2);          // Array to store the elements
    vector<ll> prefix(n + 1, 0);  // Prefix sum array

    ll total_sum = 0;

    // Input array elements and calculate prefix sums
    for (ll i = 1; i <= n; i++) {
        cin >> b[i];
        total_sum += b[i];
    }
    b[0] = -1e18; b[n+1] = 1e18;
    // Sort the array for binary search
    sort(b.begin() + 1, b.begin() + n + 1);
    for(ll i = 1; i <= n; i++){
        prefix[i] = b[i] + prefix[i-1];
    }
    
    
    
    
    // Handle queries
    ll q;
    cin >> q;
    while (q--) {
        ll target;
        cin >> target;

        ll g = lower(b,target);
        //cout<<g<<"\n";
        // Calculate left part and right part
        ll left_part = target * g - prefix[g];//cout<<left_part;cout<<"\n";
        ll right_part = (total_sum - prefix[g]) - target * (n - g);

        // Output the total operations
        cout << left_part + right_part << endl;
    }

    return 0;
}
