#include<bits/stdc++.h>

using namespace std;

#define long long int ll;

// Bellman-Ford Algorithm to find the shortest path from a source node to all other nodes in a weighted graph
// Time Complexity: O(V*E), where V is the number of vertices and E is the number of edges


// Space Complexity: O(V), where V is the number of vertices

// The space complexity is O(V) because we are using a distance array of size V to store the shortest distances from the source node to all other nodes.    

// The time complexity is O(V*E) because we are iterating through all the edges V-1 times to relax them. In the worst case, we may have to check all edges for each vertex.

// 
// The Bellman-Ford algorithm is capable of handling graphs with negative weights and can also detect negative weight cycles.

// If a negative weight cycle is detected, the algorithm will return an empty vector to indicate that no solution exists.
// If no negative weight cycle is detected, the algorithm will return the shortest distances from the source node to all other nodes.

// The Bellman-Ford algorithm is a single-source shortest path algorithm that can handle graphs with negative weights and detect negative weight cycles.
// It works by relaxing all edges V-1 times, where V is the number of vertices in the graph. The algorithm can also detect negative weight cycles by checking if any edge can still be relaxed after V-1 iterations.

// The algorithm is slower than Dijkstra's algorithm for graphs with non-negative weights, but it is more versatile and can handle a wider range of graphs.
// The Bellman-Ford algorithm is a single-source shortest path algorithm that can handle graphs with negative weights and detect negative weight cycles. It works by relaxing all edges V-1 times, where V is the number of vertices in the graph. The algorithm can also detect negative weight cycles by checking if any edge can still be relaxed after V-1 iterations.

// The algorithm is slower than Dijkstra's algorithm for graphs with non-negative weights, but it is more versatile and can handle a wider range of graphs.

// The Bellman-Ford algorithm is a single-source shortest path algorithm that can handle graphs with negative weights and detect negative weight cycles. It works by relaxing all edges V-1 times, where V is the number of vertices in the graph. The algorithm can also detect negative weight cycles by checking if any edge can still be relaxed after V-1 iterations.

// The algorithm is slower than Dijkstra's algorithm for graphs with non-negative weights, but it is more versatile and can handle a wider range of graphs.

// The Bellman-Ford algorithm is a single-source shortest path algorithm that can handle graphs with negative weights and detect negative weight cycles. It works by relaxing all edges V-1 times, where V is the number of vertices in the graph. The algorithm can also detect negative weight cycles by checking if any edge can still be relaxed after V-1 iterations.
// The algorithm is slower than Dijkstra's algorithm for graphs with non-negative weights, but it is more versatile and can handle a wider range of graphs.


// The Bellman-Ford algorithm is a single-source shortest path algorithm that can handle graphs with negative weights and detect negative weight cycles. It works by relaxing all edges V-1 times, where V is the number of vertices in the graph. The algorithm can also detect negative weight cycles by checking if any edge can still be relaxed after V-1 iterations.
// The algorithm is slower than Dijkstra's algorithm for graphs with non-negative weights, but it is more versatile and can handle a wider range of graphs.
// The Bellman-Ford algorithm is a single-source shortest path algorithm that can handle graphs with negative weights and detect negative weight cycles. It works by relaxing all edges V-1 times, where V is the number of vertices in the graph. The algorithm can also detect negative weight cycles by checking if any edge can still be relaxed after V-1 iterations.  






public int[] bellmanFord(int V, int[][] edges, int src) {
    // code here
    int[] dist = new int[V];
    // Arrays.fill(dist,1e8);
    for(int i=0;i<V;i++)
        dist[i] = (int)1e8;
    dist[src] = 0;
    for(int i=0;i<V;i++){
        for(int[] it:edges){
            int u = it[0];
            int v = it[1];
            int c = it[2];
            
            // if(i == V-1)return new int[]{-1}; 
            if(dist[u] != (int)1e8 && (dist[u] + c) < dist[v]){
                if(i == V-1){
                    int[] t = new int[1];
                    t[0] = -1;
                    return t;
                }
                dist[v] = dist[u] + c;
            }
        }
    }