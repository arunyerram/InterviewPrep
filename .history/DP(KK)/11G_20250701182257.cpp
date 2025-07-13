

// Given an integer “N” ; find the minimum cost to reduce it to 1
// The operations you can do are as follows.->

// i) Reduce the number by 1 in “y” dollars; 

// ii) Reduce the number by /7 in “x” dollars.(if number is divisible by 7)

// iii) Reduce the number by /3 in “z” dollars;(if number is divisible by 3)

// iv) Reduce the number by /5 in “b” dollars;(if number is divisible by 5) 

// (1<=n<=100000)


// Understanding :->

// N = 15 

// Y = 100 
// X = 1 
// Z = 500 
// B = 10000000












// C++ https://ideone.com/AkCp1q 
// Java. https://ideone.com/Sj8bDQ 
// Py https://ideone.com/Lldqtv 





#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main() {
    
    int n; 
    cin>>n; 
    int y,x,z,b;
    cin>>y>>x>>z>>b;
    
    int dp[n+1]={0};
    
    dp[1] = 0 ; 
    
    int i = 2 ; 
    while(i<=n){
        int v1 = dp[i-1] + y ; 
        int v2 = 1e8;
        int v3 = 1e8;
        int v4 = 1e8;
        if(i%7==0){
            v2 = dp[i/7] + x; 
        }
        if(i%3==0){
            v3 = dp[i/3] + z;
        }
        if(i%5==0){
            v4 = dp[i/5] + b;
        }
        
        dp[i] = min(v1,min(v2,min(v3,v4)));
        i++;
    }
    cout<<dp[n];
    return 0 ; 
}
















