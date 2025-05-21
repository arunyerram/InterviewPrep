import java.util.*;

public class RottingOranges {
    static int[][] directions = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0}
    };

    public static void bfs(int i, int j, int m, int n, int[][] arr, boolean[][] vis, int[][] help) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{i, j, 0});
        vis[i][j] = true;

        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int x = cell[0], y = cell[1], cost = cell[2];

            for (int[] dir : directions) {
                int ni = x + dir[0], nj = y + dir[1];

                if (ni >= 0 && nj >= 0 && ni < m && nj < n && !vis[ni][nj] && arr[ni][nj] == 1 && help[ni][nj] > cost + 1) {
                    help[ni][nj] = cost + 1;
                    vis[ni][nj] = true;
                    queue.add(new int[]{ni, nj, cost + 1});
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();

        int[][] arr = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        int[][] help = new int[m][n];
        for (int[] row : help) {
            Arrays.fill(row, Integer.MAX_VALUE);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] != 1){
                    help[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 2) {
                    boolean[][] vis = new boolean[m][n];
                    bfs(i, j, m, n, arr, vis, help);
                }
            }
        }

        int mn = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 1) {
                    mn = Math.max(mn, help[i][j]);
                }
            }
        }

        System.out.println(mn != Integer.MAX_VALUE ? mn : -1);
        sc.close();
    }
}
