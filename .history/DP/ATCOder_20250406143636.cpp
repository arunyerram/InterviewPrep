#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 


// in some questions masking or pre computation Helps tHink About iT.....................

int main() {
    ll n ; 
    cin>>n ; ll b[n+1] = {0};
    ll i = 1 ; 
    while(i<=n){
        cin>>b[i] ; 
        i++;
    }
    
    
    ll dp[n+1] = {0};
    
    dp[1] = 0 ; 
    dp[2] = abs(b[1]-b[2]);
    i = 3 ; 
    while(i<=n){
        // dp[i] = min(dp[i-1] + abs(b[i]-b[i-1]) ,dp[i-2] + abs(b[i]-b[i-2]));
        dp[i] = min(dp[i-1] + abs(b[i]-b[i-1]), dp[i-2] + abs(b[i] - b[i-2]));
        i++;
    }
    
    cout<<dp[n] ; 
    
    return 0 ; 
}