#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
int main() {
    ll t;
    cin>>t;
    while(t--){unordered_map <ll,ll> g;
        ll n,m;
        cin>>m>>n;ll c = 0 ; 
        for(ll i=1;i<=n;i++){
            ll y;cin>>y;g[y]++;
            
        }
        ll prefix[m+1] = {0};prefix[1] = n ;  
        for(ll i=2;i<=m;i++){
        	
            prefix[i] = prefix[i-1] - g[i-1];
        }
        
        
        for(auto itr=g.begin();itr!=g.end();++itr){
            ll number = itr->first;ll frequency = itr->second; 
            ll u = 0 ; 
            // for(ll p=1;p<=number;p++){
            //     ll l = m - p ; //cout<<p<<"\n";
            //     if(l>=1){
            //       if(l<=number){    
            //       u = u + prefix[l] - 1;}
            //       else{
            //           u = u + prefix[l];
            //       }
            //     }
            // }
            ll tot = pre[]
            u = u*frequency;
            c = c + u ; 
            //itr = g.end();
        }
        
        cout<<c;
        cout<<"\n";
    }
    
    return 0;
}