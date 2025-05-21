
import java.util.*;
class ConnectedComponents {

    public void dfs(int node,List<List<Integer>>adj,boolean[] vis){
        if(vis[node]) return;
        
        vis[node] = true;
        
        for(int it:adj.get(node))
            if(!vis[it])
                dfs(it,adj,vis);
                
    }
    public int countComponents(int n, int[][] edges) {
        //Write your code here and return an integer
        List<List<Integer>>adj = new ArrayList<>();
        for(int i=0;i<n;i++)
            adj.add(new ArrayList<>());
        for(int [] it : edges){
            int a = it[0];
            int b = it[1];
            
            adj.get(a).add(b);
            adj.get(b).add(a);
        }
        int cnt = 0;
        boolean[] vis = new boolean[n];
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }    
   //Any supporting functinalities, write here
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int e = sc.nextInt();
        int[][] edges = new int[e][2];        
        for (int i = 0; i < e; i++) {
            for (int j = 0; j < 2; j++) {
                edges[i][j] = sc.nextInt();
            }
        }        
        int result = new ConnectedComponents().countComponents(n, edges);
        System.out.println(result);
    }
}
