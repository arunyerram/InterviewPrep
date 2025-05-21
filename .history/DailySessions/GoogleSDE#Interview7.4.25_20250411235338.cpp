
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll arr[n + 1];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    ll k;
    cin>>k;

    ll ans = 0;

    vector<vector<ll>>dp(n  + 1,vector<ll>(2,-1));

    for(int i=1;i<=n;i++){
        if(i==1){
            dp[i][0] = 0;
            dp[i][1] = arr[i];
        }else{
            dp[i][0] = max(dp[i-1][1],dp[i-1][0]);
            if(i - k >= 0)
                dp[i][1] = arr[i] + max(dp[i-k-1][1],dp[i-k-1][0]);
        }
        ans = max(ans,max(dp[i][0],dp[i][1]));
    }

    return 0;
}
    
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







// -> You are given an array of N integers (both positive and negative). You can either take an element and add it to your sum or skip it. However, if you take an element, you must skip the next K elements. Find the maximum sum you can obtain.

// -> If question stated to skip >=K after each pick still it would mean same as above question; 

// Analysis :-> If you select index “i” :-> You cannot select :- i+1,i+2,i+3,.......i+k and similarly you cannot select i-1,i-2,i-3,.....i-k 

// -> dp[i][0] =>  best sum you can get till index “i” but element at index i should not be included in the sum;  (journey is of special type where you ignore K elements after selecting “i”) 

// :-> dp[i][1] => best sum you can get till index “i” but element at index i should be included in the sum; (special type journey :- where you ignore K elements after selecting “i”) 

// => dp[i][0] = max(dp[i-1][1],dp[i-1][0]) 

// => dp[i][1] = b[i] + max(dp[i-k-1][1],dp[i-k-1][0])

    
