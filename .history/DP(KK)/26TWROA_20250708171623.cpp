
// You are given an array A. Size = N. You start at index 1 and end at index N. Find the number of ways to reach from index 1 to index N. 

// You have to follow some conditions. 

// Each number A[i] = 1 or 2 ; if you are at index i you can make a jump of size from range [1…..A[i]] 


// -> You can visit each index utmost once. 

// dp[...............................................................] 

// dp[i] = number of ways to reach index “i” 


// C++ - https://ideone.com/eH0IL4
// Java- https://ideone.com/w4GW2y
// Py - https://ideone.com/Mc8nPm


// Real :- You are allowed to jump backwards also but utmost 1 time. 

 
// dp[i][0] = number of ways to reach index “i” such that 0 backward jumps are made. 

// dp[i][1] = one backward jump allowed. (but the last jump is not backward.) 


// Final answer = dp[n][0] + dp[n][1] 


// Big observation :- You can never make -2 jump as it will block your path to reach the final index N.

// dp[i][0] = dp[i-1][0] 

// if(b[i-2]==2){
// dp[i][0] = dp[i][0] + dp[i-2][0]
// }


// dp[i][1] = dp[i-1][1] + dp[i-2][1] + dp[i-3][0]



// C++ - https://ideone.com/X20k1T 
// Java - https://ideone.com/Uzr9gl
// Py - https://ideone.com/WDoGZj

// https://drive.google.com/file/d/1zNnttm33M1ISOcp8g0gIcSmhyAU_bHC2/view

https://drive.google.com/file/d/1khZoXoiU1XjYFqkWJcd_LmyMhs9UBnqN/view


#include <iostream>
using namespace std;

int countSequences(int n, int b[]) {
    int dp[n + 1][2] = {{0}};

    dp[1][0] = 1;
    dp[2][0] = 1;

    for (int i = 3; i <= n; i++) {
    	
        dp[i][0] = dp[i - 1][0];
        
        if (b[i - 2] == 2) {
            dp[i][0] += dp[i - 2][0];
        }

        dp[i][1] = dp[i - 1][1];
        
        if(b[i-2] == 2)
        dp[i][1] += dp[i - 2][1];
        
        if(b[i-3] == 2 and b[i-2] == 2)
        dp[i][1] += dp[i - 3][0];
    }

    return dp[n][0] + dp[n][1];
}

int main() {
    int n = 5;
    int b[] = {1, 2, 1, 1, 2}; // Example array b

    cout << countSequences(n, b) << endl;

    return 0;
}



// public class Main {
//     public static int countSequences(int n, int[] b) {
//         int[][] dp = new int[n + 1][2];

//         dp[1][0] = 1;
//         dp[2][0] = 1;

//         for (int i = 3; i <= n; i++) {
//             dp[i][0] = dp[i - 1][0];
//             if (b[i - 2] == 2) {
//                 dp[i][0] += dp[i - 2][0];
//             }

//             dp[i][1] = dp[i - 1][1];
//             if (b[i - 2] == 2)
//                 dp[i][1] += dp[i - 2][1];
//             if (b[i - 3] == 2 && b[i - 2] == 2)
//                 dp[i][1] += dp[i - 3][0];
//         }

//         return dp[n][0] + dp[n][1];
//     }

//     public static void main(String[] args) {
//         int n = 5;
//         int[] b = {1, 2, 1, 1, 2}; // Example array b

//         System.out.println(countSequences(n, b));
//     }
// }





