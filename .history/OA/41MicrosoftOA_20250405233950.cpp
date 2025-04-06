#include <bits/stdc++.h>

using namespace std;
typedef long long int ll; 

int main() {
    
    ll n;
    cin>>n;
    ll a[n+1]={0};
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    
    ll x,y;
    cin>>x>>y;

    ll pref[n+1]={0};
    for(ll i=1;i<=n;i++){
        if(i-y>=1){
            pref[i] = a[i] + pref[i-y];
        }
        else{
            pref[i] = a[i];
        }
    }
    
    ll k = 1e18 ; 
    for(ll i=1;i<=n;i++){
        
        ll index = i - (x-1)*y;
        if(index>=1){
            ll g = pref[i] ; 
            if(index-y>=1){
                g = g - pref[index-y] ; 
            }
            k = min(g,k);
            cout<<g ; 
            cout<<'\n';
        }
    }
    cout<<k;
    
    
    
    return 0 ; 
}