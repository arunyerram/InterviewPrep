/*
 * You are given three sorted integer arrays A[], B[], and C[], and an integer target.

Your task is to find one element from each array (A[i], B[j], and C[k]) such that the sum of these three elements is equal to target.

If there is no exact match, return the triplet with the minimum absolute difference to the target.

Input Format:
-------------
Line 1: An integer N, the size of the first array.
Line 2: N space-separated integers representing elements of array A.
Line 3: An integer M, the size of the second array.
Line 4: M space-separated integers representing elements of array B.
Line 5: An integer P, the size of the third array.
Line 6: P space-separated integers representing elements of array C.
Line 7: An integer target, the required sum.

Output Format:
--------------
Line-1: Print the triplet (A[i], B[j], C[k]) that either matches the target or has the closest sum to the target.

Constraints:
------------
Time Complexity: O(N + M + P)
Space Complexity: O(1)

Sample Input-1:
---------------
4
5 10 20 30
4
1 3 7 10
4
2 5 8 12
25

Sample Output-1:
----------------
10 3 12

Explanation:
-------------
The sum 10 + 7 + 8 = 25, which exactly matches target.


Sample Input-2:
---------------
3
1 5 10
3
3 6 9
3
4 7 8
30

Sample Output-2:
----------------
10 9 8

Explanation:
------------
The sum 10 + 9 + 8 = 27, which is the closest sum to 30 (minimum absolute difference |30 - 27| = 3).
 */

import java.util.Scanner;

public class ClosestTripletSum {


    public static int[] closestPair(int[] arr1, int[] arr2, int target) {
        int n = arr1.length;
        int m = arr2.length;
        int i = 0;
        int j = m - 1;
        int diff = Integer.MAX_VALUE;
        int[] res = new int[2];
        while (i < n && j >= 0) {
            int sum = arr1[i] + arr2[j];
            if (Math.abs(sum - target) < diff) {
                diff = Math.abs(sum - target);
                res[0] = arr1[i];
                res[1] = arr2[j];
            }
            if (sum > target) {
                j--;
            } else {
                i++;
            }
        }
        return res;
    }

    public static void findClosestTriplet(int[] A, int[] B, int[] C, int target) {
        int n = A.length;
        int[] res = new int[3];
        int diff = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            int[] pair = closestPair(B, C, target - A[i]);
            int sum = A[i] + pair[0] + pair[1];
            if (Math.abs(sum - target) < diff) {
                diff = Math.abs(sum - target);
                res[0] = A[i];
                res[1] = pair[0];
                res[2] = pair[1];
            }
        }
        System.out.println(res[0] + " " + res[1] + " " + res[2]);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the input arrays and target value
        int n = sc.nextInt(); // Size of the first array A
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }

        int m = sc.nextInt(); // Size of the second array B
        int[] B = new int[m];
        for (int i = 0; i < m; i++) {
            B[i] = sc.nextInt();
        }

        int p = sc.nextInt(); // Size of the third array C
        int[] C = new int[p];
        for (int i = 0; i < p; i++) {
            C[i] = sc.nextInt();
        }

        int target = sc.nextInt(); // The target sum

        // Call the function to find the closest triplet
        findClosestTriplet(A, B, C, target); ///time complexity O(n+m+p)
    }
}
