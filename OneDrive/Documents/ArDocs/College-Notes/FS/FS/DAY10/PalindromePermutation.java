/*
 * AlphaCipher is a string formed from another string by rearranging its letters

You are given a string S.
Your task is to check, can any one of the AlphaCipher is a palindrome or not.

Input Format:
-------------
A string S

Output Format:
--------------
Print a boolean value.


Sample Input-1:
---------------
carrace

Sample Output-1:
----------------
true


Sample Input-2:
---------------
code

Sample Output-2:
----------------
false
 */

 import java.util.*;

 public class PalindromePermutation{
     public static boolean solve(String str){
         int mask = 0;
         for(char ch: str.toCharArray()){
             mask = mask^(1<<(ch-'a'));
         }
         return (mask == 0) || ((mask & (mask-1))==0);
     }
     public static void main(String args[]){
         Scanner sc = new Scanner(System.in);
         String str = sc.next();
         System.out.print(solve(str));
     }
 }