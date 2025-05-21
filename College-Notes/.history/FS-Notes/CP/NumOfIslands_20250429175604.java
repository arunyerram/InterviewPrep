
// Ibrahim is an interior designer wants to color wall of size M*N. 
// He plans to color the wall and put lights of two different colors

// The designer can lit the wall using M*N lights.The lights are Blue or pink
// in color. Blue colored lights represented with digit-1 and pink colored lights 
// represented with digit-0.

// The Blue colored lights forms different shapes, that are connected 4 directonally.
// The directons are upwards, downwards, left, and right. Ibrahim got an idea to 
// count the number of shapes formed by blue colored lights.

// You will be given the decorated wall as a matrix wall[][].
// Your task is to help Ibrahim to count the number of shapes by the lights.

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

public class NumOfIslands {
    private int[] sz;
    private int[] parent;
    private int rows, cols;

    public int find(int p) {
        if (parent[p] != p) {
            parent[p] = find(parent[p]); // Path compression
        }
        return parent[p];
    }

    public void union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);

        if (rootP == rootQ) return;

        if (sz[rootP] < sz[rootQ]) {
            parent[rootP] = rootQ;
            sz[rootQ] += sz[rootP];
        } else {
            parent[rootQ] = rootP;
            sz[rootP] += sz[rootQ];
        }
    }

    public int numIslands(int[][] grid) {
        rows = grid.length;
        cols = grid[0].length;
        int total = rows * cols;
        parent = new int[total];
        sz = new int[total];

        for (int i = 0; i < total; i++) {
            parent[i] = i;
            sz[i] = 1;
        }

        // Directions: up, down, left, right
        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    int index1 = i * cols + j;
                    for (int[] d : dirs) {
                        int ni = i + d[0], nj = j + d[1];
                        if (ni >= 0 && ni < rows && nj >= 0 && nj < cols && grid[ni][nj] == 1) {
                            int index2 = ni * cols + nj;
                            union(index1, index2);
                        }
                    }
                }
            }
        }

        // Count distinct roots for cells with value 1
        Set<Integer> shapes = new HashSet<>();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    shapes.add(find(i * cols + j));
                }
            }
        }
        return shapes.size();
    }

    public static void main(String args[]) {
        Scanner s = new Scanner(System.in);
        int row = s.nextInt();
        int col = s.nextInt();
        int arr[][] = new int[row][col];
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                arr[i][j] = s.nextInt();
            }
        }
        System.out.println(new NumOfIslands().numIslands(arr));
    }
}
