

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




#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
ll dp[N][4];
ll A[N], B[N], C[N];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) cin >> A[i];
    for (int i = 1; i <= n; ++i) cin >> B[i];
    for (int i = 1; i <= n; ++i) cin >> C[i];

    // Base case initialization
    dp[1][0] = dp[1][1] = LLONG_MIN;
    dp[1][3] = A[1];
    dp[1][2] = B[1];

    for (int i = 2; i <= n; ++i) {
        dp[i][0] = max(dp[i-1][1], dp[i-1][3]) + C[i]; // both adjacent
        dp[i][1] = max(dp[i-1][1],dp[i-1][3]) + B[i]; // after i-1, before i+1
        dp[i][2] = max(dp[i-1][0],dp[i-1][2]) + B[i]; // after i+1, before i-1
        dp[i][3] = max(dp[i-1][0], dp[i-1][2]) + A[i]; // before both
    }

    // Invalidate illegal state at position n
    dp[n][2] = LLONG_MIN;
    dp[n][0] = LLONG_MIN; 
    // Final result
    ll result = max({dp[n][0], dp[n][1], dp[n][2], dp[n][3]});
    cout << result << "\n";

    return 0;
}




