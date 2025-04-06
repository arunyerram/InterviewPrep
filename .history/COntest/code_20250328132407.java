import java.util.*;

public class code {
    public static int lowerBound(List<Integer> lst, int x) {
        int low = 0, high = lst.size();
        
        while (low < high-1) {
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
                int idx = lowerBound(lst, n - it);

                // Ensure index is within bounds before accessing
                while (idx >= 0 && idx < m) {
                    int ele = lst.get(idx);
                    tot += mp.getOrDefault(ele, 0);
                    
                    // Exit if `it` does not change to avoid infinite loop
                    if (it == 0) break;
                    it -= 1;

                    // Recalculate index
                    idx = lowerBound(lst, n - it);
                }
            }

            System.out.println(tot);
        }
        
        sc.close(); // Close scanner outside the loop
    }
}
