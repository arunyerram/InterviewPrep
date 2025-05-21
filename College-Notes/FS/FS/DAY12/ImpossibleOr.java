/*
 * 
 * You are given a 0-indexed integer array nums.

We say that an integer x is expressible from nums if there exist some integers 0 <= index1 < index2 < ... < indexk < nums.length for which nums[index1] | nums[index2] | ... | nums[indexk] = x. In other words, an integer is expressible if it can be written as the bitwise OR of some subsequence of nums.

Return the minimum positive non-zero integer that is not expressible from nums.

Sample Input-1:
---------------
2
2 1

Sample Output-1:
----------------
4

Explanation: 
------------
1 and 2 are already present in the array. We know that 3 is expressible, since nums[0] | nums[1] = 2 | 1 = 3. 
Since 4 is not expressible, we return 4.

Sample Input-2:
---------------
3
5 3 2

Sample Output-2: 
----------------
1

Explanation: We can show that 1 is the smallest number that is not expressible.
 

Constraints:
------------
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9

 */

// import java.util.*;

// public class ImpossibleOr{
    
//     public static int solve(int arr[] ,int n){
//         int mini = Integer.MAX_VALUE;
//         Arrays.sort(arr);
//         Set<Integer> s = new HashSet<>();
//         for(int i=0;i<n-1;i++){
//             for(int j=i+1;j<n;j++){
//                 int res = arr[i] | arr[j];
//                 mini = Math.min(mini, res);
//             }
//             s.add(arr[i]);
//         }
//         s.add(arr[n-1]);
        
//         int itr = Math.max(mini, arr[n-1]);
//         for(int i=1;i<=itr;i++){
//             if(!s.contains(i) && i<mini){
//                 return i;
//             }
//         }
//         return mini+1;
        
//     }
    
//     public static void main(String args[]){
//         Scanner sc = new Scanner(System.in);
//         int n = sc.nextInt();
//         int arr[] = new int[n];
//         for(int i=0;i<n;i++){
//             arr[i] = sc.nextInt();
//         }
//         System.out.print(solve(arr, n));
//     }
// }

// // import java.util.*;

// // public class ImpossibleOr {
// //     public static int solve(int[] nums, int n) {
// //         Arrays.sort(nums);
// //         int smallestNonExpressible = 1;

// //         for (int num : nums) {
// //             if (num > smallestNonExpressible) {
// //                 break;
// //             }
// //             smallestNonExpressible |= num;
// //         }

// //         return smallestNonExpressible + 1;
// //     }

// //     public static void main(String[] args) {
// //         Scanner sc = new Scanner(System.in);
// //         int n = sc.nextInt();
// //         int[] nums = new int[n];
// //         for (int i = 0; i < n; i++) {
// //             nums[i] = sc.nextInt();
// //         }
// //         System.out.println(solve(nums, n));
// //     }
// // }

import java.util.*;

public class ImpossibleOr{
    public static int solve(int arr[], int n){
        int mini = 1;
        Set<Integer> s = new HashSet<>();
        s.add(0);
        
        for(int a: arr){
            List<Integer> al = new ArrayList<>(s);
            for(int val : al){
                s.add(a | val);
            }
        }
        
        while(s.contains(mini)){
            mini++;
        }
        
        return mini;
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        System.out.print(solve(arr, n));
    }
}