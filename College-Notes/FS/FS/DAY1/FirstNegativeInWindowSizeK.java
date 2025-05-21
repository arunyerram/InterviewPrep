import java.util.*;

public class FirstNegativeInWindowSizeK {
    public static ArrayList<Integer> solve(int arr[], int k) {
        ArrayList<Integer> al = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();

        for (int i = 0; i < k; i++) {
            if (arr[i] < 0) {
                q.add(arr[i]);
            }
        }

        if (!q.isEmpty()) {
            al.add(q.peek());
        } else {
            al.add(0);
        }

        for (int i = k; i < arr.length ; i++) {
            if (!q.isEmpty() && q.peek() == arr[i - k]) {
                q.poll();
            }

            if (arr[i] < 0) {
                q.add(arr[i]);
            }

            if (!q.isEmpty()) {
                al.add(q.peek());
            } else {
                al.add(0);
            }
        }

        return al;

    }

    public static void main(String[] args) {
        int[] arr = { 12, -1, -2, 8, -16, 30, 16, 28 };
        int k = 3;
        // here in this problem, we have been provided with an array and a window length
        // for each sub-array of size k, we need to find the first negative element that
        // occurred in it
        // answer will be again in form of an array, which will either have the negative
        // element that encountered first in that window
        // or it will be zero representing there was no negative element in that
        // sub-array

        // print the result
        System.out.println(solve(arr, k));
    }
}