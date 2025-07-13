
// ******************************************************************//////////


// There are 'n' stones in a row from 0 to n-1. For every ith stone , there are 2 values associated with it, a[i] and b[i] . You have to remove all the stones from the row one by one. Removing the ith stone follows the rule :

 

 

// If (i-1)th and (i+1)th stones are still present , then , cost of removing the ith stone is b[i].

 

 

// if either (i-1)th or (i+1)th stone is present , then cost of removing the ith stone is a[i].

 

 

// if neither (i-1)th nor (i+1)th stone is present , the cost of removing the ith stone is 0.

 

 

// Find the minimum total cost of removing all the stones.

// Constraints :
// 1 <= n <= 50000
// 1 <= a[i] , b[i] <= 1000




#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int b[n+1], a[n+1];
    
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    int dp[n+1][3]; // Using 3 columns for simplicity
    
    dp[2][1] = a[2]; // 1--- last
    dp[2][2] = a[1]; // 2--- second last
    dp[1][2] = 0 ;
    dp[1][1] = 0 ; 
    
    for (int i = 3; i <= n; ++i) {
        dp[i][1] = a[i] + min(dp[i-1][1], dp[i-1][2]);
        
        int v1 = b[i-1] + min(dp[i-2][1], dp[i-2][2]);
        int v5 = dp[i-1][2] + a[i-1]; // 1 min answer of both
        
        dp[i][2] = min(v1, v5);
    }

    // cout << dp[3][1] << " " << dp[3][2] << endl;
    
    cout << min(dp[n][1], dp[n][2]) << endl;

    return 0;
}




// import java.util.Scanner;

// public class Main {
//     public static void main(String[] args) {
//         Scanner scanner = new Scanner(System.in);
//         int n = scanner.nextInt();

//         int[] b = new int[n + 1];
//         int[] a = new int[n + 1];

//         for (int i = 1; i <= n; ++i) {
//             b[i] = scanner.nextInt();
//         }

//         for (int i = 1; i <= n; ++i) {
//             a[i] = scanner.nextInt();
//         }

//         int[][] dp = new int[n + 1][3]; // Using 3 columns for simplicity

//         dp[2][1] = a[2]; // 1--- last
//         dp[2][2] = a[1]; // 2--- second last
//         dp[1][2] = 0;
//         dp[1][1] = 0;

//         for (int i = 3; i <= n; ++i) {
//             dp[i][1] = a[i] + Math.min(dp[i - 1][1], dp[i - 1][2]);

//             int v1 = b[i - 1] + Math.min(dp[i - 2][1], dp[i - 2][2]);
//             int v5 = dp[i - 1][2] + a[i - 1]; // 1 min answer of both

//             dp[i][2] = Math.min(v1, v5);
//         }

//         System.out.println(dp[3][1] + " " + dp[3][2]);
//         System.out.println(Math.min(dp[n][1], dp[n][2]));

//         scanner.close();
//     }
// }
