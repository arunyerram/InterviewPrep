
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 



int main() {
    
    ll n ; 
    cin>>n ; 
    //taking input --> size of graph 
    
    ll m ; 
    //taking input --> number of edges in the graph 
    cin>>m ; 
    
    vector <ll> G[n+5]; //constructing a graph using adjacency list 
    
    ll i = 1 ; 
    while(i<=m){
        
        ll u,v ; 
        cin>>u>>v ; //reading the number of edges in the graph 
        G[u].push_back(v);
        G[v].push_back(u);
        //making un directed graph jii 
        i++;
    }
    
    
    queue <ll> q ; //declaring a queue  
    
    q.push(1) ; //pushing the source node = 1 in the queue  
    
    ll used[n+5] = {0}; //declaring an empty used array where in used[i] = 0 means this node has not yet been visited in our algorithm
    
    used[1] = 1 ; //1st node has been visited hence setting is as 1 and it is inserted in the queue as well jiiiiii
    ll lvl[n+5] = {0}; //declaring level array this basically lets us know level of each node jiiiii 
    lvl[1] = 0 ; //lvl of 1st node which we mean the source node is 0 as we start from here jiiiiiiii
    
    
    
    while(!q.empty()){
        //BFS Algo 
        
        ll v = q.front(); //top most element of queue jii
        cout<<v<<" "<<lvl[v]; //printing that node with its lvl 
        cout<<"\n";
        q.pop(); //popping out the top most element of the queue jii........ 
        
        for(auto u : G[v]){
            //this simply means you'r iterating through all nodes connected to node v 
            if(used[u]==0){
                
                //if the node u(node connected to v) has never been visited before then lets visit it jiii
                q.push(u);
                used[u] = 1 ; //it has now been visited hence setting its values as 1 
                lvl[u] = lvl[v] + 1 ; //lvl[u] will be 1 greater than lvl[1] as we move 1 step forward from u to v jiii 
                
                
            }
            
            
            
            
        }
        
        
        
        
        
        
    }
    
    





    import java.util.*; // importing java.util package

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // declaring Scanner object to take input
        int n = sc.nextInt(); // taking input of size of graph
        int m = sc.nextInt(); // taking input of number of edges in the graph
        ArrayList<ArrayList<Integer>> G = new ArrayList<>(); // constructing graph using adjacency list

        // creating n number of vertices in graph
        for (int i = 0; i <= n; i++) {
            G.add(new ArrayList<Integer>());
        }

        // reading edges of graph
        for (int i = 1; i <= m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            G.get(u).add(v);
            G.get(v).add(u);
            // making un-directed graph
        }

        Queue<Integer> q = new LinkedList<>(); // declaring a queue

        q.add(1); // pushing the source node = 1 in the queue

        int[] used = new int[n + 5]; // declaring an empty used array where in used[i] = 0 means this node has not yet been visited in our algorithm
        used[1] = 1; // 1st node has been visited hence setting it as 1 and it is inserted in the queue as well

        int[] lvl = new int[n + 5]; // declaring level array which lets us know level of each node
        lvl[1] = 0; // lvl of 1st node, which is the source node, is 0 as we start from here

        while (!q.isEmpty()) {
            // BFS Algo

            int v = q.remove(); // top most element of queue

            System.out.println(v + " " + lvl[v]); // printing that node with its level

            for (int i = 0; i < G.get(v).size(); i++) {
                // iterating through all nodes connected to node v
                int u = G.get(v).get(i);
                if (used[u] == 0) {
                    // if the node u (node connected to v) has never been visited before then let's visit it
                    q.add(u);
                    used[u] = 1; // it has now been visited hence setting its value as 1
                    lvl[u] = lvl[v] + 1; // lvl[u] will be 1 greater than lvl[1] as we move 1 step forward from u to v
                }
            }
        }
    }
}





    
    
    return 0 ; 
}