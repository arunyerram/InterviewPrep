// You're given a binary tree represented in level-order (with -1 denoting nulls). Your task is to print all paths from each leaf node to the root, preserving the order from leaf → parent → … → root. Each path should be printed on a new line, with node values joined by " —> ".
// If the current node is null, return.
// If the current node is a leaf (no left or right children), print the current path.

// Input Format:
// ------------
// Line-1: A single line containing space-separated integers representing the binary tree in level-order.
// Use -1 to represent a null (no child).

// Output Format:
// --------------
// Each line represents one path from a leaf node to the root.
// Node values must be joined using " —> ".
// Order of output paths may vary based on traversal, but all valid paths must be included

// Constraints:
// -------------
// 1 ≤ number of nodes ≤ 10^4
// Node values are integers in the range [-10^9, 10^9]
// Input tree is binary (each node has at most two children)
// Input is provided in level-order, and -1 denotes nulls

// Sample Input-1:
// ------------------
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1

// Sample Output-1:
// --------------
// 4 —> 2 —> 1  
// 5 —> 2 —> 1  
// 8 —> 6 —> 3 —> 1  
// 9 —> 6 —> 3 —> 1  
// 7 —> 3 —> 1

// Sample Input-2:
// -------------
// 1 -1 2 -1 3 -1 4

// Sample Output-2:
// -------------------
// 4 —> 3 —> 2 —> 1


