
import java.util.*;

class ConnectedComponents {
    // Number of vertices
    private int V;
    // Adjacency list representation
    private ArrayList<ArrayList<Integer>> adjListArray;

    // Constructor
    ConnectedComponents(int V) {
        this.V = V;
        adjListArray = new ArrayList<>();
        // Initialize adjacency lists for all vertices
        for (int i = 0; i < V; i++) {
            adjListArray.add(new ArrayList<>());
        }
    }

    // Adds an undirected edge between src and dest
    void addEdge(int src, int dest) {
        adjListArray.get(src).add(dest);
        adjListArray.get(dest).add(src);
    }

    // Utility method for DFS traversal from a given vertex
    private void DFSUtil(int v, boolean[] visited) {
        visited[v] = true;
        System.out.print(v + " ");
        // Recur for all adjacent vertices
        for (int x : adjListArray.get(v)) {
            if (!visited[x]) {
                DFSUtil(x, visited);
            }
        }
    }

    // Prints all connected components
    void connectedComponents() {
        boolean[] visited = new boolean[V];
        for (int v = 0; v < V; ++v) {
            if (!visited[v]) {
                // Print all vertices in this component
                DFSUtil(v, visited);
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of vertices:");
        int v = sc.nextInt();
        System.out.println("Enter number of edges:");
        int e = sc.nextInt();

        ConnectedComponents g = new ConnectedComponents(v);
        System.out.println("Enter edges (src dest):");
        for (int i = 0; i < e; i++) {
            int src = sc.nextInt();
            int dest = sc.nextInt();
            g.addEdge(src, dest);
        }

        System.out.println("Following are connected components:");
        g.connectedComponents();
        sc.close();
    }
}















