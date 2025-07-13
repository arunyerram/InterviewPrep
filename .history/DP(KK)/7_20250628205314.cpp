
// atcoder.............DP




#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 

int main() {
    ll n ; 
    cin>>n ; ll b[n+1] = {0};
    ll i = 1 ; 
    while(i<=n){
        cin>>b[i] ; 
        i++;
    }
    
    
    ll dp[n+1] = {0};
    
    dp[1] = 0 ; 
    dp[2] = abs(b[1]-b[2]);
    i = 3 ; 
    while(i<=n){
        
        dp[i] = min(dp[i-1] + abs(b[i]-b[i-1]) ,dp[i-2] + abs(b[i]-b[i-2]));
        
        i++;
    }
    
    cout<<dp[n] ; 
    
    return 0 ; 
}


// import java.util.Scanner;

// public class Main {
//     public static void main(String[] args) {
//         Scanner scanner = new Scanner(System.in);
//         int n = scanner.nextInt();
//         long[] b = new long[n+1];
        
//         for (int i = 1; i <= n; i++) {
//             b[i] = scanner.nextLong();
//         }
        
//         long[] dp = new long[n+1];
        
//         dp[1] = 0;
//         dp[2] = Math.abs(b[1] - b[2]);
        
//         for (int i = 3; i <= n; i++) {
//             dp[i] = Math.min(dp[i-1] + Math.abs(b[i] - b[i-1]), dp[i-2] + Math.abs(b[i] - b[i-2]));
//         }
        
//         System.out.println(dp[n]);
//     }
// }
