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
            int cnt = 1;
            
            // Assign frequency to all present elements
            for (int i = 0; i < m; i++) {
                mp.put(lst.get(i), cnt);
                cnt += 1;
            }

            // Fill gaps with the frequency of the next greater element
            for (int i = m - 2; i >= 0; i--) {
                int curr = lst.get(i);
                int next = lst.get(i + 1);

                for (int j = curr + 1; j < next; j++) {
                    mp.put(j, mp.get(next));  // Assign frequency of next element
                }
            }

            long tot = 0;
            for (int it : lst) {
                int idx = 0;
                while(idx >= 0 && idx < m) {
                    idx = lowerBound(lst, n - it);

                    if (idx < 0 || idx >= m) {
                        break;
                    }

                    if (idx < m) {
                        int ele = lst.get(idx);
                        tot += mp.get(ele);
                    }
                    it -= 1;
                }
            }
            System.out.println(tot);
        }
        sc.close();
    }
}
