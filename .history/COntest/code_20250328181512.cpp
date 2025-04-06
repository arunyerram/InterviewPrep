#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll;
int main() {
    
    ll t;
    // cin
    cin>>t;

    while(t--){

        unordered_map <ll,ll> g;
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

            /* The commented code snippet is calculating the value of `tot` based on the values in the
            `prefix` array. */
            ll tot = prefix[m- number] - prefix[m - 1];

            // if(m-number >= 1){

                // if(m-number <= number){   
                //     u = tot - 1 ;}
                // else u = tot;
            }
            // u = tot;
            
            u = u*tot;
            c = c + u ; 
            //itr = g.end();
        }
        
        cout<<c;

        cout<<"\n";
    }
    
    return 0;

}