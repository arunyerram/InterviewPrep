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
            for(int i = 0; i < n; i++){
                lst.add(sc.nextInt());
            }
            Collections.sort(lst);
            Map<Integer,Integer>mp = new HashMap<>();
            long cnt = 0;
            for (int i = 0; i < m; i++) {
                mp.put(lst.get(i), mp.getOrDefault(lst.get(i), 0) + cnt++);
            }
            
            for(int i = 0; i < n; i++){
                mp.put(lst.get(i) , n - mp.get(i)+ 1);
            }

            cnt = 0;
            for(int it:lst){
                while (Collections.binarySearch(lst, it) != -1){
                    int idx = Collections.binarySearch(lst, it); 
                    int ele = lst.get(idx); 
                    cnt += mp.get(ele);
                    it--;
                }
            }
            System.out.printlncnt);
        }
        sc.close(); 
    }
}