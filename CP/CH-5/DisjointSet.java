import java.util.*;

public class DisjointSet {
    private int[] parent;
    private int[] size;

    // Initialize n singleton sets: 0, 1, ..., n-1
    public DisjointSet(int n) {
        parent = new int[n];
        size   = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;   // each element is its own parent
            size[i]   = 1;   // initial size is 1
        }
    }

    // Find the representative (root) of the set containing x
    public int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // path compression
        }
        return parent[x];
    }

    // Merge the sets containing x and y
    public void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) {
            return;  // already in the same set
        }
        // Union by size: attach smaller tree under larger
        if (size[rootX] < size[rootY]) {
            parent[rootX] = rootY;
            size[rootY]  += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX]  += size[rootY];
        }
    }

    // Example usage
    public static void main(String[] args) {
        DisjointSet ds = new DisjointSet(5);
        ds.union(0, 1);
        ds.union(1, 2);
        ds.union(3, 4);

        System.out.println("Component of 2: " + ds.find(2)); // same as find(0) => root
        System.out.println("Component of 4: " + ds.find(4)); // same as find(3)
        // Check if 2 and 3 are connected
        System.out.println("2 and 3 connected? " + 
            (ds.find(2) == ds.find(3)));
    }
}
