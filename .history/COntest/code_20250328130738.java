import java.util.*;
public class code{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while (t-- > 0) {
            int n,m;
            n = sc.nextInt();
            m = sc.nextInt();

            List<Integer>lst = new ArrayList<>();
            for(int i = 0; i < m; i++){
                lst.add(sc.nextInt());
            }
            Collections.sort(lst);
            Map<Integer,Integer>mp = new HashMap<>();
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                mp.put(lst.get(i),cnt+1);
                cnt += 1;
            }
            
            for(int i = 0; i < m; i++){
                mp.put(lst.get(i) , m - mp.get(lst.get(i)));
            }

            long tot = 0;
            for(int it:lst){
                while (it >= 0 && Collections.binarySearch(lst,n - it) != -1){
                    int idx = Collections.binarySearch(lst, n - it); 
                    long ele = lst.get(idx); 
                    tot += mp.get(ele);
                    it--;
                }
            }
            System.out.println(tot);
        }
        sc.close(); 
    }
}