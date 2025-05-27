import java.util.*;

class ArticulationPoint {
    static int time;  // global discovery time counter

    // Add an undirected edge between u and v
    static void addEdge(ArrayList<ArrayList<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    // DFS utility to find articulation points
    static void APUtil(ArrayList<ArrayList<Integer>> adj, int u,
                       boolean[] visited, int[] disc, int[] low,
                       int parent, boolean[] isAP) {
        int children = 0;
        visited[u] = true;
        disc[u] = low[u] = ++time;

        for (int v : adj.get(u)) {
            if (!visited[v]) {
                children++;
                APUtil(adj, v, visited, disc, low, u, isAP);

                // Update low value
                low[u] = Math.min(low[u], low[v]);

                // If u is not root and low[v] ≥ disc[u], u is an articulation point
                if (parent != -1 && low[v] >= disc[u])
                    isAP[u] = true;
            }
            else if (v != parent) {
                // Back edge
                low[u] = Math.min(low[u], disc[v]);
            }
        }

        // If u is root and has two or more children, it's an articulation point
        if (parent == -1 && children > 1)
            isAP[u] = true;
    }

    // Finds and prints all articulation points in the graph
    static void AP(ArrayList<ArrayList<Integer>> adj, int V) {
        boolean[] visited = new boolean[V];
        int[] disc = new int[V];
        int[] low  = new int[V];
        boolean[] isAP = new boolean[V];
        time = 0;

        // Handle disconnected graph
        for (int u = 0; u < V; u++) {
            if (!visited[u])
                APUtil(adj, u, visited, disc, low, -1, isAP);
        }

        System.out.println("Articulation points in the graph:");
        for (int u = 0; u < V; u++) {
            if (isAP[u])
                System.out.print(u + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("enter number of vertices ");
        int V = sc.nextInt();
        System.out.println("enter number of edges");
        int E = sc.nextInt();

        ArrayList<ArrayList<Integer>> adj = new ArrayList<>(V);
        for (int i = 0; i < V; i++)
            adj.add(new ArrayList<>());

        System.out.println("enter edges (u v):");
        for (int i = 0; i < E; i++) {
            int u = sc.nextInt(), v = sc.nextInt();
            addEdge(adj, u, v);
        }

        AP(adj, V);
        sc.close();
    }
}
