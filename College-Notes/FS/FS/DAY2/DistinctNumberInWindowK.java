/*
 * There are N small cartoons, and each cartoon contains a balloon of a specific color, represented by an integer.

You need to pick k consecutive cartoons at a time and determine the number of unique colored balloons within that selection. 
Repeat this for each possible selection of k cartoons from the given sequence.

The total number of such selections will be (N - k + 1), and for each selection, 
you must return the count of unique balloon arr.

Input Format:
-------------
Line-1: Two space-separated integers N (total number of cartoons) and k (number of cartoons selected at a time).
Line-2: N space-separated integers, representing the color of balloons inside each cartoon.

Output Format:
---------------
Line-1: krint space-separated (N - k + 1) integers, where each integer represents the number of unique balloon arr in each selection of k cartoons.

Sample Input-1:
---------------
7 4
1 2 2 3 3 4 4

Sample Output-1:
----------------
3 2 3 2

Explanation: 
------------
The number of distinct elements in each subarray of size k goes as follows:
- nums[0:3] = [1,2,2,3] so ans[0] = 3
- nums[1:4] = [2,2,3,3] so ans[1] = 2
- nums[2:5] = [2,3,3,4] so ans[2] = 3
- nums[3:6] = [3,3,4,4] so ans[3] = 2


Sample Input-2:
---------------
6 3
1 1 1 1 1 1

Sample Output-2:
----------------
1 1 1 1

Explanation:
------------
The number of distinct elements in each subarray goes as follows:
- nums[0:2] = [1,1,1] so ans[0] = 1
- nums[1:3] = [1,1,1] so ans[1] = 1
- nums[2:4] = [1,1,1] so ans[2] = 1
- nums[3:5] = [1,1,1] so ans[3] = 1


Sample Input-3:
---------------
7 3
1 2 3 4 2 1 3

Sample Output-3:
----------------
3 3 3 3 3

 */
import java.util.*;

public class DistinctNumberInWindowK {
    // public static void solve(int[] arr, int k) {
    // // Set<Integer> s = new HashSet<>();
    // // for(int i = 0; i < k;i++){
    // // s.add(arr[i]);
    // // }
    // // System.out.println(s.remove());
    // int n = arr.length;
    // int[] res = new int[n - k + 1];
    // Map<Integer, Integer> map = new HashMap<>();
    // for (int i = 0; i < k; i++) {
    // map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
    // }
    // res[0] = map.size();
    // for (int i = k; i < n; i++) {
    // map.put(arr[i - k], map.get(arr[i - k]) - 1);
    // if (map.get(arr[i - k]) == 0) {
    // map.remove(arr[i - k]);
    // }
    // map.put(arr[i], map.getOrDefault(arr[i], 0) + 1);
    // res[i - k + 1] = map.size();
    // }
    // for (int i = 0; i < res.length; i++) {
    // System.out.print(res[i] + " ");
    // }
    // // System.out.println(Arrays.toString(arr));
    // // Map<Integer, Integer> m = new HashMap<>();
    // // int dist = 0;
    // // for (int i = 0; i < arr.length; i++) {
    // // if (i >= k) {
    // // m.put(arr[i - k], m.getOrDefault(arr[i - k], 0) - 1);

    // // if (m.get(arr[i - k]) == 0)
    // // dist--;
    // // }
    // // m.put(arr[i - k], m.getOrDefault(arr[i - k], 0) + 1);
    // // if (m.get(arr[i]) == 1)
    // // dist++;
    // // if (i >= k - 1) {
    // // System.out.println(dist);
    // // }
    // // }
    // }

    // public static void main(String[] args) {
    // int arr[] = { 1, 2, 2, 3, 3, 4, 4 };
    // solve(arr, 4);
    // }
    public static void solve(int[] arr, int k, int n) {
        HashMap<Integer, Integer> m = new HashMap<>();
        for (int i = 0; i < k; i++) {
            m.put(arr[i], m.getOrDefault(arr[i], 0) + 1);
        }
        System.out.print(m.size() + " ");

        for (int i = k; i < n; i++) {
            if (m.get(arr[i - k]) == 1) {
                m.remove(arr[i - k]);
            } else {
                m.put(arr[i - k], m.get(arr[i - k]) - 1);
            }
            m.put(arr[i], m.getOrDefault(arr[i], 0) + 1);
            System.out.print(m.size() + " ");
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        solve(arr, k, n);
    }
}
