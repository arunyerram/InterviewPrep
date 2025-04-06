#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll h[200005]; ll dp[200005];vector <ll> G[200005];
void dfs(ll node,vector <ll> &used,vector <ll> G[],vector <ll> &p){
    used[node] = 1 ;
   
    for(auto u : G[node]){
        if(used[u]==0){
            p[u] = node ;
            dfs(u,used,G,p);
        }
    }
   
    ll d = 0 ;
     for(auto u : G[node])
        if(u!=p[node])
          d = max(d,h[u]);
        
     
     h[node] = d + 1;
     //cout<<node<<" "<<h[node]<<"\n";
}

void dfs2(ll node,vector <ll> &used,vector <ll> G[],vector <ll> &p){
    used[node] = 1 ;

    for(auto u : G[node]){
        if(used[u]==0){
            p[u] = node ;
            dfs2(u,used,G,p);
        }
    }
    vector <ll> child;
    for(auto u : G[node])
        if(u!=p[node])
          child.push_back(u);
    
    
    
    ll n = child.size();
   
    if(n>=1){
    vector <ll> prefix(n,0);prefix[0] = dp[child[0]];
    vector <ll> suffix(n,0);suffix[n-1] = dp[child[n-1]]; 
    for(ll i=1;i<n;i++){
    	prefix[i] = prefix[i-1] + dp[child[i]]; 
    }
    for(ll i=n-2;i>=0;i--){
    	suffix[i] = suffix[i+1] + dp[child[i]]; 
    }
    
    
   
   
    ll d = 0 ;ll id = 0 ; 
    for(auto u : G[node]){
        if(u!=p[node]){ll z = 0 ; 
          // for(auto u2 : G[node]){
              // if(u2!=p[node] && u!=u2){
                  // z = z + dp[u2]; 
              // }
          // }
         
          if(id-1>=0){
          	z = z + prefix[id-1];
          }
          if(id+1<=n-1){
          	z = z + suffix[id+1];
          }
          
           
          dp[node] = max(dp[node],z + dp[u] + 2*h[u] + 1);id++;
        }
    }
    }
    if(G[node].size()==0){
        dp[node] = 1;
    }
    //cout<<node<<" "<<dp[node]<<"\n";
}


int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;cin>>n; 
        for(ll i=1;i<=n;i++){
        	G[i].clear();
        }
        for(ll i=1;i<=n-1;i++){
            ll d;
            cin>>d;
            G[d].push_back(i+1);
            dp[i]=0;
            h[i]=0;
            //cout<<d<<" "<<i+1<<"\n";
        }
        vector <ll> used(n+1,0);
         vector <ll> p(n+1,-1);dp[n]=0;h[n]=0;
        dfs(1,used,G,p);vector <ll> used2(n+1,0);
        dfs2(1,used2,G,p);
        cout<<dp[1]<<"\n";
    }
    
    
    
    return 0;
}