
// u ----> v  uuuu before vvvvv



/* A Java program to print topological sorting of a graph using indegrees

Sample Input=1:
---------------
6 //no of vertices
6 //no of edges
5 2
5 0
4 0
4 1
2 3
3 1

Sample Output-1:
----------------
4 5 2 0 3 1

Sample Input-2:
---------------
5
5
4 0
4 1
2 3
3 1
2 0

Sample Output-2:
----------------
2 4 3 0 1

*/

import java.util.*;

// Class to represent a graph
class Graph 
{
	// No. of vertices
	int V;

	// An Array of List which contains references to the Adjacency List of each vertex
	List<Integer> adj[];
// 	List<Integer>adj[];
// 	adj = new ArrayList[V];
	
	// Constructor
	public Graph(int V)
	{
		this.V = V;
		adj = new ArrayList[V];
		for (int i = 0; i < V; i++)
			adj[i] = new ArrayList<Integer>();
	}

	// Function to add an edge to graph
	public void addEdge(int u, int v)
	{
		adj[u].add(v);
	}

	public void topologicalSort()
	{
		//Write your code here and print the vertices order after sorting
		int[] in = new int[V];
		for(int i=0;i<V;i++){
		    for(int it:adj[i]){
		        in[it]++;
		    }
		}
		Queue<Integer>q = new LinkedList<>();
		for(int i=0;i<in.length;i++){
		    if(in[i] == 0){
		        q.offer(i);
		    }
		}
		List<Integer>ans = new ArrayList<>();
		while(!q.isEmpty()){
		    int ele = q.poll();
		    ans.add(ele);
		    
		    for(int it:adj[ele]){
		        in[it]--;
		        if(in[it] == 0) q.offer(it);
		    }
		}
		if(ans.size() == V){
		  //  System.out.println(ans);
		  for(int i=0;i<ans.size();i++){
		      System.out.print(ans.get(i));
		      if(i != ans.size() - 1)System.out.print(" ");
		  }
		  System.out.println();
		}else{
            System.out.println("Cycle is present in the graph");
        }
		return;
	}
}

class test 
{
	public static void main(String args[])
	{
		// Create a graph 
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		Graph g = new Graph(n);
        int e=sc.nextInt();
		for(int i=0;i<e;i++){
			int e1=sc.nextInt();
			int e2=sc.nextInt();
			g.addEdge(e1,e2);
		}

		//System.out.println("Following is a Topological Sort");
		g.topologicalSort();
	}
}
