
// There are N cities, and M routes[], each route is a path between two cities.
// routes[i] = [city1, city2], there is a travel route between city1 and city2.
// Each city is numbered from 0 to N-1.
 
// There are one or more Regions formed among N cities. 
// A Region is formed in such way that you can travel between any two cities 
// in the region that are connected directly and indirectly.
 
// Your task is to findout the number of regions formed between N cities. 
 
// Input Format:
// -------------
// Line-1: Two space separated integers N and M, number of cities and routes
// Next M lines: Two space separated integers city1, city2.
 
// Output Format:
// --------------
// Print an integer, number of regions formed.
 
 
// Sample Input-1:
// ---------------
// 5 4
// 0 1
// 0 2
// 1 2
// 3 4
 
// Sample Output-1:
// ----------------
// 2
 
 
// Sample Input-2:
// ---------------
// 5 6
// 0 1
// 0 2
// 2 3
// 1 2
// 1 4
// 2 4
 
// Sample Output-2:
// ----------------
// 1


import java.util.*;
public class ConnectedComponentsBFS{
    public void bfs(int node,boolean[] vis,List<List<Integer>>adj){
        Queue<Integer>qu = new LinkedList<>();
        qu.offer(node);
        vis[node] = true;
        while(!qu.isEmpty()){
            int nd = qu.poll();
            
            for(int it:adj.get(nd)){
                if(!vis[it]){
                    // bfs(it,vis,adj);
                    qu.offer(it);
                    vis[it] = true;
                
                }
            }
        }
    }
    public int countComponents(int n, int[][] edges) {
        //Write your code here and return an integer
        boolean[] vis = new boolean[n];
        List<List<Integer>>adj = new ArrayList<>();
        for(int i=0;i<n;i++)
            adj.add(new ArrayList<>());
        
        for(int [] it:edges){
            int a = it[0];
            int b = it[1];
            
            adj.get(a).add(b);
            adj.get(b).add(a);
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,vis,adj);
                cnt++;
            }    
        }return cnt;
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
        int result = new ConnectedComponentsBFS().countComponents(n, edges);
        System.out.println(result);
    }
}
