
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int b[n + 1]={0}; // Assuming b is already initialized
    
    int dp[n + 1]={0};
    
    for(int i=1;i<=n;i++){
      cin>>b[i];
    }
    
    dp[1] = b[1];
    dp[2] = b[1] + b[2];
    dp[3] = b[1] + b[2] + b[3];
    dp[4] = max(dp[1] + b[4], max(dp[2] + b[4], dp[3] + b[4]));
    dp[5] = max(dp[4] + b[5], dp[2] + b[5]);
    
    for (int i = 6; i <= n; i++) {
        dp[i] = max(dp[i - 1] + b[i], max(dp[i - 3] + b[i], dp[i - 5] + b[i]));
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
