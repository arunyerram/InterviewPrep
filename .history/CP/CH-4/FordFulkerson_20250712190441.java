package CH-4;

public import java.util.*;

public class FordFulkerson {
    static int V;

    // Returns maximum flow from source to sink in the given graph
    static int findMaxFlow(int[][] graph, int source, int sink) {
        int[][] residualGraph = new int[V][V];

        // Initialize residual graph
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                residualGraph[i][j] = graph[i][j];

        int[] parent = new int[V];
        int maxFlow = 0;

        // Augment the flow while there is a path using DFS
        while (dfs(residualGraph, source, sink, parent, new boolean[V])) {
            // Find bottleneck capacity
            int pathFlow = Integer.MAX_VALUE;
            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                pathFlow = Math.min(pathFlow, residualGraph[u][v]);
            }

            // Update residual capacities
            for (int v = sink; v != source; v = parent[v]) {
                int u = parent[v];
                residualGraph[u][v] -= pathFlow;
                residualGraph[v][u] += pathFlow;
            }

            maxFlow += pathFlow;
        }

        return maxFlow;
    }

    // DFS-based path finding
    static boolean dfs(int[][] residualGraph, int u, int sink, int[] parent, boolean[] visited) {
        visited[u] = true;

        if (u == sink)
            return true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && residualGraph[u][v] > 0) {
                parent[v] = u;
                if (dfs(residualGraph, v, sink, parent, visited))
                    return true;
            }
        }

        return false;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter number of vertices:");
        V = s.nextInt();

        int[][] graph = new int[V][V];
        System.out.println("Enter adjacency matrix (capacity matrix):");
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                graph[i][j] = s.nextInt();

        System.out.println("Enter source and sink:");
        int source = s.nextInt();
        int sink = s.nextInt();

        int maxFlow = findMaxFlow(graph, source, sink);
        System.out.println("The maximum possible flow is " + maxFlow);
        s.close();
    }
}
 {
    
}
