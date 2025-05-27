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

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Read number of courses n and number of relations m
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] relations = new int[m][2];
        // Read each prerequisite pair (prevCourse, nextCourse)
        for (int i = 0; i < m; i++) {
            relations[i][0] = sc.nextInt();
            relations[i][1] = sc.nextInt();
        }
        sc.close();

        // Compute and output minimum semesters
        ParallelCourses_I solver = new ParallelCourses_I();
        int semesters = solver.minimumSemesters(n, relations);
        System.out.println(semesters);
    }
}
