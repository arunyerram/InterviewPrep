import java.util.ArrayList;

public class MaxSlidingWindow {
    public static ArrayList<Integer> solve(int arr[], int k) {
        ArrayList<Integer> al = new ArrayList<>();
        int prevMaxIndex = 0;

        for (int i = 0; i < k; i++) {
            if (arr[i] >= arr[prevMaxIndex]) {
                prevMaxIndex = i;
            }
        }

        al.add(arr[prevMaxIndex]);

        for (int i = k; i < arr.length; i++) {
            // If the previous maximum element is outside the current window
            if (prevMaxIndex <= i - k) {
                // Find the new maximum element in the current window
                prevMaxIndex = i - k + 1;
                for (int j = i - k + 1; j <= i; j++) {
                    if (arr[j] >= arr[prevMaxIndex]) {
                        prevMaxIndex = j;
                    }
                }
            } else {
                // If the current element is greater than or equal to the previous maximum
                // element
                if (arr[i] >= arr[prevMaxIndex]) {
                    prevMaxIndex = i;
                }
            }
            al.add(arr[prevMaxIndex]);
        }

        return al;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 3, -1, -3, 5, 3, 6, 7 };
        int k = 3;

        System.out.println(solve(arr, k));
    }
}
