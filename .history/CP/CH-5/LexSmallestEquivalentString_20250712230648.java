import java.util.*;

public class LexSmallestEquivalentString {
    // Inner DSU class
    private static class UnionFind {
        private final int[] parent;

        // Initialize n singleton sets (here, n = 26 for 'a'–'z')
        UnionFind(int n) {
            parent = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        // Path-compressed find: returns the root (smallest letter) of i
        int find(int i) {
            if (parent[i] != i) {
                parent[i] = find(parent[i]);
            }
            return parent[i];
        }

        // Union by choosing the smaller root as parent
        void union(int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra == rb) return;
            if (ra < rb) {
                parent[rb] = ra;
            } else {
                parent[ra] = rb;
            }
        }
    }

    // Main API: returns the lexicographically smallest equivalent of baseStr
    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        UnionFind uf = new UnionFind(26);
        // Merge equivalence classes
        for (int i = 0; i < s1.length(); i++) {
            uf.union(s1.charAt(i) - 'a', s2.charAt(i) - 'a');
        }
        // Build result using each character’s smallest representative
        StringBuilder sb = new StringBuilder();
        for (char c : baseStr.toCharArray()) {
            int root = uf.find(c - 'a');
            sb.append((char) (root + 'a'));
        }
        return sb.toString();
    }

    // Example driver
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String A = sc.next(), B = sc.next(), T = sc.next();
        System.out.println(new LexSmallestEquivalentString()
                                .smallestEquivalentString(A, B, T));
        sc.close();
    }
}
