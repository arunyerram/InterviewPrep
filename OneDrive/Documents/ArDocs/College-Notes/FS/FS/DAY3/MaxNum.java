
// import java.util.*;

// public class MaxNum {
//     public static void solve(int arr[], int k) {
//         if (k > arr.length) {
//             System.out.println(0);
//             return;
//         }
//         ArrayList<Integer> al = new ArrayList<>();

//         // int maxi = Integer.MIN_VALUE;

//         if (arr.length < k) {
//             System.out.println("Invalid");
//             return;
//         }
//         for (int i = 0; i < k; i++) {
//             al.add(arr[i]);
//         }
//         System.out.print(Collections.max(al) + " ");

//         for (int i = k; i < arr.length; i++) {
//             al.remove(0);
//             al.add(arr[i]);
//             System.out.print(Collections.max(al) + " ");

//         }
//     }

//     public static void main(String[] args) {
//         Scanner sc = new Scanner(System.in);
//         int n = sc.nextInt();
//         int k = sc.nextInt();
//         int arr[] = new int[n];
//         for (int i = 0; i < n; i++) {
//             arr[i] = sc.nextInt();
//         }
//         solve(arr, k);
//     }
// }

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class MaxOfAllSubarraysOfSizeK {
    private static int[] maxofAllSubarray(int[] a, int k) {
        int n = a.length;
        int[] maxOfSubarrays = new int[n - k + 1];
        int idx = 0;
        PriorityQueue<Integer> q = new PriorityQueue<>(Comparator.reverseOrder());
        int windowStart = 0;
        for (int windowEnd = 0; windowEnd < n; windowEnd++) {
            q.add(a[windowEnd]);
            if (windowEnd - windowStart + 1 == k) {
                /*
                 * We've hit the window size. Find the maximum in the current
                 * window and Slide the window ahead
                 */
                int maxElement = q.peek();
                maxOfSubarrays[idx++] = maxElement;
                if (maxElement == a[windowStart]) {
                    /*
                     * Discard a[windowStart] since we are sliding the window
                     * now. So, it is going out of the window.
                     */
                    q.remove();
                }
                windowStart++; // Slide the window ahead
            }
        }
        return maxOfSubarrays;
    }

public static void main(String[] args)
{
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int[] a = new int[n];
COMPETITIVE PROGRAMMING UNIT-I III –II SEM(KR21)
for(int i = 0; i < n; i++)
{
a[i] = sc.nextInt();
}
int k = sc.nextInt();
int[] result = maxofAllSubarray(a, k);
for(int i = 0; i < result.length; i++)
{
System.out.print(result[i] + " ");
}
}
}