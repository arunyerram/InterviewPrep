import java.util.*;

public class codecHef3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            Long n,k;
            n = sc.nextLong();
            k = sc.nextLong();

            Long[] a = new Long[n];
            Long[] a1 = new Long[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextLong();
            }
            for(int i = 0; i < n; i++) {
                a1[i] = sc.nextLong();
            }

            Long mn = 0L;
            Long p = Long.MAX_VALUE;
            for(int i=0;i<n;i++){
                Long diff = Math.abs(a[i] - a1[i]);
                mn = Math.min(diff,9-diff);
                Long x = diff,y = 9-diff;
                p = Math.min(p,Math.abs(x-y));
            }

            if(mn > k)System.out.println("NO");
            else{
                Long d = Math.abs(k-mn);
                if(d%2 == 0){
                    System.out.println("YES");
                }else{
                    mn += p;
                     if(mn > k)System.out.println("NO");
                     else System.out.println("YES");
                }
            }
    }
        sc.close();
    }
}