// given two arrays find max sum possible and no two adjacent elements pick up from 2 arrays


// dp[i] = max(dp[i-1], dp[i-2] + max(a[i],b[i]));


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int>v1;
    vector<int>v2;
    cin>>n;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v1.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v2.push_back(x);
    }
    vector<int>dp(n+1,0);   
    dp[0] = max({0 , v1[0] , v2[0]});

    for(int i=1;i<n;i++){
        dp[i] = max(dp[i-1], dp[i-2] + max(v1[i], v2[i]));
    }
    cout<<dp[n-1]<<endl;
    return 0;
}