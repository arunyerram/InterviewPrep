import java.util.*;
// Given an array of integers of size ‘n’.  Our aim is to calculate the maximum sum of ‘k’ consecutive elements in the array. using sliding window technique. 
public class SlidingWindow_LargetsSum {

    static int maxSum(int arr[], int n, int k) {
        int maxSum = 0;
        // Calculate the sum of first k elements of window of size k
        for (int i = 0; i < k; i++) {
            maxSum += arr[i];
        }

        // Calculate the sum of remaining elements by removing the first element of the previous window and adding the last element of the current window
        int windowSum = maxSum;
        for (int i = k; i < n; i++) {
            windowSum += arr[i] - arr[i - k];
            maxSum = Math.max(maxSum, windowSum);
        }

        return maxSum;

    }

    public static void main(String[] args) {
        int arr[] = { 1, 8, 30, -5, 20, 7 };
        int n = arr.length;
        int k = 3;
        System.out.println(maxSum(arr, n, k));
    }

}