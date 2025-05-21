
import java.util.Arrays;

public class Bellmanford{

    public int[] bellmanFord(int V, int[][] edges, int src) {
        int[] dist = new int[V];
        Arrays.fill(dist, (int) 1e8);
        dist[src] = 0;

        for (int i = 0; i < V; i++) {
            for (int[] edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if (dist[u] != (int) 1e8 && dist[u] + wt < dist[v]) {
                    if (i == V - 1) {
                        // Negative weight cycle detected
                        return new int[]{-1};
                    }
                    dist[v] = dist[u] + wt;
                }
            }
        }

        return dist;
    }

    public static void main(String[] args) {
        Bellmanford bf = new Bellmanford();
        int V = 5;
        int[][] edges = {
            {0, 1, -1}, {0, 2, 4},
            {1, 2, 3}, {1, 3, 2},
            {1, 4, 2}, {3, 2, 5},
            {3, 1, 1}, {4, 3, -3}
        };
        int src = 0;

        int[] result = bf.bellmanFord(V, edges, src);

        if (result.length == 1 && result[0] == -1) {
            System.out.println("Negative weight cycle detected");
        } else {
            System.out.println("Shortest distances from source node " + src + ":");
            for (int i = 0; i < result.length; i++) {
                System.out.println("Node " + i + ": " + result[i]);
            }
        }
    }
}
