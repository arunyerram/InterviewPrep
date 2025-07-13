import java.util.*;

class ConnectedComponents {
    private int[] parent;
    private int[] size;

    // Initialize n singleton sets
    public ConnectedComponents(int n) {
        parent = new int[n];
        size   = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = -1;   // means it's its own root with negative size
            size[i]   = 1;
        }
    }

    // Find root of i (no path compression in this example)
    private int find(int i) {
        while (parent[i] >= 0) {
            i = parent[i];
        }
        return i;
    }

    // Merge sets containing u and v
    public boolean union(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru == rv) return false;  // already connected

        // Union by size: attach smaller tree under larger
        if (size[ru] < size[rv]) {
            parent[ru] = rv;
            size[rv] += size[ru];
        } else {
            parent[rv] = ru;
            size[ru] += size[rv];
        }
        return true;
    }

    // Count connected components given edge list
    public int countComponents(int[][] edges) {
        int components = parent.length;
        for (int[] e : edges) {
            if (union(e[0], e[1])) {
                components--;
            }
        }
        return components;
    }

    // Example usage
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] edges = new int[m][2];
        for (int i = 0; i < m; i++) {
            edges[i][0] = sc.nextInt();
            edges[i][1] = sc.nextInt();
        }
        ConnectedComponents cc = new ConnectedComponents(n);
        System.out.println(cc.countComponents(edges));
        sc.close();
    }
}



