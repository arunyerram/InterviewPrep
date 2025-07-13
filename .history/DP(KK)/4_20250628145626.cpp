
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> cost(n + 1);
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }

    dp[1] = 0;
    dp[2] = abs(cost[2] - cost[1]);
    cout<<dp[2]<<'\n';
    dp[3] = dp[2] + abs(cost[2]-cost[3]);
    cout<<dp[3]<<'\n';
    for (int i = 4; i <= n; ++i) {
        dp[i] = min(abs(cost[i] - cost[i - 1]) + dp[i - 1], abs(cost[i] - cost[i - 3]) + dp[i - 3]);
        cout<<dp[i];
        cout<<'\n';
    }

    cout << dp[n] << endl;
    return 0;
}
