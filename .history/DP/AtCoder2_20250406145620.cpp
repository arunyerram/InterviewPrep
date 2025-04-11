#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 

int main() {
    ll n ; 
    cin>>n ; ll k; cin>>k ; 
    ll b[n+1] = {0};
    ll i = 1 ; 
    while(i<=n){
        cin>>b[i] ; 
        i++;
    }
    ll dp[n+1] = {0};
    
    dp[1] = 0 ; 
    dp[2] = abs(b[1]-b[2]);
    //cout<<dp[1]<<"\n";
    //cout<<dp[2]<<"\n";
    i = 3 ; 
    while(i<=n){
        ll answer = 1e18 ; 
        ll j = 1 ; 
        while(j<=k && i-j>=1){
            ll yy = dp[i-j] + abs(b[i]-b[i-j]);
            answer = min(answer,yy);
            j++;
        }
        dp[i] = answer; 
        i++;
    }
    cout<<dp[n] ; 
    return 0 ; 
}