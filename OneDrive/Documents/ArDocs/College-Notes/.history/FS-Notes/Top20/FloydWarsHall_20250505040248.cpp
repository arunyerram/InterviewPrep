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
    
    for(int i=1;i<=n;i++){
        dist[i][i]=0;
    }
    
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}