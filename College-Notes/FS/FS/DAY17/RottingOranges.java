/*
 * You are given an m x n grid where each cell can have one of three values:
-> 0 representing an empty cell,
-> 1 representing a fresh orange, or
-> 2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. 
If this is impossible, return -1.


Input Format:
-------------
Line-1: Two integers, m and n, represents grid[] sizes
Line-2 to m: n Space separated integers, represents grid[i][j]

Output Format:
--------------
Line-1: An integer

Sample Input-1:
---------------
3 3
2 1 1
1 1 0
0 1 1

Sample Output-1:
----------------
4

Sample Input-2:
---------------
3 3
2 1 1
0 1 1
1 0 1

Sample Output-2:
----------------
-1

Explanation: 
-------------
The orange in the bottom left corner (row 2, column 0) is never rotten, 
because rotting only happens 4-directionally.

Sample Input-3:
---------------
1 1
0 2

Sample Output-3:
----------------
0

Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 
Constraints:
------------
m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
 */

//  import java.util.*;

// public class RottingOranges{
//     public static int iterate(int arr[][], int i, int j, int dirs[][]){
//         int cnt = 0;
//         boolean updated = false;
//         for(int d[]: dirs){
//             int x = i+d[0];
//             int y = j+d[1];
//             if(x>=0 && x<arr.length && y>=0 && y<arr[0].length && arr[x][y] == 2){
//                 arr[i][j] = 2;
//                 cnt = 1;
//                 // System.out.println("X : "+ x + " Y : "+y);
//             }else{
//                 cnt = -1;
//             }
//         }
//         // if(updated){
//         //     cnt = 1;
//         // }else if(!updated){
//         //     cnt = 0;
//         // }
//         // System.out.println("I : "+ i + "J : "+j);
//         return cnt;
//     }
//     public static int solve(int arr[][], int n, int m){
//         int res = 0;
//         int dirs[][] = {{-1,0},{1,0},{0,1},{0,-1}};
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(arr[i][j] == 1){
//                     int r = iterate(arr, i, j, dirs);
//                     if(r == -1){
//                         res = -1;
//                         break;
//                     }else{
//                         res += r;
//                     }
//                 }
//             }
//         }
//         return res;
//     }
//     public static void main(String args[]){
//         Scanner sc = new Scanner(System.in);
//         int n = sc.nextInt();
//         int m = sc.nextInt();
//         int arr[][] = new int[n][m];
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 arr[i][j] = sc.nextInt();
//             }
//         }
//         System.out.print(solve(arr, n, m));
//     }
// }

// import java.util.*;

// public class RottingOranges {
//     public static int solve(int[][] grid, int m, int n) {
//         Queue<int[]> queue = new LinkedList<>();
//         int freshCount = 0;
//         int minutes = 0;
        
//         // Directions for 4-directional spread
//         int[][] directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        
//         // Initialize the queue with all rotten oranges and count fresh oranges
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (grid[i][j] == 2) {
//                     queue.offer(new int[]{i, j});
//                 } else if (grid[i][j] == 1) {
//                     freshCount++;
//                 }
//             }
//         }
        
//         // If there are no fresh oranges, no minutes are required
//         if (freshCount == 0) {
//             return 0;
//         }
        
//         // Perform BFS to rot the fresh oranges
//         while (!queue.isEmpty()) {
//             int size = queue.size();
//             boolean hasRotten = false;
            
//             for (int i = 0; i < size; i++) {
//                 int[] rotten = queue.poll();
//                 for (int[] dir : directions) {
//                     int newX = rotten[0] + dir[0];
//                     int newY = rotten[1] + dir[1];
                    
//                     if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1) {
//                         grid[newX][newY] = 2;
//                         freshCount--;
//                         queue.offer(new int[]{newX, newY});
//                         hasRotten = true;
//                     }
//                 }
//             }
            
//             // Only increment minutes if we actually rotted some fresh oranges
//             if (hasRotten) {
//                 minutes++;
//             }
//         }
        
//         // If there are still fresh oranges left, it's impossible to rot them all
//         return freshCount == 0 ? minutes : -1;
//     }

//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         int m = sc.nextInt();
//         int n = sc.nextInt();
//         int[][] grid = new int[m][n];
        
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 grid[i][j] = sc.nextInt();
//             }
//         }
        
//         System.out.println(solve(grid, m, n));
//     }
// }

import java.util.*;

public class RottingOranges{
    public static int solve(int arr[][], int n, int m){
        int cnt = 0;
        int res = 0;
        int dirs[][] = {{-1,0},{1,0},{0,1},{0,-1}};
        Queue<int []> q = new LinkedList<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j] == 2){
                    q.add(new int[]{i,j});
                }else if(arr[i][j] == 1){
                    cnt++;
                }
            }
        }
        while(!q.isEmpty()){
            int s = q.size();
            for(int i=0; i<s;i++){
                int c[] = q.poll();
                boolean up = false;
                for(int d[]: dirs){
                    int x = c[0]+d[0];
                    int y = c[1]+d[1]; 
                    if(x>=0 && x<arr.length && y>=0 && y<arr[0].length && arr[x][y] == 1){
                        arr[x][y] = 2;
                        cnt--;
                        q.add(new int[]{x,y});
                    }
                }
            }
            res++;
        }
        return cnt == 0 ? res-1 : -1;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int arr[][] = new int[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j] = sc.nextInt();
            }
        }
        System.out.print(solve(arr, n, m));
    }
}