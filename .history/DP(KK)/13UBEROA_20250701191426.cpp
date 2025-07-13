
// You are given a positive integer 'N’. Your task is to find and return the minimum number of steps that 'N' has to take to get reduced to 1. 
// You can perform any one of the following 3 steps:
// 1) Subtract 1 from it. (n = n - ­1) ,
// 2) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
// 3) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).



// Algorithm:- https://ideone.com/Mctn4Q.  

// p1 = 1 + dp[i-1]

// if(i%2==0){
// p2 = 1 + dp[i/2]
// }

// if(i%3==0){
// p3 = 1 + dp[i/3]
// }

// dp[i] = min(p1,min(p2,p3)) 

// —--------------------------------------------------------------------

// Reduce n to 1 
// If the number is even you can divide it by 2. 
// If the number is odd you can do +1 or -1 

// C++ - https://ideone.com/4iHGKc
// Java - https://ideone.com/AjNRMh
// Py - https://ideone.com/pfNC8K



#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main() {
    
    int n = 5;
    
    int dp[n+1]={0};
    
    dp[1] = 0 ; 
    
    int i = 2 ; 
    while(i<=n){
    	
    	if(i%2 == 0){
    		
    		dp[i] = 1 + dp[i/2];
    		
    	}
    	
    	else{
    		
    		dp[i] = min(1+dp[i-1], 2+dp[(i+1)/2]);
    		
    	}
    	
        i++;
    }
    cout<<dp[n];
    return 0 ; 
}



// import java.util.Arrays;

// public class Main {
//     public static void main(String[] args) {
//         int n = 5;
//         int[] dp = new int[n + 1];

//         Arrays.fill(dp, 0);
//         dp[1] = 0;

//         for (int i = 2; i <= n; i++) {
//             if (i % 2 == 0) {
//                 dp[i] = 1 + dp[i / 2];
//             } else {
//                 dp[i] = Math.min(1 + dp[i - 1], 2 + dp[(i + 1) / 2]);
//             }
//         }
//         System.out.println(dp[n]);
//     }
// }
