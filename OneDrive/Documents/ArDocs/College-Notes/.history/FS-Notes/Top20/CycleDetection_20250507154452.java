import java.util.*;

public class CycleDetection {

    static class Pair {
        int node;
        int parent;

        Pair(int node, int parent) {
            this.node = node;
            this.parent = parent;
        }
    }

    public static boolean hasCycle(int V, List<List<Integer>> adj, int src) {
        boolean[] visited = new boolean[V];
        Queue<Pair> queue = new LinkedList<>();

        visited[src] = true;
        queue.offer(new Pair(src, -1));

        while (!queue.isEmpty()) {
            Pair current = queue.poll();

            for (int neighbor : adj.get(current.node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.offer(new Pair(neighbor, current.node));
                } else if (neighbor != current.parent) {
                    return true; // Cycle found
                }
            }
        }
        
        return false;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int V = sc.nextInt(); // Number of vertices
        int E = sc.nextInt(); // Number of edges

        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) adj.add(new ArrayList<>());

        for (int i = 0; i < E; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v);
            adj.get(v).add(u); // Undirected graph
        }

        int src = sc.nextInt(); // Source node

        if (hasCycle(V, adj, src)) {
            System.out.println("Cycle detected");
        } else {
            System.out.println("No cycle");
        }
    }
}
