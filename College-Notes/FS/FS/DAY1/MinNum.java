// You are given an array consisting of N integers, and an integer, K. 
// Your task is to determine the minimum element in subarrays of size K.

// Sample Input1:
// --------------
// 5
// 10 12 14 11 15
// 3

// Sample Output1:
// ---------------
// 10 11 11

// Sample Input2:
// --------------
// 5
// 5 2 1 1 1
// 4

// Sample Output2:
// ---------------
// 1 1

import java.util.*;

public class MinNum {
    public static void solve(int arr[], int k) {
        ArrayList<Integer> al = new ArrayList<>();
        int mini = Integer.MAX_VALUE;
        
        if(arr.length < k){
            System.out.println("Invalid");
            return;
        }
        for (int i = 0; i < k; i++) {
            al.add(arr[i]);
        }
        System.out.print(Collections.min(al)+" ");

        for (int i = k; i < arr.length; i++) {
            al.remove(i - k);
            al.add(arr[i]);
            System.out.print(Collections.min(al)+" ");

        }
    }

    public static void main(String[] args) {
        int arr[] = { 10,12,14,11,15 };
        solve(arr, 3);
    }
}
