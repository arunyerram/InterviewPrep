
// Given a string str of length n, your task is to find all possible ways to split it into non-empty, contiguous, and non-overlapping substrings while preserving the original character order.If the input string is empty, return an empty list [].

// Each split must use all characters in the original string exactly once, with substrings formed from consecutive characters only.

// Input Format:
// --------------
// Line-1: A single string str containing only uppercase or lowercase English letters.

// Output Format:
// --------------
// Line-1: A list of lists containing all possible combinations of non-overlapping, contiguous substrings.
// Each inner list represents one valid way to split the string.

// Constraints:
// ------------
// -> 1 ≤ str.length() ≤ 100
// -> The string can contain only uppercase or lowercase English letters.
// -> Each substring in a combination must be contiguous (no skipping characters).
// -> If the input is an empty string, output an empty list.

// Sample  Input-1:
// ----------------
// ABC

// Sample Output-1:
// ----------------
// [["A", "B", "C"], ["A", "BC"], ["AB", "C"], ["ABC"]]

// Sample  Input-2:
// ---------------
// ABCD

// Sample Output-2:
// ----------------
// [["A", "B", "C", "D"], ["A", "B", "CD"], ["A", "BC", "D"], ["A", "BCD"], ["AB", "C", "D"], ["AB", "CD"], ["ABC", "D"], ["ABCD"]]


