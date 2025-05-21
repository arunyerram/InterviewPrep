package DAY15;
/*
 * 
 * Given string num representing a non-negative integer num and an integerk , return the smallest possible integer after removing k digits from it
 * 
 * ex:
 * 1432219
 * 3
 * o.p
 * 1219
 */

import java.util.*;

public class RemoveKdigits {
    public static String solve(String str, int n, int k) {
        if (str == null || str == "")
            return "";
        if (k > n)
            return "0";
        Stack<Integer> st = new Stack<Integer>();
        StringBuilder sb = new StringBuilder();
        int req = k;
        for (int i = 0; i < n; i++) {
            char ch = str.charAt(i);
            int num = Integer.parseInt("" + ch);
            while (!st.isEmpty() && st.peek() >= num && req > 0) {
                st.pop();
                req--;
            }
            st.push(num);
        }
        while (req > 0) {
            st.pop();
            req--;
        }
        while (!st.isEmpty()) {
            sb.append(st.pop());
        }
        String r = sb.reverse().toString();
        int res = 0;
        if (r.length() != 0 && r != null) {
            res = Integer.parseInt(r);
        }
        return ("" + res);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int k = sc.nextInt();
        System.out.print(solve(str, str.length(), k));
    }
}