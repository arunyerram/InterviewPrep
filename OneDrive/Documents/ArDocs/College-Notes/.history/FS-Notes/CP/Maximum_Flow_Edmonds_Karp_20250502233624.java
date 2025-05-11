// Given a graph which represents a flow network where every edge has a capacity. 
// Also, given two vertices source 's' and sink 't' in the graph, find the maximum possible flow from s to t with the following constraints:
// 	- Flow on an edge doesn't exceed the given capacity of the edge.
// 	- Incoming flow is equal to outgoing flow for every vertex except s and t.

// Input Format:
// ------------------
// Line-1: An integer V, number of vertices in graph
// Next V lines: V space separated integers, graph[][], 
//                        the adjacency matrix of the grpah.
// Last Line: Two space separated integers, s and t, source and sink.

// input=
// //Enter number of vertices 
// 6
// //Enter the adjacency matrix of the directed graph
// 0 16 13  0   0   0
// 0  0  10 12  0   0
// 0  4   0   0  14  0
// 0  0   9   0   0  20
// 0  0   0   7   0  4
// 0  0   0   0   0  0
// //Enter source and sink 
// 0 5
// Output =23

// Example 2:
// input=
// //Enter number of vertices 
// 6
// //Enter the adjacency matrix of the directed graph
// 0 7 4 0 0 0
// 0 0 0 5 3 0
// 0 3 0 0 2 0
// 0 0 0 0 0 8
// 0 0 0 3 0 5
// 0 0 0 0 0 0
// //Enter source and sink
// 0 5
// output=10



public class Maximum_Flow_Edmonds_Karp {
    
}
