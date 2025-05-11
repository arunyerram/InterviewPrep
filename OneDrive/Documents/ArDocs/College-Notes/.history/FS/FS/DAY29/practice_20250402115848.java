package FS.FS.DAY29;
import java.util.*;
public class practice {
    // public static void     
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int k = sc.nextInt();
        ArrayList<Integer>ar = new ArrayList<>();
        // System.out.print(solve(arr, n, k));
        Map<Integer,ArrayList<Integer>>mp = new HashMap<Integer,ArrayList<Integer>>();
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i+1;j<n;j++){
                sum = sum + arr[j];
                mp.putIfAbsent(sum,new ArrayList<>());
                ar.add(sum);
            }
        }
        Collections.sort(ar);
        int key = ar.get(k);
        System.out.println(mp.get(key));

        
    }
}
