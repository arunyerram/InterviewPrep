/*
 * A string is good if there are no repeated characters.
Given a string s, return the number of good substrings of length three in s.
Note that if there are multiple occurrences of the same substring, every occurrence should be counted.
A substring is a contiguous sequence of characters in a string.

Sample Input-1:
---------------
xyzzaz

Sample Output-1:
----------------
1

Explanation: 
------------
There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
The only good substring of length 3 is "xyz".

Sample Input-2:
---------------
aababcabc

Sample Output-2:
----------------
4

Explanation: 
------------
There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
The good substrings are "abc", "bca", "cab", and "abc".
 */

 import java.util.*;

 public class GoodStrings{
     public static int solve(String str, int k, int n){
         Map<Character, Integer> m = new HashMap<>();
         int cnt = 0;
         
         for(int i = 0;i<k;i++){
             m.put(str.charAt(i), m.getOrDefault(str.charAt(i),0)+1);
         }
         if(m.size() == 3) cnt++;
         for(int i = k;i<n;i++){
             if(m.get(str.charAt(i-k)) == 1){
                 m.remove(str.charAt(i-k));
             }else{
                 m.put(str.charAt(i-k), m.getOrDefault(str.charAt(i-k),0)-1);
             }
             m.put(str.charAt(i), m.getOrDefault(str.charAt(i),0)+1);
             if(m.size() == 3) cnt++;
         }
         return cnt;
     }
     public static void main(String args[]){
         Scanner sc = new Scanner(System.in);
         String str = sc.next();
         int k = 3;
         System.out.print(solve(str,k, str.length()));
     }
 }