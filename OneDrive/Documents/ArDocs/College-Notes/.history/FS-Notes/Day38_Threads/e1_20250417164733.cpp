#include<bits/stdc++.h>
using namespace std;

int main(){

    // dp[i][0] = dp[i-1][1];
// dp[i][1] = max(dp[i-1][0],dp[i-1][1]) + nums[i];
    int n;
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int x;  
        cin>>x;
        nums.push_back(x);
    }
    vector<vector<int>>dp(n + 1,vector<int>(2,0));
    dp[1][0] = 0;
    dp[1][1] = nums[0];

    for(int i=2;i<=n;i++){
        dp[i][0] = dp[i-1][1];
        dp[i][1] = max(dp[i-1][0],dp[i-1][1]) + nums[i - 1];
    }
    cout<<max(dp[n][0],dp[n][1])<<endl;
    return 0;
}