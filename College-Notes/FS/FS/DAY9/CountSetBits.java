// package DAY9;

public class CountSetBits {
    public static int countSetBits(int n) {
        int count = 0;
        // while (n > 0) {
        //     n = n & (n - 1);
        //     count++;
        // }

        //or
        while (n > 0) {
             if((n & 1) != 0) count++;
            n = n>>1;
        }

        return count;
    }

    public static void main(String[] args) {
        int n = 16;
        System.out.println(countSetBits(n));
    }
}
