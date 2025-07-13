


// -> There are two arrays , 'B' and 'C' ; size of both the arrays is 'N' ;

// -> At each index you are supposed to pick up an element either from array 'C' or array 'B'

// ->You have to maximize the final sum of all elements

// ->Condition : You cannot select 3 or more than 3 element consecutively from the same array.

// Example :

// 3

// 5 10

// 3 10

// 4 10

// Output : 25

// 1<=N<=100000

// 1<=B[i];C[i]<=10000000000


#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 
ll dp[100000+5][5][5];

ll mxi(ll x,ll y,ll z){
    
    
    return max(x,max(y,z));
    
}

ll mx(ll x,ll y,ll z,ll g){
    
    return max(max(x,g),max(y,z));
}

int main() {
    
    ll n;
    cin>>n ; 
    
    ll i = 1 ; ll b[n+1] = {0};
    ll d[n+1] = {0};
    while(i<=n){
        cin>>b[i];
        cin>>d[i];
        i++;
    }
    
    //base-cases
    dp[1][1][1] = b[1] ; 
    dp[1][1][2] = b[1] ; 
    dp[1][2][1] = d[1] ; 
    dp[1][2][2] = d[1] ; 
    
    
    //dp[index][][]
       
    i = 2 ; 
    while(i<=n){
        
        dp[i][1][1] = b[i] + b[i-1] + max(dp[i-2][2][2],dp[i-2][2][1]);
        dp[i][1][2] = b[i] + d[i-1] + mxi(dp[i-2][1][1],dp[i-2][1][2],dp[i-2][2][1]);
        dp[i][2][1] = d[i] + b[i-1] + mxi(dp[i-2][2][1],dp[i-2][2][2],dp[i-2][1][2]);
        dp[i][2][2] = d[i] + d[i-1] + max(dp[i-2][1][2],dp[i-2][1][1]);
        
        i++;
    }
    
    cout<<mx(dp[n][1][1],dp[n][1][2],dp[n][2][2],dp[n][2][1]); 
    
    
    
    
    
    return 0 ; 
}