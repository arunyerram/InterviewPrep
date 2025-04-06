import java.util.*;

public class codecHef3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n,k;
            n = sc.nextInt();
            k = sc.nextInt();

            int[] a = new int[n];
            int[] a1 = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            for(int i = 0; i < n; i++) {
                a1[i] = sc.nextInt();
            }

            Long mn = 0L;
            for(int i=0;i<n;i++){
                Long diff = Math.abs(a.get(i) - a1.get(i));
                mn = Math.min(diff,9-diff);
                Long x = diff,y = 9-diff;
                p = Math.min(p,Math.abs(x-y));
            }

            if(mn > k)System.out.println("NO");
            else{
                int d = Math.abs(k-mn);
                if(d%2 == 0){
                    System.out.println("YES");
                }else{
                    mn ++= p;
                     if(mn > k)System.out.println("NO");
                     else System.out.println("YES");
                }
            }
    }
        sc.close();
    }
}