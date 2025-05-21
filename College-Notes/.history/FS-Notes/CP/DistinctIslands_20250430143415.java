// Ibrahim is an interior designer wants to color wall of size M*N. 
// He plans to color the wall and put lights of two different colors

// The designer can lit the wall using M*N lights.The lights are Blue or pink
// in color. Blue colored lights represented with digit-1 and pink colored lights 
// represented with digit-0.

// The Blue colored lights forms different shapes, that are connected 4 directonally.
// The directons are upwards, downwards, left, and right. Ibrahim got an idea to 
// count the unique shapes formed by blue colored lights.

// You will be given the decorated wall as a matrix wall[][].
// Your task is to help Ibrahim to count the unique shapes by the lights.

// Input Format:
// -------------
// Line-1: Two space separated integers M and N, size of the wall.
// Next M lines: N space separated integers, either 0 or 1.

// Output Format:
// --------------
// Print an integer, Number of distinct shapes formed by Blue Lights.


// Sample Input-1:
// ---------------
// 4 5
// 1 1 0 1 1
// 1 1 0 0 1
// 0 0 0 0 0
// 1 1 0 0 0

// Sample Output-1:
// ----------------
// 3


// Sample Input-2:
// ---------------
// 5 5
// 1 1 0 1 1
// 1 0 0 0 1
// 0 0 0 0 0
// 1 0 0 0 1
// 1 1 0 1 1

// Sample Output-2:
// ----------------
// 4



import java.util.*;


public class DistinctIslands {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int[][] grid = new int[m][n];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                grid[i][j] = sc.nextInt();
        System.out.println(new Solution().numDistinctIslands(grid));
    }
}



class Solution {
    private static final int[] dRow = {-1, 1, 0, 0};
    private static final int[] dCol = {0, 0, -1, 1};

    private class DSU {
        int[] parent;
        int[] size;

        public DSU(int n) {
            parent = new int[n];
            size = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }

        void union(int x, int y) {
            int px = find(x);
            int py = find(y);
            if (px == py) return;
            if (size[px] < size[py]) {
                parent[px] = py;
                size[py] += size[px];
            } else {
                parent[py] = px;
                size[px] += size[py];
            }
        }
    }

    public int numDistinctIslands(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        DSU dsu = new DSU(m * n);

        // Step 1: Union connected 1's
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int id1 = i * n + j;
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dRow[d], nj = j + dCol[d];
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == 1) {
                            int id2 = ni * n + nj;
                            dsu.union(id1, id2);
                        }
                    }
                }
            }
        }

        // Step 2: Group cells by root parent
        Map<Integer, List<int[]>> islandMap = new HashMap<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int id = i * n + j;
                    int root = dsu.find(id);
                    islandMap.computeIfAbsent(root, k -> new ArrayList<>()).add(new int[]{i, j});
                }
            }
        }

        // Step 3: Normalize each island's shape
        Set<String> distinctShapes = new HashSet<>();
        for (List<int[]> island : islandMap.values()) {
            distinctShapes.add(normalize(island));
        }

        return distinctShapes.size();
    }

    private String normalize(List<int[]> island) {
        // Sort based on row, then column
        island.sort((a, b) -> {
            if (a[0] != b[0]) return a[0] - b[0];
            return a[1] - b[1];
        });

        // Find top-left most coordinate
        int baseRow = island.get(0)[0];
        int baseCol = island.get(0)[1];

        StringBuilder sb = new StringBuilder();
        for (int[] cell : island) {
            sb.append((cell[0] - baseRow)).append(",").append((cell[1] - baseCol)).append(";");
        }

        return sb.toString();
    }
}

