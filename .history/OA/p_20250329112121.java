import java.util.*;

public class p {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in, "UTF-8"); 
        List<int[]>l = new ArrayList<>();
        l.add(new int[]{1,2});
        l.add(new int[]{2,3});
        l.add(new int[]{1,3});
        l.add(new int[]{3,5});

        // l.sort((b,a) -> Integer.compare(a[1],b[1]));

        l.sort(Ca->a[0]);
        for(int[] pair:l)
            System.out.println(Arrays.toString(pair));
        

        sc.close();
    }
}
