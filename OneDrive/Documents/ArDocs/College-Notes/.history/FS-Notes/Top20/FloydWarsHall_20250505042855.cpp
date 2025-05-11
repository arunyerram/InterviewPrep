#include<bits/stdc++.h>

using namespace std;

#define long long int ll;





// floyd WarsHall .....

// 1. The Floyd-Warshall algorithm is a dynamic programming algorithm used to find the shortest paths in a weighted graph with positive or negative edge weights (but with no negative cycles).

    
    
class Solution {
    public:
      void floydWarshall(vector<vector<int>> &dist) {
          // Code here
          int n = dist.size();
          for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                  for(int k=0;k<n;k++){
                      if(dist[j][i] != 1e8 && dist[i][k] != 1e8){
                          dist[j][k] = min(dist[j][k],dist[j][i]+dist[i][k]);
                      }
                  }
              }
          }
      }


  };
