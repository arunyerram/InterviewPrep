#include<bits/stdc++.h>

using namespace std;

#define long long int ll;





// floyd WarsHall .....

// 1. The Floyd-Warshall algorithm is a dynamic programming algorithm used to find the shortest paths in a weighted graph with positive or negative edge weights (but with no negative cycles).

    

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> dist(n+1,vector<int>(n+1,INT_MAX));
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        dist[u][v]=w;
        dist[v][u]=w;
    }
    
    return 0;
}