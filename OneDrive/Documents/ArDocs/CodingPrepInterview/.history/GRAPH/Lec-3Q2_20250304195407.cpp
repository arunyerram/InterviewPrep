#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll ; 
 
 
 
int main() {
 
    ll n,m; 
    cin>>n>>m; 
    //taking input --> size of graph and number of edges in the graph 
 
    
 
    vector <ll> G[n+5]; //constructing a graph using adjacency list 
 
    ll i = 1 ; 
    while(i<=m){
 
        ll u,v ; 
        cin>>u>>v ; //reading the number of edges in the graph 
        G[u].push_back(v);
        G[v].push_back(u);
        //making un directed graph jii 
        i++;
    }
 
 
    queue <ll> q ; //declaring a queue  
    ll source ;
	cin>>source;
    q.push(source) ; //pushing the source node in the queue  
 
    ll used[n+5] = {0}; //declaring an empty used array where in used[i] = 0 means this node has not yet been visited in our algorithm
    used[source] = 1 ; //source node has been visited hence setting it = 1 and it is inserted in the queue as well jiiiiii
    ll lvl[n+5] = {0}; //declaring level array this basically lets us know level of each node jiiiii 
    lvl[source] = 0 ; //lvl of source node which we mean the source node is 0 as we start from here jiiiiiiii
 
    while(!q.empty()){
        //BFS Algo 
 
        ll v = q.front(); //top most element of queue jii
        
        q.pop(); //popping out the top most element of the queue jii........ 
 
        for(auto u : G[v]){
            //this simply means you'r iterating through all nodes connected to node v 
            if(used[u]==0){
 
                //if the node u(node connected to v) has never been visited before then lets visit it jiii
                q.push(u);
                used[u] = 1 ; //it has now been visited hence setting its values as 1 
                lvl[u] = lvl[v] + 1 ; //lvl[u] will be 1 greater than lvl[1] as we move 1 step forward from u to v jiii 
            } 
            
 
        }

    }

	i = 1 ; 
	while(i<=n){
		if(used[i]==0){
		    cout<<"You cannot visit the node "<<i<<" from the source node = "<<source ; 
		}
		else {
		    cout<<"You can visit the node "<<i<<" from the source node = "<<source ;
		}
		
		
		cout<<'\n';
		i++;
	}
 
    return 0 /*RR*/ ; 
}