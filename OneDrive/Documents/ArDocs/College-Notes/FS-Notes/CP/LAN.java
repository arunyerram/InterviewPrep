// In your computer lab, network switches are connected using Ethernet cables to form a LAN. 
// However, a new hardware technician inadvertently connected switches in a way that created a cycle,
// resulting in a network loop. 
// As a consequence, the network has become unstable. You need to identify and remove the specific cable that 
// is causing the loop. 
// If there are multiple cables contributing to the loop, you should remove the one that was most recently added

// Sample Input-1:
// ---------------
// 3
// 0 1
// 0 2
// 1 2

// Sample Output-1:
// ----------------
// [1 2]

// Sample Input-2:
// ---------------
// 5
// 0 1
// 1 2
// 2 3
// 0 3
// 0 4

// Sample Output-2:
// ----------------
// [0,3]
 

// Constraints:
// ------------
// -> n == edges.length
// -> 3 <= n <= 1000
// -> edges[i].length == 2
// -> 1 <= ai < bi <= edges.length
// -> ai != bi
// -> There are no repeated edges.
// -> The given graph is connected.



import java.util.*;

public class LAN {

    static class DisjointSet {
        int[] parent;

        DisjointSet(int n) {
            parent = new int[n + 1];
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }

        int find(int u) {
            if (parent[u] != u)
                parent[u] = find(parent[u]); 
            return parent[u];
        }

        boolean union(int u, int v) {
            int pu = find(u);
            int pv = find(v);
            if (pu == pv)
                return false;
            parent[pv] = pu;
            return true;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] edges = new int[n][2];
        int maxNode = 0;

        for (int i = 0; i < n; i++) {
            edges[i][0] = sc.nextInt();
            edges[i][1] = sc.nextInt();
            maxNode = Math.max(maxNode, Math.max(edges[i][0], edges[i][1]));
        }

        DisjointSet ds = new DisjointSet(maxNode);

        for (int[] edge : edges) {
            if (!ds.union(edge[0], edge[1])) {
                System.out.println("[" + edge[0] + "," + edge[1] + "]");
                break;
            }
        }
    }
}
