
import java.util.*;

public class walmart {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in, "UTF-8");

        int n;
        n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        List<Integer>ans = new ArrayList<>();
        int idx = 0;
        while(n > 0){
            int oc = (n+1)/2;
            for(int i=0;i<oc;i++){
                ans.add(Integer.parseInt(Math.pow(2,idx)));
            }idx++;
            n -= oc;
        }

    for(int i=0;i<ans.size();i++){
        System.out.println(ans.get(i));
    }
    sc.close();
    }
}
