

// dp[1][1][1] = a[1]%2 == 0?1:0;
// dp[1][1][2] = a[1]%2 != 0?1:0;

// i from 2 to n....
// if(a[i]%2 == 0)
// dp[i][1][1]  = dp[i-1][1][1] + dp[i-1][2][1];
// else 
// dp[i][1][1] = dp[i-1][1][2] + dp[i-1][2][2];

// if(a[i]%2 == 0)
// dp[i][1][2] = dp[i-1][1][1] + dp[i-1][2][1];
// else
// dp[i][1][2] = dp[i-1][1][1] + dp[i-1][2][1];

// if(b[i]%2 == 0)
// dp[i][2][1] = dp[i-1][2][1] + dp[i-1][1][1];
// else 
// dp[i][2][1] = dp[][][]  +  dp[][][]; 


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[100005][2][2];








