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
            HashMap<Integer,Integer>mp = new HashMap<>();
            for(int i = 0; i < m; i++){
                mp.put(lst.get(i),mp.getOrDefault(lst.get(i),0) + 1);
            }
            
    }  
}