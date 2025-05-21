import java.util.*;
public class ClosestPair {
    //give 2 sorted arrays and find pair close to target usng 2 pointer

    public static long[] closestPair(long[] arr1, long[] arr2, long target) {
        int n = arr1.length;
        int m = arr2.length;
        int i = 0;
        int j = m - 1;
        long diff = Long.MAX_VALUE;
        long[] res = new long[2];
        while (i < n && j >= 0) {
            long sum = arr1[i] + arr2[j];
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


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        long target = sc.nextLong();
        long[] arr1 = new long[n];
        long[] arr2 = new long[m];
        for (int i = 0; i < n; i++) {
            arr1[i] = sc.nextLong();
        }
        for (int i = 0; i < m; i++) {
            arr2[i] = sc.nextLong();
        }
        System.out.println(Arrays.toString(closestPair(arr1, arr2, target)));   
    }
}
