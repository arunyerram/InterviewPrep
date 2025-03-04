import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int n = 5; // size of the array
        int[] a = {6, 7, 3, 2, 2};

        int[] dp = new int[n + 1]; // dp array
        int i = 0;
        while (i <= n - 1) {
            if (i == 0) {
                dp[i] = a[i];
            } else {
                dp[i] = a[i] + dp[i - 1];
            }
            i++;
        }

        int q = 4; // number of queries
        int[] w = {0, 3, 4, 2}; // query array
        i = 0;
        while (i <= q - 1) {
            int query = w[i];
            System.out.println(dp[query]); // answering each query in O(1)
            i++;
        }
    }
}
