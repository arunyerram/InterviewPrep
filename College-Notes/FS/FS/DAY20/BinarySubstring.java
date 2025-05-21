/*
 * Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

Sample Input-1:
---------------
00110110
2

Sample Output-1: 
----------------
true

Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.

Sample Input-2:
---------------
0110
1

Sample Output-2: 
----------------
true

Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 

Sample Input-3:
---------------
0110
2

Sample Output-3: 
----------------
false

Explanation: The binary code "00" is of length 2 and does not exist in the array.
 

Constraints:
------------
1 <= s.length <= 5 * 10^5
s[i] is either '0' or '1'.
1 <= k <= 20
 */

import java.util.*;

public class BinarySubString {
    public static void getBinary(String res, int k, ArrayList<String> al) {
        if (res.length() == k) {
            al.add(res);
            return;
        }
        getBinary(res + "0", k, al);
        getBinary(res + "1", k, al);
    }

    public static boolean solve(String str, int n) {
        ArrayList<String> al = new ArrayList<>();
        getBinary("", n, al);
        for (int i = 0; i < n; i++) {
            String s = al.get(i);
            if (!str.contains(s)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        int n = sc.nextInt();
        System.out.print(solve(str, n));
    }
}