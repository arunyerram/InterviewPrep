
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }


    ll ans = 0;
    
//     You are given an array of N integers. You can either take an element and add it to your sum or skip it. However, if you take an element, you cannot take the next element. Find the maximum sum you can obtain.
// Constraints:
// 1<=N<=100000
// -100000<=A[i]<=100000 

// Analysis :-> If you select index “i” -> i+1 or i-1 cannot be selected; 

// :-> dp[i][0] => best sum you can get till index “i” but element at index i should not be included in the sum; 

// :-> dp[i][1] => best sum you can get till index “i” but element index i should be included in the sum; 

// -> dp[i][1] => b[i] + dp[i-1][0]; 
// -> dp[i][0] => max(dp[i-1][0],dp[i-1][1]); 

// => Final answer = max(dp[n][0],dp[n][1]); 

    



    return 0;
}
