import java.util.*;
import java.util.Arrays;
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
            int cnt = 0;
            for(int i = 0; i < m; i++){
                mp.put(lst.get(i),cnt++);
            }

            for(int it:lst){
                while ( Arrays.binarySearch(lst, it) != -1){
                    cnt++;
                    mp.put(it,cnt);{
                    
                }
                
            }


    }  
}