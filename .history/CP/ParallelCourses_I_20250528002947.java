import java.util.*;

public class ParallelCourses_I{
    public int minimumSemesters(int n, int[][] relations) {
        List<Integer>[] g = new List[n];
        Arrays.setAll(g, k -> new ArrayList<>());
        int[] indeg = new int[n];

        // Build graph and in-degree array
        for (var r : relations) {
            int prev = r[0] - 1, nxt = r[1] - 1;
            g[prev].add(nxt);
            ++indeg[nxt];
        }

        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) q.offer(i);
        }

        int semesters = 0;
        while (!q.isEmpty()) {
            ++semesters;
            for (int k = q.size(); k > 0; --k) {
                int u = q.poll();
                --n;
                for (int v : g[u]) {
                    if (--indeg[v] == 0) {
                        q.offer(v);
                    }
                }
            }
        }
        return n == 0 ? semesters : -1;
    }
}
