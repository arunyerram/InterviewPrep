
import java.util.*;

public class walmart {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in, "UTF-8");

        int[][] arr = new int[3][3];
        int[][] arr2 = new int[3][3];

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                arr2[i][j] = sc.nextInt();
            }
        }
    }
}
