
import java.io.*;
import java.util.*;

class FindingBridges {
    private int V;                     // Number of vertices
    private LinkedList<Integer> adj[]; // Adjacency list
    private int time = 0;
    static final int NIL = -1;

    @SuppressWarnings("unchecked")
    FindingBridges(int v) {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i)
            adj[i] = new LinkedList<>();
    }

    // Add undirected edge u–v
    void addEdge(int u, int v) {
        adj[u].add(v);
        adj[v].add(u);
    }

    // DFS utility to find bridges
    void bridgeUtil(int u, boolean visited[], int disc[], int low[], int parent[]) {
        visited[u] = true;
        disc[u] = low[u] = ++time;

        for (int v : adj[u]) {
            // If v is not yet visited, explore it
            if (!visited[v]) {
                parent[v] = u;
                bridgeUtil(v, visited, disc, low, parent);

                // Update low[u] based on subtree
                low[u] = Math.min(low[u], low[v]);

                // If no back-edge from v or its descendants to u or ancestors, it's a bridge
                if (low[v] > disc[u])
                    System.out.println(u + " " + v);
            }
            // Update low[u] for back-edge
            else if (v != parent[u]) {
                low[u] = Math.min(low[u], disc[v]);
            }
        }
    }

    // Finds and prints all bridges
    void bridge() {
        boolean visited[] = new boolean[V];
        int disc[]    = new int[V];
        int low[]     = new int[V];
        int parent[]  = new int[V];

        // Initialize
        for (int i = 0; i < V; i++) {
            visited[i] = false;
            parent[i]  = NIL;
        }

        // Call DFS for each unvisited vertex
        for (int i = 0; i < V; i++)
            if (!visited[i])
                bridgeUtil(i, visited, disc, low, parent);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter number of vertices ");
        int v = sc.nextInt();
        System.out.println("enter number of edges");
        int e = sc.nextInt();

        FindingBridges g = new FindingBridges(v);
        System.out.println("enter edges");
        for (int i = 0; i < e; i++) {
            int u = sc.nextInt(), w = sc.nextInt();
            g.addEdge(u, w);
        }

        System.out.println("Bridges in graph");
        g.bridge();
    }
}

