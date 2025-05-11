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

int main(){

    int V = 5; // Number of vertices
    vector<vector<int>> edges = { {0, 1, 2}, {0, 2, 4}, {1, 2, 1}, {1, 3, 7}, {2, 3, 3}, {3, 4, 1} };
    int src = 0; // Source node

    
    return 0;
}