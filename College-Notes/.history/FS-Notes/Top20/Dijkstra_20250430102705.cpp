#include<bits/stdc++.h>
using namespace std;
#define long long int ll;
// Dijkstra's Algorithm to find the shortest path from a source node to all other nodes in a weighted graph

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
    vector<int> ans(V, INT_MAX);
    vector<vector<pair<int, int>>> adj(V);

    // Build the adjacency list
    for (auto it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    ans[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int nd = it.second;
        int wgt = it.first;
        
        for (auto i : adj[nd]) {
            if (wgt + i.second < ans[i.first]) {
                ans[i.first] = wgt + i.second;
                pq.push({ans[i.first], i.first});
            }
        }
    }
    return ans;
}
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>> pq; 
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        pq.insert({0,S});
        
        while(!pq.empty()){
            auto it = *(pq.begin());
            int d=it.first;
            int node=it.second;
            pq.erase(it);
            
            for(auto it:adj[node]){
                int wt=it[1];
                int adjnode=it[0];
                
                if( d+wt < dist[adjnode] ){
                    if(dist[adjnode] == INT_MAX)
                        pq.erase({dist[adjnode],adjnode});
                    dist[adjnode]=d+wt;
                    pq.insert({d+wt,adjnode});
                }
            }
            
        }
        return dist;   
    }
int main(){

    int V = 5; // Number of vertices
    vector<vector<int>> edges = { {0, 1, 2}, {0, 2, 4}, {1, 2, 1}, {1, 3, 7}, {2, 3, 3}, {3, 4, 1} };
    int src = 0; // Source node

    vector<int> result = dijkstra(V, edges, src);

    cout << "Shortest distances from source node " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": " << result[i] << endl;
    }
    return 0;
}