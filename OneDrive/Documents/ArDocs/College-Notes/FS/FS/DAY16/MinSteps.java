/*
 * given a positive number u can apply one of the follwoing opr
 * if n is even replace n with n/2
 * if n is odd replace n with either n+1 or n-1
 * return min number of operations needed for n to become 1
 */
public class MinSteps{
    // public static int solve(int n) {
    //     if(n==1) return 0;
    //     if(n%2==0) return 1+solve(n/2);
    //     return 1+Math.min(solve(n-1),solve(n+1));
    // }

    //using bit wise operator
    public static int solve(int n) {
        int operations = 0;
        while (n != 1) {
            if ((n & 1) == 0) { // n is even
                n >>= 1; // Equivalent to n = n / 2
            } else {
                if (n == 3 || ((n >> 1) & 1) == 0) {
                    n--; // If n is 3 or the second least significant bit is 0, decrement n
                } else {
                    n++; // Otherwise, increment n
                }
            }
            operations++;
        }
        return operations;
    }

    public static void main(String[] args) {
        System.out.println(solve(7));
    }    
}
