

import java.util.*;
import java.util.LinkedList;

class FindingBridges {
    private int V;               // Number of vertices
    private LinkedList<Integer> adj[]; 
    private int time = 0;        // Time counter for discovery times
    static final int NIL = -1;    // Sentinel for no parent

    @SuppressWarnings("unchecked")
    FindingBridges(int v) {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i)
            adj[i] = new LinkedList<>();
    }

    // Add an undirected edge src–dest
    void addEdge(int src, int dest) {
        adj[src].add(dest);
        adj[dest].add(src);
    }


    PriorityQueue<int[]>pq = new PriorityQueue<>(Comparator.comparingInt((a,b) -> Integer.compare(b[0],a[0])));
    // List<Integer>dist = new ArrayList<>(n,Integer.MAX_VALUE); 
    int[] dist = new int[n];
    for(int i=0;i<n;i ){
        dist[i] = 
    }
    // DFS utility that finds bridges using discovery and low times
    void bridgeUtil(int u, boolean visited[], int disc[], int low[], int parent[]) {
        visited[u] = true;
        disc[u] = low[u] = ++time;

        for (int v : adj[u]) {
            if (!visited[v]) {
                parent[v] = u;
                bridgeUtil(v, visited, disc, low, parent);
                low[u] = Math.min(low[u], low[v]);

                // If the lowest vertex reachable from v is after u's discovery,
                // then edge u–v is a bridge
                if (low[v] > disc[u]) {
                    System.out.println(u + " " + v);
                }
            }
            else if (v != parent[u]) {
                // Update low[u] for a back edge
                low[u] = Math.min(low[u], disc[v]);
            }
        }
    }

    // Finds and prints all bridges
    void bridge() {
        boolean visited[] = new boolean[V];
        int disc[]   = new int[V];
        int low[]    = new int[V];
        int parent[] = new int[V];

        // Initialize parents and visited[]
        for (int i = 0; i < V; i++) {
            parent[i] = NIL;
            visited[i] = false;
        }

        // Call the recursive helper for each component
        for (int i = 0; i < V; i++) {
            if (!visited[i])
                bridgeUtil(i, visited, disc, low, parent);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter number of vertices ");
        int v = sc.nextInt();
        System.out.println("enter number of  edges");
        int e = sc.nextInt();

        FindingBridges g = new FindingBridges(v);
        System.out.println("enter edges");
        for (int i = 0; i < e; i++) {
            int src  = sc.nextInt();
            int dest = sc.nextInt();
            g.addEdge(src, dest);
        }

        System.out.println("Bridges in graph");
        g.bridge();
        sc.close();
    }
}
