

// Link -> https://www.desiqna.in/16115/google-interview-problem-dynamic-programming-cities-october 

// Mentor :- Kumar K(Prev SDE @ Amazon; All India Rank 12 Google CodeJam’21 ; World Rank 368 Google Kickstart ; World Rank 178 in LeetCode Weekly Contest) 



// Understanding :-> You are given 2 arrays ; travel from start to end; maximum maximum dollars ; whenever you try to jump from Array “A” to Array “B” you make no money :) 


// Analysis :-> 
// dp[i] = best answer to the question if the size of array was “i” 
// -> we really need information at ith index whether we have take element from array A or B   

// -> dp[i][a] = best answer to the question if size of both array were “i” and the element picked at the ith index if for sure from array “a”

// -> dp[i][b] = best answer to the question if size of both array were i and element picked at ith index is from B

// dp[i][a] = max(a[i] + dp[i-1][a] Or a[i] + dp[i-2][b]) 

// dp[i][b] = max(b[i] + dp[i-1][b] or b[i] + dp[i-2][a]) 

// —-----------------------------------------------------------

// C++ https://ideone.com/0gX7CQ
// Java. https://ideone.com/WAEqvQ 
// Py https://ideone.com/POwtBK 

// TC :- O(N)
// SC :-O(N*2)=>O(N)

// You have to print the maximum earning but there is a way to print the whole schedule of “N” depicting on which day what choice you have made for the final best answer. Think about how to do it :) 
// Hint - At each step you can see what is the maximum quantity indicating what you have done for that day and its previous day 

// dp1[i][a] should tell you what was done on the previous day to reach this step today 

// —-------------------------------------------------------------

// Follow up dp formulation! 

// dp[i][b] = max(b[i]+dp[i-1][b],b[i]+dp[i-2][a],b[i]+dp[i-2][c])

// dp[i][a] = max(dp[i-1][a], dp[i-2][b], dp[i-2][c]) + a[i])
// dp[i][c] = max(c[i]+dp[i-1][c],c[i]+dp[i-2][a],c[i]+dp[i-2][b])

// TC ➖O(N)
// SC - O(3*N) …O(N)

// C++ - Homework
// Java. - Homework
// Py - Homework 


// dpa[n  +   1] = {0};
// dpb[n  +  1] = {0};

// dpa[0] = 0;
// dpb[0] = 0;

// dpa[1] = a[0];
// dpb[1] = b[0];

// dpa[i] = max(dpa[i-1] + a[i],dpb[i-2] + a[i]); 
// dpb[i] = max(dpb[i-1] + b[i],dpa[i-2] + b[i]);

// or

// dpa[n + 1][2] 


// dpa[0][0] = 0;

// dpa[i][a] = max(dpa[i-1][a] + a[i],dpa[i-2][b] + a[i]);
// dpa[i][b] = max(dpa[i-1][b] + b[i],dpa[i-2][a] + b[i]);



// for 3 cities.........

// dp[n + 1][3].....

// // dp[0][0] = 0;
//  dp[0][1]
// 
// dp[i][a] = a[i] + max(dp[i-1][a],dp[i-2][b],dp[i-2][c]);
// dp[i][b] = b[i] + max(dp[i-1][b],dp[i-2][a],dp[i-2][c]);
// dp[i][c] = c[i] + max(dp[i-1][c],dp[i-2][a],dp[i-2][b]);

