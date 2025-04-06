import java.util.*;

public class code {
    public static int lowerBound(List<Integer> lst, int x) {
        int low = 0, high = lst.size();
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (lst.get(mid) < x) {
                low = mid + 1; // Move right
            } else {
                high = mid; // Move left
            }
        }
        
        return low; // Returns the first index where lst[index] >= x
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n, m;
            n = sc.nextInt();
            m = sc.nextInt();

            List<Integer> lst = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                lst.add(sc.nextInt());
            }
            Collections.sort(lst);

            Map<Integer, Integer> mp = new HashMap<>();
            int cnt = m;
            for (int i = 0; i < m; i++) {
                mp.put(lst.get(i), --cnt);
            }

            long tot = 0;
            for (int it : lst) {
                int idx = 0;
                while(idx >= 0){
                    idx = lowerBound(lst, n - it);

                    // If element is not found, get the first element greater than (lower bound)
                    if (idx < 0) {
                        // idx = -(idx + 1);
                        continue;
                    }

                    // Ensure idx is within bounds before accessing the list
                    if (idx < m) {
                        int ele = lst.get(idx);
                        tot += mp.get(ele);
                    }
                }
            System.out.println(tot);
            }
            sc.close();
        }
    }
}
