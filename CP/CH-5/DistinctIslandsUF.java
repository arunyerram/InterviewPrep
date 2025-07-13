import java.util.*;

public class DistinctIslandsUF {
    private int[] size;      // size of each DSU tree
    private int[] parent;    // DSU parent pointers
    private int N, M;        // grid dimensions

    // DSU find with path compression
    public int find(int i) {
        while (parent[i] >= 0) {
            i = parent[i];
        }
        return i;
    }

    // DSU union by tree size
    public void union(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj) return;
        if (size[ri] < size[rj]) {
            size[rj] += size[ri];
            parent[ri] = rj;
        } else {
            size[ri] += size[rj];
            parent[rj] = ri;
        }
    }

    // Check if (x,y) is inside the grid
    private boolean inside(int x, int y) {
        return x >= 0 && y >= 0 && x < N && y < M;
    }

    // Main routine: count distinct island shapes
    public int numIslands(int[][] grid) {
        if (grid == null || grid.length == 0) return 0;
        N = grid.length;                  // rows
        M = grid[0].length;               // cols
        size   = new int[N * M];
        parent = new int[N * M];
        List<int[]> ones = new ArrayList<>();

        // Initialize DSU: each cell is its own root of size 1
        for (int i = 0; i < N * M; i++) {
            parent[i] = -1;
            size[i]   = 1;
        }

        // Union adjacent land cells and record their positions
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == 1) {
                    ones.add(new int[]{i, j});
                    int idx = i * M + j;
                    if (inside(i-1, j) && grid[i-1][j] == 1) union(idx, idx - M);
                    if (inside(i, j-1) && grid[i][j-1] == 1) union(idx, idx - 1);
                    if (inside(i+1, j) && grid[i+1][j] == 1) union(idx, idx + M);
                    if (inside(i, j+1) && grid[i][j+1] == 1) union(idx, idx + 1);
                }
            }
        }

        // Group cells by their DSU root
        HashMap<Integer, Queue<int[]>> map = new HashMap<>();
        for (int[] pos : ones) {
            int x = pos[0], y = pos[1];
            int root = find(x * M + y);
            map.computeIfAbsent(root, k -> new LinkedList<>()).add(pos);
        }

        // For each island, normalize its shape by translating
        // so that the smallest (x,y) becomes the origin (0,0).
        HashSet<String> shapes = new HashSet<>();
        for (Queue<int[]> queue : map.values()) {
            int[] origin = queue.peek();
            int ox = origin[0], oy = origin[1];
            StringBuilder shape = new StringBuilder();
            while (!queue.isEmpty()) {
                int[] cur = queue.remove();
                shape.append(cur[0] - ox)
                     .append(',')
                     .append(cur[1] - oy)
                     .append(';');
            }
            shapes.add(shape.toString());
        }

        // Number of distinct normalized shapes
        return shapes.size();
    }

    // Driver to read input and output the result
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt(), n = sc.nextInt();
        int[][] grid = new int[m][n];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                grid[i][j] = sc.nextInt();
        System.out.println(new DistinctIslandsUF().numIslands(grid));
        sc.close();
    }
}

