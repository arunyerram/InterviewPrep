

// Program to implement Disjoint Set Data Structure.

/*
5 = number of friends
3 = number of relationships
2 = number of friendship check
input=5
3
0 2
4 2
3 1
2
4 0
1 0
output=4 is a friend of 0
1 is not a friend of 0

*/

import java.util.*;

class DisjointUnionSets {
    int[] rank, parent;
    int n;

    public DisjointUnionSets(int n) {
        rank = new int[n];
        parent = new int[n];
        this.n = n;
        makeSet();

}

    // Creates n sets with single item in each
    void makeSet() {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
}
    // Returns representative of x's set with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
}
        return parent[x];
    }
    // Unites the sets that include x and y using union by rank
    void union(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if (xRoot == yRoot) return;
        // Attach smaller rank tree under root of higher rank tree
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot
} else if (rank[yRoot] < rank[xRoot]) {
            parent[yRoot] = xRoot;
} else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
}

public class test {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(); 
        int r = sc.nextInt(); // Number of relationships

        DisjointUnionSets dus = new DisjointUnionSets(n);
        for (int i = 0; i < r; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            dus.union(a, b);
        }
        int q = sc.nextInt();
        for (int i = 0; i < q; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            if (dus.find(x) == dus.find(y)) {
                System.out.println(x + " is a friend of " + y);
} else {
                System.out.println(x + " is not a friend of " + y);
            }
        }
    }
}