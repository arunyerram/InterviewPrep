
import java.util.*;

public class Dijkstra{

    public static List<Integer> dijkstra(int V, List<List<Integer>> edges, int src) {
        // Create adjacency list
        List<List<int[]>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        for (List<Integer> edge : edges) {
            int u = edge.get(0), v = edge.get(1), wt = edge.get(2);
            adj.get(u).add(new int[]{v, wt});
            adj.get(v).add(new int[]{u, wt}); // If graph is undirected
        }

        int[] dist = new int[V];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.offer(new int[]{0, src});

        while (!pq.isEmpty()) {
            int[] top = pq.poll();
            int d = top[0];
            int node = top[1];

            for (int[] neighbor : adj.get(node)) {
                int adjNode = neighbor[0], weight = neighbor[1];
                if (d + weight < dist[adjNode]) {
                    dist[adjNode] = d + weight;
                    pq.offer(new int[]{dist[adjNode], adjNode});
                }
            }
        }

        List<Integer> result = new ArrayList<>();
        for (int d : dist) result.add(d);
        return result;
    }

    public static void main(String[] args) {
        int V = 5;
        List<List<Integer>> edges = Arrays.asList(
                Arrays.asList(0, 1, 2),
                Arrays.asList(0, 2, 4),
                Arrays.asList(1, 2, 1),
                Arrays.asList(1, 3, 7),
                Arrays.asList(2, 3, 3),
                Arrays.asList(3, 4, 1)
        );
        int src = 0;

        List<Integer> result = dijkstra(V, edges, src);

        System.out.println("Shortest distances from source node " + src + ":");
        for (int i = 0; i < result.size(); i++) {
            System.out.println("Node " + i + ": " + result.get(i));
        }
    }
}
