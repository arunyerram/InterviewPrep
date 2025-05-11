
public class FirstSetBit {
    public static int getFirstSetBit(int n) {
        if (n == 0) {
            return 0;
        }
        int p = 1;
       
        while (n>0) {
            if((n & 1) == 1) {
                return p;
            }
            p++;
            n = n >> 1;
        }
        return 0;
    }
    public static void main(String[] args) {
        int n = 18;
        System.out.println(getFirstSetBit(n));
    }
}
