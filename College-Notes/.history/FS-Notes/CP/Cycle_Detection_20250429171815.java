
// Mr. Balu is interested in solving puzzles. 
// One puzzle involves a given number of nodes and undirected paths between these nodes. 

// He needs to determine whether he can exit from path loop or not. 
// If at least one cycle can be formed with the given paths, then he cannot exit.

// Input Format:
// -------------
// Line-1: Two integers n and e, n, number of nodes and e number of edges
// Line-2 to e: e number of integer pairs, space separated

// Output Format:
// --------------
// Line-1: A string, Cycle_found or No_Cycle_Found

// Sample Input-1:
// ---------------
// 5 5
// 0 1
// 1 2
// 2 3
// 3 4
// 4 0

// Sample Output-1:
// ----------------
// Cycle_Found

// Sample Input-2:
// ---------------
// 5 4
// 0 1
// 1 2
// 2 3
// 3 4

// Sample Output-2:
// ----------------
// No_Cycle_Found



// Program to implement Disjoint Set Data Structure.

/*
5 = number of friends
3 = number of relationships
2 = number of friendship check
input=5
3
0 2
4 2
3 1
2
4 0
1 0
output=4 is a friend of 0
1 is not a friend of 0

*/

