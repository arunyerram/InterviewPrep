



import java.util.*;

class ConnectedComponents {
    // Number of vertices
    int V;

    // Adjacency list
    ArrayList<ArrayList<Integer>> adjListArray;

    // Constructor
    ConnectedComponents(int V) {
        this.V = V;
        adjListArray = new ArrayList<>();

        // Initialize adjacency list for each vertex
        for (int i = 0; i < V; i++) {
            adjListArray.add(new ArrayList<>());
        }
    }

    // Adds an edge to the undirected graph
    void addEdge(int src, int dest) {
        adjListArray.get(src).add(dest);
        adjListArray.get(dest).add(src);
    }

    // DFS traversal for a component
    void DFSUtil(int v, boolean[] visited) {
        visited[v] = true;
        System.out.print(v + " ");

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
                DFSUtil(v, visited);
                System.out.println();
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of vertices: ");
        int v = sc.nextInt();

        System.out.print("Enter number of edges: ");
        int e = sc.nextInt();

        ConnectedComponents g = new ConnectedComponents(v);

        System.out.println("Enter edges (src dest):");
        for (int i = 0; i < e; i++) {
            int end1 = sc.nextInt();
            int end2 = sc.nextInt();
            g.addEdge(end1, end2);
        }

        System.out.println("Following are connected components:");
        g.connectedComponents();
    }
}


