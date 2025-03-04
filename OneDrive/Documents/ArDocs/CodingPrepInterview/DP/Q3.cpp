#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n + 1], b[n + 1], dp[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    dp[1] = max(a[1], b[1]);
    dp[2] = max(dp[1], max(a[2], b[2]));
    for (int i = 3; i <= n; i++) {
        int x = dp[i - 1];
        int y = b[i] + dp[i - 2];
        int z = a[i] + dp[i - 2];
        dp[i] = max(x, max(y, z));
    }
    cout << "Answer: " << dp[n] << endl;
    return 0;
}
