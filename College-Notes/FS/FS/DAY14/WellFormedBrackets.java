/*
 * Clavius, the person who suggested grouping of data using brackets.
He has suggested that the group of brackets should be Well-Formed.

A string is said to be Well-Formed, if:
    - Any open bracket must have corresponding two consecutive close brackets.
    - Open bracket must appear before the corresponding close brackets.

You will be given a string B, consists of square brackets only '[' , ']'.
In one operation, you can insert one square bracket at any position of B.
i.e., Given B = [[]]], in one operation you can add a open square bracket,
now B can be Well-Formed string, if you add at index 2,3,4 or 5 => [[]]]]

Your task is to return the least number of operations required,
to make B as a Well-Formed string.

Input Format:
-------------
A string, B contains only characters '[', ']'

Output Format:
--------------
Print an integer value.


Sample Input-1:
---------------
[]]][

Sample Output-1:
----------------
4


Sample Input-2:
---------------
[]][[]]

Sample Output-2:
----------------
2

 */

 import java.util.Stack;

public class WellFormedBrackets {

    public static int makeWellFormed(String B) {
        Stack<Character> stack = new Stack<>();
        int insertions = 0;

        for (int i = 0; i < B.length(); i++) {
            char ch = B.charAt(i);

            if (ch == '[') {
                // Push open brackets onto the stack
                stack.push(ch);
            } else if (ch == ']') {
                if (!stack.isEmpty() && stack.peek() == '[') {
                    // If stack is not empty and the top is '[', pop it (matching pair)
                    stack.pop();
                } else {
                    // If no matching open bracket is found, we need to insert one
                    insertions++;
                }
            }
        }

        // After processing all the characters, any remaining open brackets in the stack
        // need corresponding closing brackets. Each open bracket requires 2 closing brackets.
        insertions += stack.size() * 2;

        return insertions;
    }

    public static void main(String[] args) {
        String B1 = "[]]][";
        System.out.println(makeWellFormed(B1));  // Output: 4

        String B2 = "[]][[]]";
        System.out.println(makeWellFormed(B2));  // Output: 2
    }
}

 