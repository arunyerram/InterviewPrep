// max best sum in array witHout pick adjacent.................


// dp[i] = max(dp[i-1],dp[i-2] + nums[i]);

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }

    vector<int> dp(n + 1, 0);
    dp[1] = nums[1];
    
    for (int i = 2; i <= n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }

    cout << dp[n] << '\n';

    return 0;
}
