#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll d[105][105];

ll dp[105][110];

int main() {
    
    ll n;
    cin>>n;
    
    ll k;cin>>k;
    vector <ll> b(n+1,0);
    for(ll i=1;i<=n;i++){
        cin>>b[i];
    }
    sort(b.begin()+1,b.end());
    
    
    
    //cout<<b[2]<<"\n";
    for(ll i=1;i<=n;i++){
        //i-> middle part 
        d[i][i] = 0 ; 
        ll i1=i-1;ll j1=i+1;
        while(i1>=1 && j1<=n){
            //d[i1][j1] explains the best answer for [i1..........j1] if you place the cake in middle;
            d[i1][j1] = d[i1+1][j1-1] + abs(b[i1]-b[i]) + abs(b[j1]-b[i]);
            cout<<i1<<" "<<j1<<" "<<d[i1][j1]<<"\n";
            
            i1--;j1++;
        }
        
        //answer for all odd length subarray has been calculated. 
    }
    
    
    for(ll i=1;i<=n;i++){
        //i-> middle part 
        d[i][i] = 0 ; 
        ll i1=i;ll j1=i+1;
        while(i1>=1 && j1<=n){
            //d[i1][j1] explains the best answer for [i1..........j1] if you place the cake in middle;
            d[i1][j1] = d[i1+1][j1-1] + abs(b[i1]-b[i]) + abs(b[j1]-b[i]);
            cout<<i1<<" "<<j1<<" "<<d[i1][j1]<<"\n";
            i1--;j1++;
        }
        //answer for all even length subarray has been calculated. 
    }
    for(ll i=0;i<=101;i++){
        for(ll j=0;j<=101;j++){
            dp[i][j] = 1e18;
        }
    }
    dp[1][1] = d[1][1];
    for(ll i=2;i<=n;i++){
        dp[i][1] = d[1][i];
        cout<<i<<" 1"<<" "<<dp[i][1]<<"\n";
        for(ll j=2;j<=i;j++){
            //dp[i][j] = put j sticks among first i ppl 
            
            ll j1=i;
            while(j1>=1){
                //last part ->[j1.....i]
                if(j1>=j){
                    ll p = dp[j1-1][j-1] + d[j1][i] ; //RRRRR
                   
                    dp[i][j] = min(dp[i][j],p);
                }
                
                
                j1--;
            }
            cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
        }
        
        
        
    }
    cout<<dp[n][k];
    cout<<"\n";
    
    return 0;
    
}