/*
 * You are given three sorted integer arrays A[], B[], and C[]. 

Your task is to find one element from each array (A[i], B[j], and C[k]) 
such that the following expression is minimized:
    
   x =  max(∣A[i]−B[j]∣,∣B[j]−C[k]∣,∣C[k]−A[i]∣)
where |x| denotes the absolute value of x.

You need to return the three selected elements A[i], B[j], and C[k] that result in the minimum possible value of the above expression.

Input Format:
-------------
Line-1: An integer n, the size of array A, followed by n space-separated integers representing array A.
Line-2: An integer m, the size of array B, followed by m space-separated integers representing array B.
Line-3: An integer p, the size of array C, followed by p space-separated integers representing array C.

Output Format:
--------------
Line-1: Print three space-separated integers A[i] B[j] C[k] that minimize the given expression.


Sample Input-1:
---------------
3
1 4 10
3
2 15 20
2
10 12

Sample Output-1:
----------------
10 15 10

Sample Input-2:
---------------
24 22 23

Sample Output-1:
----------------
10 15 10

Sample Input-2:
---------------
3
0 0 0
1

Sample Output-2:
----------------
0
 */

 import java.util.*;

public class MinimizedDifference {
    public static void solve(int[] A, int[] B, int[] C) {
        int n = A.length, m = B.length, p = C.length;
        int i = 0, j = 0, k = 0;
        int minDiff = Integer.MAX_VALUE;
        int resultA = 0, resultB = 0, resultC = 0;
        
        // Iterate until one of the arrays is completely traversed
        while (i < n && j < m && k < p) {
            // Current values from each array
            int valA = A[i], valB = B[j], valC = C[k];
            
            // Calculate the current maximum difference
            int currentMaxDiff = Math.max(Math.abs(valA - valB), 
                                          Math.max(Math.abs(valB - valC), Math.abs(valC - valA)));
            
            // Update result if a smaller max difference is found
            if (currentMaxDiff < minDiff) {
                minDiff = currentMaxDiff;
                resultA = valA;
                resultB = valB;
                resultC = valC;
            }
            
            // Move the pointer that points to the smallest element
            if (valA <= valB && valA <= valC) {
                i++;  // Move pointer of array A
            } else if (valB <= valA && valB <= valC) {
                j++;  // Move pointer of array B
            } else {
                k++;  // Move pointer of array C
            }
        }
        
        // Output the result
        System.out.println(resultA + " " + resultB + " " + resultC);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        
        // Input arrays
        int n = sc.nextInt();
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }
        
        int m = sc.nextInt();
        int[] B = new int[m];
        for (int i = 0; i < m; i++) {
            B[i] = sc.nextInt();
        }
        
        int p = sc.nextInt();
        int[] C = new int[p];
        for (int i = 0; i < p; i++) {
            C[i] = sc.nextInt();
        }
        
        solve(A, B, C);
    }
}
