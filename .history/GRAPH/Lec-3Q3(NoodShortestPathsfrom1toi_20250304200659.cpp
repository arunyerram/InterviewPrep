#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll ; 
 
 
 
int main() {
 
    ll n ; 
    cin>>n ; 
    //taking input --> size of graph 
 
    ll m ; 
    //taking input --> number of edges in the graph 
    cin>>m ; 
 
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
 
    q.push(1) ; //pushing the source node = 1 in the queue  
 
    ll used[n+5] = {0}; //declaring an empty used array where in used[i] = 0 means this node has not yet been visited in our algorithm
    ll ways[n+5] = {0};
    used[1] = 1 ; //1st node has been visited hence setting is as 1 and it is inserted in the queue as well jiiiiii
    ll lvl[n+5] = {0}; //declaring level array this basically lets us know level of each node jiiiii 
    lvl[1] = 0 ; //lvl of 1st node which we mean the source node is 0 as we start from here jiiiiiiii
    ways[1] = 1 ; 
 
 
    while(!q.empty()){
        //BFS Algo 
 
        ll v = q.front(); //top most element of queue jii
        cout<<v<<" "<<ways[v]; //printing that node with its number of ways to visit 
        cout<<"\n";
        q.pop(); //popping out the top most element of the queue jii........ 
 
        for(auto u : G[v]){
            //this simply means you'r iterating through all nodes connected to node v 
            if(used[u]==0){
 
                //if the node u(node connected to v) has never been visited before then lets visit it jiii
                q.push(u);
                used[u] = 1 ; //it has now been visited hence setting its values as 1 
                lvl[u] = lvl[v] + 1 ; //lvl[u] will be 1 greater than lvl[1] as we move 1 step forward from u to v jiii 
                ways[u] = ways[u] + ways[v] ; 
            } 
            else {
                if(lvl[v]+1==lvl[u]){
                    ways[u] = ways[u] + ways[v] ; 
                }
            }
        }
    }
    return 0 ; 
}