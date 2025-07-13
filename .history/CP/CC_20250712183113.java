






import java.util.*;
class ConnectedComponents
{
// A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
int V;
ArrayList<ArrayList<Integer> > adjListArray;
// constructor
ConnectedComponents(int V)
{
this.V = V;
// define the size of array as number of vertices
adjListArray = new ArrayList<>();
// Create a new list for each vertex such that adjacent nodes can be stored
for (int i = 0; i < V; i++)
{
adjListArray.add(i, new ArrayList<>());
}
}
// Adds an edge to an undirected graph
void addEdge(int src, int dest)
{
// Add an edge from src to dest.
adjListArray.get(src).add(dest);
// Since graph is undirected, add an edge from dest to src also
adjListArray.get(dest).add(src);
}
void DFSUtil(int v, boolean[] visited)
{
// Mark the current node as visited and print it
visited[v] = true;
COMPETITIVE PROGRAMMING UNIT-IV III – II SEM (KR21 Regulations)
KESHAV MEMORIAL INSTITUE OF TECHNOLOGY (AN AUTINOMOUS INSTITUTE)
System.out.print(v + " ");
// Recur for all the vertices
// adjacent to this vertex
for (int x : adjListArray.get(v))
{
if (!visited[x])
DFSUtil(x, visited);
}
}
void connectedComponents()
{
// Mark all the vertices as not visited
boolean[] visited = new boolean[V];
for (int v = 0; v < V; ++v) {
if (!visited[v]) {
// print all reachable vertices
// from v
DFSUtil(v, visited);
System.out.println();
}
}
}
public static void main(String args[])
{
Scanner sc=new Scanner(System.in);
System.out.println("enter number of vertices ");
int v=sc.nextInt();
System.out.println("enter number of edges");
int e=sc.nextInt();
ConnectedComponents g = new ConnectedComponentsh(v);
System.out.println("enter edges");
for(int i=0;i<e;i++)
{
int end1=sc.nextInt();
int end2=sc.nextInt();
g.addEdge(end1,end2);
}
System.out.println("Following are connected components");
g.connectedComponents();
}
