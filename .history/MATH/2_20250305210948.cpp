#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll MAXN = 1000000;

vector<ll> spf(MAXN + 1); // spf[i] will store the smallest prime factor of i

void computeSPF() {
    // Initialize spf for every number to itself
    for (ll i = 2; i <= MAXN; i++) {
        spf[i] = i;
    }

    // Start the sieve process
    for (ll i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) { // Check if i is prime
            for (ll j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j) { // Update spf[j] to the smallest prime factor
                    spf[j] = i;
                }
            }
        }
    }
}

unordered_map <ll,ll> cl(ll vl){ unordered_map <ll,ll> a2;
    while(vl!=1){
        ll d = spf[vl]; a2[d]++;
        vl = vl/d;
    }
    return a2;
}

int main() {ll n;cin>>n;ll m;cin>>m;unordered_map <ll,ll> b1; 
    // Compute SPF for all numbers from 2 to MAXN
    computeSPF();ll md = 1e9+7;
    for(ll i=2;i<=m;i++){
        unordered_map <ll,ll> a2 = cl(i);
        //cout<<"for index i->";
        for(auto itr = a2.begin();itr!=a2.end();++itr){
            //cout<<itr->first<<" "<<itr->second;
            
            
            b1[itr->first] = b1[itr->first] + itr->second;
            
            //cout<<"\n";
        }   
    }
    ll b[n+1]={0};
    for(ll i=1;i<=n;i++){unordered_map <ll,ll> b5 = b1 ; ll g = 1 ; 
        cin>>b[i];
        unordered_map <ll,ll> a2 = cl(b[i]);
        //cout<<"for index i->";
        for(auto itr = a2.begin();itr!=a2.end();++itr){
            
            
            b5[itr->first] = b5[itr->first] + itr->second;
        }
        
        for(auto itr = b5.begin();itr!=b5.end();++itr){
            
            g = ((g%md)*( (itr->second%md + 1%md)%md))%md;
        }cout<<g<<" ";
        
        
    }
    
    
    
    
    
    
    

    return 0;
}
