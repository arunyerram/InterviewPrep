/*
 Given a string s, reverse only all the vowels in the 
string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can 
appear in both lower and upper cases, more than once.

Sample Input-1:
---------------
hello

Sample Output-1:
----------------
holle

Sample Input-2:
----------------
Keshavmemorial

Sample Output-2:
----------------
Kashivmomerael

 */

import java.util.*;

public class RotateArray {
    public static void rotate(int[] nums, int k) {
        int n = nums.length;
        k = k % n; // Handle cases where k > n

        reverse(nums, 0, n - 1); // Step 1: Reverse the entire array
        reverse(nums, 0, k - 1); // Step 2: Reverse first k elements
        reverse(nums, k, n - 1); // Step 3: Reverse the remaining elements
    }

    private static void reverse(int[] nums, int left, int right) {
        while (left < right) {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];

        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        int k = sc.nextInt();

        rotate(nums, k);

        for (int num : nums) {
            System.out.print(num + " ");
        }
        sc.close();
    }
}
