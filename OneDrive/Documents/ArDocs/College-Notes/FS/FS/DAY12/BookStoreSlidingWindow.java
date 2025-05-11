/*
 * There is a bookstore owner that has a store open for n minutes. Every minute, some number of customers enter the store.
You are given an integer array customers of length n where customers[i] is the number of the customer
that enters the store at the start of the ith minute and all those customers leave after the end of that minute.

On some minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1
if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.

When the bookstore owner is grumpy, the customers of that minute are not satisfied, 
otherwise, they are satisfied.

The bookstore owner knows a secret technique to keep themselves not grumpy for minutes consecutive minutes, 
but can only use it once.

Return the maximum number of customers that can be satisfied throughout the day.
 
Sample Input-1:
---------------
8
1 0 1 2 1 1 7 5
0 1 0 1 0 1 0 1
3

Sample Output-1: 
----------------
16

Explanation:
------------
The bookstore owner keeps themselves not grumpy for the last 3 minutes. 
The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.

Sample Input-2:
---------------
1
1
0
1

Sample Output-2:
----------------
1
 

Constraints:

n == customers.length == grumpy.length
1 <= minutes <= n <= 2 * 104
0 <= customers[i] <= 1000
grumpy[i] is either 0 or 1.
 */

// import java.util.*;

// public class BookStoreSlidingWindow {
//     public static int maxSatisfied(int[] customers, int[] grumpy, int minutes) {
//         int n = customers.length;
//         int totalSatisfied = 0;

//         // Calculate the number of satisfied customers without using the secret
//         // technique
//         for (int i = 0; i < n; i++) {
//             if (grumpy[i] == 0) {
//                 totalSatisfied += customers[i];
//             }
//         }

//         // Calculate the additional satisfied customers we can get by using the secret
//         // technique
//         int maxAdditionalSatisfied = 0;
//         int currentAdditionalSatisfied = 0;

//         // Initial window
//         for (int i = 0; i < minutes; i++) {
//             if (grumpy[i] == 1) {
//                 currentAdditionalSatisfied += customers[i];
//             }
//         }
//         maxAdditionalSatisfied = currentAdditionalSatisfied;

//         // Slide the window
//         for (int i = minutes; i < n; i++) {
//             if (grumpy[i] == 1) {
//                 currentAdditionalSatisfied += customers[i];
//             }
//             if (grumpy[i - minutes] == 1) {
//                 currentAdditionalSatisfied -= customers[i - minutes];
//             }
//             maxAdditionalSatisfied = Math.max(maxAdditionalSatisfied, currentAdditionalSatisfied);
//         }

//         return totalSatisfied + maxAdditionalSatisfied;
//     }

//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         int n = sc.nextInt();
//         int[] customers = new int[n];
//         for (int i = 0; i < n; i++) {
//             customers[i] = sc.nextInt();
//         }
//         int[] grumpy = new int[n];
//         for (int i = 0; i < n; i++) {
//             grumpy[i] = sc.nextInt();
//         }
//         int minutes = sc.nextInt();
//         System.out.println(maxSatisfied(customers, grumpy, minutes));
//     }
// }

// import java.util.*;

// class Solution{
//     public static int solve(int arr[] ,int n, int grr[], int k){
//         int cnt = 0;
//         int maxi = Integer.MIN_VALUE;
//         int idx = 0;
//         int sum = 0;
//         for(int i=0 ; i<k ;i++){
//             sum += arr[i];
//         }
//         maxi = sum;
//         idx = 0;
//         for(int i = k;i<n;i++){
//             sum -= arr[i-k];
//             sum += arr[i];
//             if(maxi < sum){
//                 maxi = sum;
//                 idx = i;
//             }
//         }
//         cnt+=maxi;
//         for(int i=0;i<idx-2;i++){
//             if(grr[i] == 0){
//                 cnt = cnt+arr[i];
//             }
//         }
//         if((idx+3) > n){
//             return cnt;
//         }
//         for(int i=idx+3;i<n;i++){
//             cnt = cnt+arr[i];
//         }
//         return cnt;
//     }
//     public static void main(String args[]){
//         Scanner sc = new Scanner(System.in);
//         int n = sc.nextInt();
//         int arr[] = new int[n];
//         for(int i=0;i<n;i++){
//             arr[i] = sc.nextInt();
//         }
//         int grr[] = new int[n];
//         for(int i=0;i<n;i++){
//             grr[i] = sc.nextInt();
//         }
//         int k = sc.nextInt();
//         System.out.print(solve(arr,n,grr,k));
//     }
// }
import java.util.*;

class Solution {
    public int maxSatisfied(int[] cust, int[] grumpy, int minutes) {
        int n = cust.length;
        int k = minutes;
        int ans = 0;
        int max = 0;
        for (int i = 0; i < k; i++) {
            if (grumpy[i] == 1) {
                max += cust[i];
            }
        }
        int st = 0, end = k - 1;
        int sum = max;
        for (int i = k; i < n; i++) {
            if (grumpy[i - k] == 1) {
                sum -= cust[i - k];
            }
            if (grumpy[i] == 1) {
                sum += cust[i];
            }
            if (sum > max) {
                max = sum;
                st = i - k + 1;
                end = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (i >= st && i <= end) {
                ans += cust[i];
            } else {
                if (grumpy[i] == 0) {
                    ans += cust[i];
                }
            }
        }
        return ans;
    }
}