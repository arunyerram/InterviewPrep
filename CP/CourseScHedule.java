import java.util.*;

public class CourseScHedule {
    /**
     * Returns true if you can finish all numCourses given the prerequisite pairs.
     * Also prints one valid order to take the courses (if possible).
     */
    public static boolean canFinish(int numCourses, int[][] prerequisites) {
        // adjacency matrix: adjList[v][u] = 1 means an edge v→u (v must be taken before u)
        int[][] adjList = new int[numCourses][numCourses];
        int[] inDegree = new int[numCourses];

        // Build the graph and in-degree array
        for (int[] pre : prerequisites) {
            int course = pre[0], prereq = pre[1];
            adjList[prereq][course] = 1;
            inDegree[course]++;
        }

        // Enqueue all courses with no prerequisites
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                queue.offer(i);
            }
        }

        int count = 0;
        int[] order = new int[numCourses];
        int idx = 0;

        // Kahn’s algorithm
        while (!queue.isEmpty()) {
            int u = queue.poll();
            order[idx++] = u;
            count++;
            // “Remove” u by decreasing in-degree of its neighbors
            for (int v = 0; v < numCourses; v++) {
                if (adjList[u][v] == 1 && --inDegree[v] == 0) {
                    queue.offer(v);
                }
            }
        }

        // If we were able to take all courses, print the order and return true
        if (count == numCourses) {
            for (int i = 0; i < count; i++) {
                System.out.print(order[i] + " ");
            }
            System.out.println();
            return true;
        }
        // Otherwise there is a cycle, so it’s impossible
        return false;
    }

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        // nc = number of courses, c = number of prerequisite pairs
        int nc = s.nextInt(), c = s.nextInt();
        int[][] prereq = new int[c][2];
        for (int i = 0; i < c; i++) {
            prereq[i][0] = s.nextInt();
            prereq[i][1] = s.nextInt();
        }
        s.close();

        System.out.println(canFinish(nc, prereq));
    }
}
