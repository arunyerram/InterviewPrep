

class Solution {
    public static void dfs(int node,int[] vis,Stack<Integer>st,ArrayList<ArrayList<Integer>>adj){
        vis[node] = 1;
        for(int it:adj.get(node)){
            if(vis[it] == 0){
                dfs(it,vis,st,adj);
            }
        }st.push(node);
    }
    public static ArrayList<Integer> topoSort(int V, int[][] edges) {
        // code here
        ArrayList<ArrayList<Integer>>adj = new ArrayList<>();
        for(int i=0;i<V;i++)adj.add(i,new ArrayList<>());
        
        for(int[] it:edges){
            adj.get(it[0]).add(it[1]);    
        }
        int[] vis = new int[V];
        // int[] ans = new int[V];
        ArrayList<Integer>ans= new ArrayList<>();
        Stack<Integer>st = new Stack<>();
        
        for(int i=0;i<V;i++){
            if(vis[i] == 0)
                dfs(i,vis,st,adj);
        }
        
        while(!st.isEmpty()){
            ans.add(st.peek());
            st.pop();
        }return ans;
    }
}