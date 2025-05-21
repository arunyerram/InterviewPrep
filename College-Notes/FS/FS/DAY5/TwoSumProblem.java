/*
 * You are given a 1-indexed array of integers, numbers, sorted in non-decreasing order. 
Your task is to find two distinct numbers in the array such that their sum equals a given target.

Return their 1-based indices as an array [index1, index2], where 1 ≤ index1 < index2 ≤ numbers.length.

Constraints:
------------
-> There is exactly one valid solution.
-> You cannot use the same element twice.
-> Your solution must use only constant extra space.

Input Format:
-------------
Line-1: An integer N, representing the size of the array.
Line-2: N space-separated integers, representing the array elements.
Line-3: An integer X, representing the target sum.

Output Format:
--------------
Line-1: Print indices as an array if there exists a pair whose sum is equal to X

Sample Input-1:
---------------
4
2 7 11 15
9

Sample Output-1:
----------------
[1, 2]

Explanation:
-------------
The sum of 2 and 7 is 9.
Their 1-based indices are 1 and 2.

Sample Input-2:
---------------
3
2 3 4
6

Sample Output-2:
----------------
[1, 3]

Explanation:
------------
The sum of 2 and 4 is 6.
Their 1-based indices are 1 and 3.

Sample Input-3:
---------------
2
-1 0
-1

Sample Output-3:
----------------
[1, 2]

Explanation:
------------
The sum of -1 and 0 is -1.
Their 1-based indices are 1 and 2.



 */

import java.util.*;
public class TwoSumProblem {
    public static int[] twoSum(int[] nums, int target) {

        //use 2 ptr approach

        int[] result = new int[2];
        int n = nums.length;
        int i = 0, j = n - 1;

        while (i < j) {
            if (nums[i] + nums[j] == target) {
                result[0] = nums[i];
                result[1] = nums[j];
                return result;
            } else if (nums[i] + nums[j] < target) {
                i++;
            } else {
                j--;
            }
        }
        return result;
        }
    public static void main(String[] args) {
        int[] arr = {2, 7, 11, 15};
        int target = 220;
        int[] result = twoSum(arr, target);
        System.out.println(result[0] + " " + result[1]);
    }
}
