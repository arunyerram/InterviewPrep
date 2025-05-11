
public class ToggleCase {
    static int x = 32;
    static String toggleCase(String str) {
        char[] arr = str.toCharArray();
        for (int i = 0; i < arr.length; i++) {
            arr[i] = (char) (arr[i] ^ x);
            // or arr[i] ^= x;
        }
        return new String(arr);
    }
    public static void main(String[] args) {
        String str = "Hello World";
        System.out.println(toggleCase(str));
    }
}
