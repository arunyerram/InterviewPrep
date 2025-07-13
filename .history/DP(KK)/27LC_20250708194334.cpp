// Link - https://leetcode.com/problems/paint-house-iv/description/ 

// Prerequisite for this question :- 

// Read these written tutorials and code them up before going ahead. 
// Dynamic
// Programming
// Session 1 
// Interview Level

// Notes
// Q 
// Sol


// https://ideone.com/s9Hgq9 
// https://ideone.com/6JeMuZ 
// Dynamic
// Programming
// Session 2  
// Interview Level

// Notes
// Q 
// https://ideone.com/RKRDXB 


// https://ideone.com/47a5Ts 
// https://ideone.com/edN1rl 
// Dynamic
// Programming
// Session 3  
// Interview Level

// Notes
// Q
// https://ideone.com/zPiT8c 
// https://ideone.com/I6hlGe 
// https://ideone.com/EkKK0L 
// Dynamic
// Programming
// AtCoder DP Session 4

// Thought Process. 
 
// Q1 


// Q2 


 
// C++1 


// C++2 
// Java1 


// Java2 


// Py1 


// Py2 



// Dynamic 
// Programming
// PayPal OA. Session 5 
// doc 








// Easy version of the problem :- Exactly same as this question :- https://atcoder.jp/contests/dp/tasks/dp_c 
// (Instead of the minimum they are asking for the maximum.) 


// -> dp[1][a] = a[1] 
// -> dp[1][b] = b[1]
// -> dp[1][c] = c[1] 

// -> dp[i][a] = minimum cost to travel from index 1 to index “i” such that at ith position you pick a[i] 
// -> dp[i][b] = minimum cost to travel from index 1 to index “i” such that at ith position you pick b[i] 
// -> dp[i][c] = minimum cost to travel from index 1 to index “i” such that at ith position you pick c[i] 


// -> dp[i][b] = b[i] + min(dp[i-1][a],dp[i-1][c]) 

// -> Run a for loop calculate for all i from 1 to N; -> dp[n][a],dp[n][b],dp[n][c] -> max of these 3 values is the final answer 

// Harder version :- Easy version condition + Element type of 1st row should not match last row - Element type of 2nd row should not match 2nd last row and so on….. 

// -> Equidistant row type should also not match; 


// -> dp[1][b][c] = select type “b” guy from row 1 and type “c” guy from row n = min answer to do it 

// -> dp[2][b][c] = select type “b” guy from row 2; and type “c” guy from row n-1 + best answer possible for row 1 – n(9 possibilities = min(dp[1][a][a],dp[1][b][b],...................) 

// -> 9 possibilities :- min(dp[1][i1][j1])
// -> where i1!=j1 and i1!=b and j1!=c 

// -> dp[i][j][k] = select type “j” guy from row i and type “k” guy from row n-i+1 = min answer to do it

// -> Final answer = min(dp[n/2][i1][j1]) such that i1!=j1 



// C++ https://leetcode.com/problems/paint-house-iv/submissions/1513226092/ 
// Java. 
// https://leetcode.com/problems/paint-house-iv/submissions/1521918987/ 
// Py 
// https://leetcode.com/problems/paint-house-iv/submissions/1521920541/ 


// https://www.youtube.com/watch?v=oAhlTS7U8GM&t=465s

// sHouldďlearn again................



#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        // DP array to store the minimum cost of painting houses
        vector<vector<vector<ll>>> dp(n / 2, vector<vector<ll>>(3, vector<ll>(3, LLONG_MAX)));

        // Initialize the dp for the first pair (0th house and (n-1)th house)
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    dp[0][i][j] = cost[0][i] + cost[n-1][j];  // First and last house painted with i and j respectively
                }
            }
        }

        // DP calculation for subsequent houses
        for (int row = 1; row < n / 2; row++) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (i == j) continue;  // Skip when adjacent houses are the same color
                    
                    ll minPrev = LLONG_MAX;
                    
                    // Search for previous valid (i1, j1) where i1 != i, j1 != j, and i1 != j1
                    for (int i1 = 0; i1 < 3; i1++) {
                        for (int j1 = 0; j1 < 3; j1++) {
                            if (i1 != i && j1 != j && i1 != j1) {
                                minPrev = min(minPrev, dp[row-1][i1][j1]);
                            }
                        }
                    }
                    
                    dp[row][i][j] = minPrev + cost[row][i] + cost[n-row-1][j];
                }
            }
        }

        // Final answer is the minimum cost from the last row dp[n/2 - 1] considering i != j
        ll result = LLONG_MAX;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    result = min(result, dp[n/2-1][i][j]);
                }
            }
        }

        return result;
    }
};



