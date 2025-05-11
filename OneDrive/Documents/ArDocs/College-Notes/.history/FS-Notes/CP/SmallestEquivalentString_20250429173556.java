





















import java.util.*;

public class SmallestEquivalentString {
    static int[] parent = new int[26];

    // Initialize the parent to point to itself
    static void makeSet() {
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
    }

    static int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }

    static void union(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return;
        // Always keep the smaller one as the parent
        if (px < py) {
            parent[py] = px;
        } else {
            parent[px] = py;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String A = sc.next();
        String B = sc.next();
        String T = sc.next();

        makeSet();  // initialize DSU

        for (int i = 0; i < A.length(); i++) {
            union(A.charAt(i) - 'a', B.charAt(i) - 'a');
        }

        StringBuilder result = new StringBuilder();
        for (char ch : T.toCharArray()) {
            char smallest = (char)(find(ch - 'a') + 'a');
            result.append(smallest);
        }

        System.out.println(result.toString());
    }
}
