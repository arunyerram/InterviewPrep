import java.util.*;

public class DistinctShapes{
    
    public static boolean isValid(int arr[][], int x, int y, int n, int m){
        return (x<n && x>=0 && y>=0 && y<m ) && (arr[x][y] == 1);
    }
    
    public static void iterate(int arr[][], int i, int j, int row, int col, StringBuilder sb, int[][] dirs){
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{i,j});
        arr[i][j] = 0;
        
        while(!q.isEmpty()){
            int curr[] = q.poll();
            sb.append(curr[0]- row);
            sb.append(curr[1]- col);
            for(int[] d: dirs){
                int newX = curr[0]+d[0];
                int newY = curr[1]+d[1];
                if(isValid(arr, newX, newY, arr.length, arr[0].length)){
                    q.offer(new int[]{newX, newY});
                    arr[newX][newY] = 0;
                }
            }
        }
    }
    
    public static int solve(int arr[][], int n, int m){
        if(arr == null) return -1;
        Set<String> s = new HashSet<>();
        int dirs[][] = {{-1,0},{1,0},{0,1},{0,-1}};
        for(int i = 0; i<n;i++){
            for(int j=0;j<arr[0].length;j++){
                if(arr[i][j] == 1){
                    StringBuilder sb = new StringBuilder();
                    iterate(arr, i, j, i, j, sb,dirs);
                    s.add(sb.toString());
                }
            }
        }
        return s.size();
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
        System.out.print(solve(arr,n,m));
    }
}