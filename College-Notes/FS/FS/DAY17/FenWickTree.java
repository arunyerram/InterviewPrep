/*
 * Malika taught a new fun time program practice for Engineering Students.
As a part of this she has given set of N numbers, and asked the students 
to perform the operations listed below:
1. sumRange(start, end) - return the sum of numbers between the indices start and end, both are inclusive.
2. update(ind, val) - update the value at the index 'ind' to 'val'.

Your task is to solve this problem using Fenwick Tree concept.

Input Format:
-------------
Line-1: Two integers N and Q, size of the array(set of numbers) and query count.
Line-2: N space separated integers.
next Q lines: Three integers option, start/ind and end/val.

Output Format:
--------------
An integer result, for every sumRange query.


Sample Input-1:
---------------
8 5
1 2 13 4 25 16 17 8
1 2 6		//sumRange
1 0 7		//sumRange
2 2 18	//update
2 4 17	//update
1 2 7		//sumRange

Sample Output-1:
----------------
75
86
80



Sample Input-2:
---------------
8 5
1 2 13 4 25 16 17 8
1 2 6		
1 0 7		
2 2 18	
2 4 17	
1 0 7

Sample Output-2:
----------------
75
86
83

 */

import java.util.*;

public class FenWickTree {
    int arr[];
    int n;
    int BIT[];

    public FenWickTree(int nums[], int n) {
        this.n = n;
        this.arr = nums;
        BIT = new int[n + 1];

        for (int i = 0; i < n; i++) {
            init(i, arr[i]);
        }
    }

    public void init(int i, int val) {
        i++;
        while (i <= n) {
            BIT[i] += val;
            i += (i & -i);
        }
        // System.out.println(i+":"+Arrays.toString(BIT));
    }

    public void update(int i, int val) {
        int diff = val - arr[i];
        arr[i] = val;
        init(i, diff);
    }

    public int getsum(int idx) {
        int sum = 0;
        idx++;
        while (idx > 0) {
            sum += BIT[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    public int sumRange(int start, int end) {
        return getsum(end) - getsum(start - 1);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int nums[] = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        FenWickTree ft = new FenWickTree(nums, n);
        while (k > 0) {
            int op = sc.nextInt();
            if (op == 1) {
                int start = sc.nextInt();
                int end = sc.nextInt();
                System.out.println(ft.sumRange(start, end));
            } else {
                int idx = sc.nextInt();
                int val = sc.nextInt();
                ft.update(idx, val);
            }
            k = k - 1;
        }
    }
}
