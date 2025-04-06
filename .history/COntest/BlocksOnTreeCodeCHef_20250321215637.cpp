#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;ll id = -1;
ll sum[5000+5];ll n,k;ll g = 0;ll vl[5000+5];
void DFS(ll node,vector <ll> G[],ll used[],ll parent[]){
 
    used[node] = 1 ; 
 
    for(auto u: G[node]){ //iterating all children "u" of "node"
 
        if(used[u]==0){
            //if this node/branch has never been visited before 
            //just go into it and search it using dfs in recursion
            parent[u] = node ; 
            DFS(u,G,used,parent);
 
        }
    }
 
 
    //print(node)--->parent
    //----> bottom up traversal 
    ll s = 0 ; 
    for(auto child: G[node]){
 
        if(child==parent[node]){
            //it means the child node is parent of the node
            //it is not the child
            //ignore it
        }
 
        else{
            s = s + sum[child]; 
        }
    }
 
    sum[node] = 1 + s; 
    ll sz1 = sum[node];ll sz2 = n - sz1;
    if(sz1==k){ g = 1 ; id = node; 
        //color with 1 
    }else if(sz2==k){ g = 2 ; id = node;
        //color with 0 
    }
 
 
}


void dfs1(ll node,vector <ll> G[],ll used1[],ll parent[]){
    used1[node] = 1 ; 
    if(g==1){vl[node]=1;}
    if(g==2){vl[node]=0;}
    for(auto u: G[node]){ 
        if(used1[u]==0 && u!=parent[node]){
            dfs1(u,G,used1,parent);
        }
    }
}




int main() {
    
    ll t;
    cin>>t;
    while(t--){
        
        cin>>n;cin>>k;
        vector <ll> G[n+1];g=0;
        for(ll i=1;i<=n-1;i++){
            ll x,y;cin>>x>>y;sum[i] = 0;vl[i] = 0 ; 
            G[x].push_back(y);
            G[y].push_back(x);
        }
        sum[n] = {0};vl[n] = {0};
    ll used[n+1] = {0};
    ll parent[n+1] = {0};ll used1[n+1] = {0};
    DFS(1,G,used,parent); //starts from node 1
    if(k==n){
        cout<<"1";cout<<"\n";
        for(ll i=1;i<=n;i++){
            cout<<"1 ";
        }
    }else if(k==0){
        cout<<"1";cout<<"\n";
        for(ll i=1;i<=n;i++){
            cout<<"0 ";
        }
    }else{
        if(g==1 || g==2){
            cout<<"2";cout<<"\n";
            //cout<<g<<" "<<id<<"\n";
            if(g==1){//cout<<id<<"\n";
            
                dfs1(id,G,used1,parent);
            }else{
                
                for(ll i=1;i<=n;i++){
                	vl[i] = 1;
                }
                
                
                dfs1(id,G,used1,parent);
                
            }
            
            
            
            
            for(ll i=1;i<=n;i++){
                cout<<vl[i]<<" ";
            }
            
            
        }else{
            cout<<"3";cout<<"\n";
            queue <ll> q ;
            q.push(1) ;
            ll used2[n+5] = {0};ll c = 0; 
            used2[1] = 1 ; 
            while(!q.empty()){
            	ll v = q.front(); c++;
            	if(c<=k){vl[v] = 1 ; }
            	q.pop(); 
            	for(auto u : G[v]){
            		if(used2[u]==0){
            			q.push(u);
            			used2[u] = 1 ; 
            		}
            		
            	}
            }  
            
            
            
            
            for(ll i=1;i<=n;i++){
                cout<<vl[i]<<" ";
            }
        }
    }
    cout<<"\n";    
        
        
        
        
    }
    
    
    return 0;
}