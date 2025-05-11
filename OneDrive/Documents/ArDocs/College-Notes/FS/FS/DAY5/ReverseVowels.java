import java.util.*;
public class ReverseVowels {

    public static String solve(String str) {
        String vowels = "aeiouAEIOU";
        char[] arr = str.toCharArray();
        int i = 0, j = arr.length - 1;
        while (i < j) {
            while (i < j && !vowels.contains(arr[i] + "")) {
                i++;
            }
            while (i < j && !vowels.contains(arr[j] + "")) {
                j--;
            }   
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
        return new String(arr);
    }s
    public static void main(String[] args) {
        String str = "hello";
        System.out.println(solve(str));

    }
}