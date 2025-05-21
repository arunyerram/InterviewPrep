#include<bits/stdc++.h>
using namespace std;

// :-> https://training.desiqna.in 
// Paint Fence (Advanced DP)
// Problem:
// You have N fence posts and K colors. You cannot paint > two adjacent fences the same color. Find the number of ways to paint the fence.


// N = 3 ; K = 2
// :-> 6 WAYS;
// {
// 121
// 211
// 112
// 122
// 221
// 212 //RRRRR


// }
 
// Understanding :-> Tell how many arrays exist of size “N” such that each number in the array is from “1 ….. K” but any 3 consecutive elements should not be the same. 

// -> dp[i] = count of arrays of size “i” which are valid; 

// -> dp[i] will not work because we need to know which colors are at index i,i-1 => are they the same?

// -> dp1[i] = number of valid arrays of size “i” such that “i” color != “i-1” color 

// -> dp2[i] 
// => number of valid arrays of size “i” such that “i” color is equal to “i-1” color 

// For n=3;k=2;k=3;
// -> dp2[3] = dp1[2];

// -> dp2[i] = dp1[i-1] 

// -> dp1[3] = (dp1[2] + dp2[1])*2;
// -> dp1[i] = (dp1[i-1] + dp2[i-1])*(k-1) 

// -> Final answer = (dp1[n] + dp2[n]) 

// You have N fence posts and K colors. You cannot paint > three; adjacent fences the same color. Find the number of ways to paint the fence.

// -> dp1[i] = last!=second_last 
// -> dp2[i] = last=second_last
// -> dp3[i] = last=second_last=third_last 



// -> dp3[i] = (total_valid(i-3)*k-1)) 
// -> total(i) = dp1[i] + dp2[i] + dp3[i] 

// -> dp2[i] = (total_valid(i-2)*k-1)) 

// -> dp1[i] = (total_valid(i-1)*k-1))


// 4 2
// 1101, 1100, 1011, 1001, 0110, 0101, 0011, 0001, 1110, 1111, 1100, 1010, 1000, 0111, 0100, 0010



// ..........................// code sHould do/.............. 



int main(){

    int n;
    int k;
    cin>>n>>k;

    // vector<int>q;
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     q.push_back(x);
    // }
    // int cnt = 0;
    int dp1[n + 1];
    int dp2[n + 1];
    int dp3[n + 1];

    dp1[0] = 0;
    dp2[0] = 0;
    dp3[0] = 0;

    for(int i=1;i<=n;i++){
        if(i == 1){
            dp1[i] = 1;
            dp2[i] = 0;
            dp3[i] = 0;
        }
        else{
            dp1[i] = (dp1[i-1] + dp2[i-1] + dp3[i-1]) * (k - 1);
            dp2[i] = (dp1[i-2]  + dp2[i-2] + dp3[i-2]) * (k - 1);
            if(i >= 3)
                dp3[i] = (dp1[i-3] + dp2[i-3] + dp3[i-3]) * (k - 1);
            else 
                dp3[i] = 0;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dp1[i]<<" "<<dp2[i]<<" "<<dp3[i]<<endl;
    }
    // cout<<dp1[n]<<endl;
    // cout<<dp2[n]<<endl;
    // cout<<dp3[n]<<endl;
    cout<<dp1[n] + dp2[n] + dp3[n]<<endl;
    return 0;
}