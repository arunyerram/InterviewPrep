

// n vertices..... n edges.............

// ...........and min sum to reacH all vertices............. 


//  pq ---- {wgt,nd,parent};
//  pq.add({0,0,-1}); // {wgt,nd,parent}

import java.util.*;
class Pair{
    int node;
    int dist;
    
    Pair(int dist,int node){
        this.node = node;
        this.dist = dist;
    }
}
class MST {
    static int spanningTree(int V, int E, List<List<int[]>> adj) {
        // Code Here.
        int cnt = 0;
        PriorityQueue<Pair>pq = new PriorityQueue<>((a,b)-> a.dist - b.dist);
        
        boolean[] vis = new boolean[V];
        pq.add(new Pair(0,0));
        int sum = 0;
        while(pq.size() > 0){
            Pair p = pq.peek();
            pq.remove();
            int nd = p.node;
            int dst = p.dist;
            if(vis[nd] == true)continue;
            vis[nd] = true;
            sum += dst;
            for(int[] it: adj.get(nd)){
                int nbr = it[0];
                int wgt = it[1];
                
                if(!vis[nbr])pq.add(new Pair(wgt,nbr));
            }
        }
        return sum;
    }
}