


#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 
ll dp[200005][5];
int main() {
    
    ll n ; 
    cin>>n ;
    ll v ; 
    cin>>v ; 
    
    ll easy[n+1] = {0};
    ll hard[n+1] = {0};
    
    
    ll i = 1 ; 
    while(i<=n){
        
        cin>>easy[i];
        cin>>hard[i];
        i++;
    }
    
    dp[1][1] = easy[1] ; //dp[][1]====easy 
    dp[1][2] = hard[1] ; //dp[][2]=====hrd
    dp[1][3] = 0 ; 
    
    i = 2 ; 
    while(i<=n){
        
        dp[i][1] = easy[i] + max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]));
        dp[i][2] = hard[i] + dp[i-1][3] ; //did nothing on i-1 dy
        dp[i][3] = 0 + max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]));
        
        
        i++;
    }
    
    cout<<max(dp[n][1],max(dp[n][2],dp[n][3]));
    
    
    return 0 ; 
}
