

// Kumar K student cracks off-campus SDE offer from Amazon + Google in May - https://www.linkedin.com/posts/kumark1_kumark-coding-activity-7325533608889237505-6fVw?utm_source=share&utm_medium=member_desktop&rcm=ACoAADB1e44BA43UYjFx2BwtGFrtyTJFuENef5c 

// -> https://training.desiqna.in 

// Link -> https://leetcode.com/discuss/post/6719472/meesho-oa-sde-1-by-anonymous_user-20ol/ 




// Understanding :-> Best way to travel the array such that sum is maximum as per the conditions given :-> 

// If you visit index “i” and “i+1” , “i-1” are unvisited; -> sum = sum + A[i] 

// -> If one of the adjacent indices is visited; sum = sum + B[i] 

// -> If both the adjacent indices are visited; sum = sum + C[i] 

// -> dp[i] = best journey possible if you have surely visited indices from “1” to “i” 








// Kumar K student cracks off-campus SDE offer from Amazon + Google in May - https://www.linkedin.com/posts/kumark1_kumark-coding-activity-7325533608889237505-6fVw?utm_source=share&utm_medium=member_desktop&rcm=ACoAADB1e44BA43UYjFx2BwtGFrtyTJFuENef5c 

// -> https://training.desiqna.in 

// Link -> https://leetcode.com/discuss/post/6719472/meesho-oa-sde-1-by-anonymous_user-20ol/ 




// Understanding :-> Best way to travel the array such that sum is maximum as per the conditions given :-> 

// If you visit index “i” and “i+1” , “i-1” are unvisited; -> sum = sum + A[i] 

// -> If one of the adjacent indices is visited; sum = sum + B[i] 

// -> If both the adjacent indices are visited; sum = sum + C[i] 

// -> dp[i] = best journey possible if you have surely visited indices from “1” to “i” 















// Let dp(i)(j) denotes max efficiency of processors from [1...i], if
// j = 0, it means the processor is deployed after both processors i-1 and i+1
// ( i-1,i+1 —->i) 
// -> dp[i][0] -> best way to do your journey from 1 till “i” where we know that i-1,i+1 have already been visited in the sequence; 


// j=1, means i was deployed after i-1 and before i+1 (i-1→i—>i+1)
// j=2, means i was deployed before i-1 and after i+1 (i+1→i—>i-1) 
// j=3, means i was deployed before i-1 and i+1 (i —>i-1,i+1) 


// 2. Now can you form transitions yourself? It's not that tough.
// For example,
// dp(i)(0) = max { dp(i-1)(1), dp(i-1)(3) } + both_adjacent(i)
// dp(i)(1) = 
// dp(i)(2) = 
// dp(i)(3) = no_adjacent(i) + max({dp[i-1][0],dp[i-1][2]) 


// C++ - https://ideone.com/d4GHB6 . 
// Java - https://ideone.com/2DLNqR 
// Py - https://ideone.com/RaIWQ1 















// // Let dp(i)(j) denotes max efficiency of processors from [1...i], if
// // j = 0, it means the processor is deployed after both processors i-1 and i+1
// // ( i-1,i+1 —->i) 
// // -> dp[i][0] -> best way to do your journey from 1 till “i” where we know that i-1,i+1 have already been visited in the sequence; 


// // j=1, means i was deployed after i-1 and before i+1 (i-1→i—>i+1)
// // j=2, means i was deployed before i-1 and after i+1 (i+1→i—>i-1) 
// // j=3, means i was deployed before i-1 and i+1 (i —>i-1,i+1) 


// // 2. Now can you form transitions yourself? It's not that tough.
// // For example,
// // dp(i)(0) = max { dp(i-1)(1), dp(i-1)(3) } + both_adjacent(i)
// // dp(i)(1) = 
// // dp(i)(2) = 
// // dp(i)(3) = no_adjacent(i) + max({dp[i-1][0],dp[i-1][2]) 


// // C++ - https://ideone.com/d4GHB6 . 
// // Java - https://ideone.com/2DLNqR 
// // Py - https://ideone.com/RaIWQ1 






