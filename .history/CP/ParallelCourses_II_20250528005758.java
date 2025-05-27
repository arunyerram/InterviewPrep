import java.util.*;

public class ParallelCourses_II {
    public int minimumSemesters(int numCourses, int[][] prerequisites, int maxCourses) {
        int[][] graph = new int[numCourses][numCourses];
        int[] indegree = new int[numCourses];

        // Build adjacency matrix and in-degree
        for (int[] pre : prerequisites) {
            int u = pre[0], v = pre[1];
            graph[u][v] = 1;
            indegree[v]++;
        }

        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) queue.offer(i);
        }

        int semesters = 0, coursesTaken = 0;
        while (!queue.isEmpty()) {
            int take = Math.min(queue.size(), maxCourses);
            for (int i = 0; i < take; i++) {
                int u = queue.poll();
                coursesTaken++;
                for (int v = 0; v < numCourses; v++) {
                    if (graph[u][v] == 1 && --indegree[v] == 0) {
                        queue.offer(v);
                    }
                }
            }
            semesters++;
        }
        return (coursesTaken != numCourses) ? -1 : semesters;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt(), c = s.nextInt();
        int[][] prereq = new int[c][2];
        for (int i = 0; i < c; i++) {88
            prereq[i][0] = s.nextInt();
            prereq[i][1] = s.nextInt();
        }
        int k = s.nextInt();
        System.out.println(new ParallelCourses_II().minimumSemesters(n, prereq, k));
    }
}
