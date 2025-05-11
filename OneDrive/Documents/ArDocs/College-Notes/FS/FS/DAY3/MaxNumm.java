
import java.util.*;

public class MaxNumm {
    public static void solve(int arr[], int k) {
        if (k > arr.length) {
            System.out.println(0);
            return;
        }
        ArrayList<Integer> al = new ArrayList<>();

        // int maxi = Integer.MIN_VALUE;

        if (arr.length < k) {
            System.out.println("Invalid");
            return;
        }
        for (int i = 0; i < k; i++) {
            al.add(arr[i]);
        }
        System.out.print(Collections.max(al) + " ");

        for (int i = k; i < arr.length; i++) {
            al.remove(0);
            al.add(arr[i]);
            System.out.print(Collections.max(al) + " ");

        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int k = sc.nextInt();
        solve(arr, k);
    }
}
