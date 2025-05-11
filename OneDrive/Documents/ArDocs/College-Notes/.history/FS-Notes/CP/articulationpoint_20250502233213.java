// A vertex is said to be an articulation point in a graph 
// if removal of the vertex and associated edges disconnects the graph.

// So, the removal of articulation points increases the number of connected components in a graph.

// The main aim here is to find out all the articulations points in a graph.


// Sample Input-1:
// ---------------
// 5
// 5
// 1 0
// 0 2
// 2 1
// 0 3
// 3 4

// Sample Output-1:
// ----------------
// [0, 3]

// Sample Input-2:
// ---------------
// 4
// 3
// 0 1
// 1 2
// 2 3

// Sample Output-2:
// ----------------
// [1, 2]


// Sample Input-3:
// ---------------
// 7
// 8
// 0 1 
// 1 2
// 2 0 
// 1 3
// 1 4
// 1 6
// 3 5
// 4 5

// Sample Output-3:
// ----------------
// [1]

// Sample Input-4:
// ---------------
// 5
// 4
// 0 1
// 1 2
// 2 3
// 3 4

// Sample Output-4:
// ----------------
// [1, 2, 3]



