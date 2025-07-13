








// Understanding -> Pick subset of elements from array -> Sum of that subset should be maximum. 

// -> If you pick a group of 2 numbers; you can again do this operation only after ignoring 1 next number 

// -> You can select a group of 3 numbers as well -> but if you do that the next 2 numbers should not be selected and the same goes for the previous 2 numbers. 


// -> dp[......................................................................]

// -> dp[i] = the best answer for the array till index i 

// -> find the general formula for dp[i] 

// -> run a for loop and calculate dp[1],dp[2],..............dp[n]. 

// -> generally dp[n] is the final answer 

// -> dp[i] = maximum sum subset that can be picked till index “i” making sure the guy at index “i” is also included in the subset 


// -> here we are not able to keep track of how many elements we selected when we ended at index “i” 

// -> either we can select the last 2 elements or we can select the last 3 elements. 

// -> we need to make an extra state for the same. 


// ->dp[i][2] =  maximum sum subset that can be picked till index “i” making sure the guy at index “i” is also included in the subset and last 2 guys are for sure put in the subset 
 

// -> dp[i][3] = maximum sum subset that can be picked till index “i” making sure the guy at index “i” is also included in the subset + last 3 guys are for sure put in the subset 

// -> dp[i][2] = b[i] + b[i-1] + dp[i-3][2] 
//                  OR 
//                 = b[i] + b[i-1] + max(dp[i-4][2],dp[i-4][3]) 
//                  OR 
//                              = b[i]+b[i-1]+ max(dp[i-5][2],dp[i-5][3])
// .
// .
// .
// .
// .
// .
// .
// .
//                         = b[i] + b[i-1] + max(dp[1][2],dp[1][3])
//                        = b[i] + b[i-1] + ignore everything before it 


// ->dp[i][3] = b[i] + b[i-1] + b[i-2] + max(dp[i-5][3],dp[i-5][2]) 

//                OR
//                =  b[i] + b[i-1] + b[i-2] + max(dp[i-6][3],dp[i-6][2]) 
//                OR
// .
// .
// .
// .
// .
// .
// .
// .
// .
// .
// .
 
//               = b[i] + b[i-1] + b[i-2] + max(dp[1][3],dp[1][2])
//               = b[i] + b[i-1] + b[i-2] + ignore it all


// Final answer = max(dp[n][2],dp[n][3]),max(dp[1][2],dp[1][3]),max(dp[2][2],dp[2][3],dp[3][2],dp[3][3],dp[4][2],dp[4][3],...........................)  


// TC - O(N*N.) 

// Optimize to O(N) :- Use prefix array -> p2[i] = max(dp[i][2],dp[i-1][2],dp[i-3][2],..................dp[1][2]) 

// -> p3[i] = max(dp[i][3],dp[i-1][3],dp[i-3][3],..................dp[1][3]) 
// -> dp[i][2] = option 1 -> b[i] + b[i-1] + dp[i-3][2] 

//                 = option 2 -> b[i] + b[i-1] + max(p2[i-4],p3[i-4])

// -> dp[i][3] = b[i] + b[i-1] + b[i-2] + max(p3[i-5],p2[i-5]) 





#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxSubsetSum(vector<int>& b) {
    int n = b.size();
    b.insert(b.begin(), 0); // 1-based indexing

    vector<int> dp2(n + 1, 0), dp3(n + 1, 0);
    vector<int> p2(n + 1, 0), p3(n + 1, 0);

    int ans = 0;

    for (int i = 2; i <= n; i++) {
        // dp[i][2]
        int option1 = b[i] + b[i - 1] + ((i - 3 >= 0) ? dp2[i - 3] : 0);
        int option2 = b[i] + b[i - 1] + ((i - 4 >= 0) ? max(p2[i - 4], p3[i - 4]) : 0);
        dp2[i] = max(option1, option2);

        // dp[i][3]
        if (i >= 3) {
            int pick = b[i] + b[i - 1] + b[i - 2];
            int prevMax = (i - 5 >= 0) ? max(p2[i - 5], p3[i - 5]) : 0;
            dp3[i] = pick + prevMax;
        }

        // update prefix max
        p2[i] = max(p2[i - 1], dp2[i]);
        p3[i] = max(p3[i - 1], dp3[i]);

        ans = max({ans, dp2[i], dp3[i]});
    }

    return ans;
}

int main() {
    vector<int> b = {3, 5, 7, 2, 8, 1, 6}; // example input
    cout << "Maximum subset sum: " << maxSubsetSum(b) << endl;
    return 0;
}





// import java.util.*;

// public class MaxSubsetSum {

//     public static int maxSubsetSum(int[] b) {
//         int n = b.length;
//         int[] b1 = new int[n + 1];
//         System.arraycopy(b, 0, b1, 1, n); // 1-based indexing

//         int[] dp2 = new int[n + 1];
//         int[] dp3 = new int[n + 1];
//         int[] p2 = new int[n + 1];
//         int[] p3 = new int[n + 1];

//         int ans = 0;

//         for (int i = 2; i <= n; i++) {
//             int option1 = b1[i] + b1[i - 1] + ((i - 3 >= 0) ? dp2[i - 3] : 0);
//             int option2 = b1[i] + b1[i - 1] + ((i - 4 >= 0) ? Math.max(p2[i - 4], p3[i - 4]) : 0);
//             dp2[i] = Math.max(option1, option2);

//             if (i >= 3) {
//                 int pick = b1[i] + b1[i - 1] + b1[i - 2];
//                 int prevMax = (i - 5 >= 0) ? Math.max(p2[i - 5], p3[i - 5]) : 0;
//                 dp3[i] = pick + prevMax;
//             }

//             p2[i] = Math.max(p2[i - 1], dp2[i]);
//             p3[i] = Math.max(p3[i - 1], dp3[i]);

//             ans = Math.max(ans, Math.max(dp2[i], dp3[i]));
//         }

//         return ans;
//     }

//     public static void main(String[] args) {
//         int[] b = {3, 5, 7, 2, 8, 1, 6}; // example input
//         System.out.println("Maximum subset sum: " + maxSubsetSum(b));
//     }
// }
