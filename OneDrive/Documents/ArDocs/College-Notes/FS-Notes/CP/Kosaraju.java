import java.util.*;

public class Kosaraju {
    private int V;
    private List<List<Integer>> adj;
    private List<List<Integer>> revAdj;

    public Kosaraju(int vertices) {
        V = vertices;
        adj = new ArrayList<>();
        revAdj = new ArrayList<>();
        
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
            revAdj.add(new ArrayList<>());
        }
    }

    public void addEdge(int v, int w) {
        adj.get(v).add(w);
        revAdj.get(w).add(v);
    }

    private void fillOrder(int v, boolean[] visited, Stack<Integer> stack) {
        visited[v] = true;
        
        for (int u : adj.get(v)) {
            if (!visited[u]) {
                fillOrder(u, visited, stack);
            }
        }
        stack.push(v);
    }

    private void DFSUtil(int v, boolean[] visited, List<Integer> component) {
        visited[v] = true;
        component.add(v);
        
        for (int u : revAdj.get(v)) {
            if (!visited[u]) {
                DFSUtil(u, visited, component);
            }
        }
    }

    public List<List<Integer>> findSCCs() {
        Stack<Integer> stack = new Stack<>();
        boolean[] visited = new boolean[V];
        List<List<Integer>> sccs = new ArrayList<>();

        // First DFS to fill the stack
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                fillOrder(i, visited, stack);
            }
        }

        // Reset visited array for second DFS
        Arrays.fill(visited, false);

        // Second DFS to find SCCs
        while (!stack.isEmpty()) {
            int v = stack.pop();

            if (!visited[v]) {
                List<Integer> component = new ArrayList<>();
                DFSUtil(v, visited, component);
                sccs.add(component);
            }
        }

        return sccs;
    }

    public static void main(String[] args) {
        // Example usage
        Kosaraju g = new Kosaraju(5);
        g.addEdge(1, 0);
        g.addEdge(0, 2);
        g.addEdge(2, 1);
        g.addEdge(0, 3);
        g.addEdge(3, 4);

        List<List<Integer>> sccs = g.findSCCs();

        System.out.println("Strongly Connected Components:");
        for (int i = 0; i < sccs.size(); i++) {
            System.out.print("Component " + (i + 1) + ": ");
            for (int v : sccs.get(i)) {
                System.out.print(v + " ");
            }
            System.out.println();
        }
    }
} 