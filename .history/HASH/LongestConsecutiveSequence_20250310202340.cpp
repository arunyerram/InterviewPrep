import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        List<Integer> arr = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            arr.add(sc.nextInt());
        }
        
        int k = sc.nextInt();
        
        Map<Integer, Integer> mp1 = new HashMap<>();
        for (int num : arr) {
            mp1.put(num, mp1.getOrDefault(num, 0) + 1);
        }
        
        Map<Integer, PriorityQueue<Integer>> mp2 = new TreeMap<>(Collections.reverseOrder());
        for (Map.Entry<Integer, Integer> entry : mp1.entrySet()) {
            mp2.putIfAbsent(entry.getValue(), new PriorityQueue<>(Collections.reverseOrder()));
            mp2.get(entry.getValue()).offer(entry.getKey());
        }
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        pq.addAll(mp2.keySet());

        List<Integer> ans = new ArrayList<>();
        
        while (k > 0 && !pq.isEmpty()) {
            int ele = pq.poll();
            
            if (mp2.get(ele).size() <= k) {
                k -= mp2.get(ele).size();
                while (!mp2.get(ele).isEmpty()) {
                    int p = mp2.get(ele).poll();
                    for (int i = 0; i < ele; i++) {
                        ans.add(p);
                    }
                }
            } else {
                while (k > 0 && !mp2.get(ele).isEmpty()) {
                    int p = mp2.get(ele).poll();
                    for (int i = 0; i < ele; i++) {
                        ans.add(p);
                    }
                    k--;
                }
            }
        }

        for (int num : ans) {
            System.out.println(num);
        }

        sc.close();
    }
}
