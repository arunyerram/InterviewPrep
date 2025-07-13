

import java.util.*;

public class MaxFlow {
    static int V; // number of vertices in the graph

    // Returns maximum flow from source to sink in the given graph
    static int findMaxFlow(int[][] graph, int source, int sink) {
        // Create residual graph and fill with initial capacities
        int[][] residualGraph = new int[V][V];
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                residualGraph[i][j] = graph[i][j];
            }
        }
        int[] parent = new int[V];  // to store augmenting path
        int maxFlow = 0;            // there is no flow initially

        // Augment the flow while there is a path from source to sink
        while (bfs(residualGraph, source, sink, parent)) {
            // Find minimum residual capacity (bottleneck) along the path filled by BFS
            int pathFlow = Integer.MAX_VALUE;
            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                pathFlow = Math.min(pathFlow, residualGraph[u][v]);
            }
            // update residual capacities of the edges and reverse edges
            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                residualGraph[u][v] -= pathFlow;
                residualGraph[v][u] += pathFlow;
            }
            maxFlow += pathFlow;
        }
        return maxFlow;
    }

    // Returns true if there is a path from source to sink in residual graph
    static boolean bfs(int[][] residualGraph, int source, int sink, int[] parent) {
        boolean[] visited = new boolean[V];
        Arrays.fill(visited, false);
        Queue<Integer> queue = new LinkedList<>();
        queue.add(source);
        visited[source] = true;
        parent[source] = -1;

        while (!queue.isEmpty()) {
            int u = queue.poll();
            for (int v = 0; v < V; v++) {
                if (!visited[v] && residualGraph[u][v] > 0) {
                    queue.add(v);
                    parent[v] = u;
                    visited[v] = true;
                }
            }
        }
        // If we reached sink in BFS starting from source, return true
        return visited[sink];
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter number of vertices");
        V = s.nextInt();
        int[][] graph = new int[V][V];
        System.out.println("Enter the adjacency matrix of the directed graph");
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                graph[i][j] = s.nextInt();
        System.out.println("Enter source and sink");
        int source = s.nextInt();
        int sink = s.nextInt();

        int maxFlow = findMaxFlow(graph, source, sink);
        System.out.println("The maximum possible flow is " + maxFlow);
        s.close();
    }
}
