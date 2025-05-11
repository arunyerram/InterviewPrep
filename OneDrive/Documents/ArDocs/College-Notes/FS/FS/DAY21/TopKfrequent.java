/*
 * You are given an integer array containing numbers, and an integer k. 
 Your task is to return the k most frequent elements in the array.
 
 If multiple elements have the same frequency, the element with the higher value should be prioritized.
 The output should be printed in descending order of frequency.
 
 Input Format:
 -------------
 Line-1: An integer N, representing the number of elements in the array.
 Line-2: A line with N space-separated integers representing the elements of the array.
 Line-3: An integer k, representing the number of most frequent elements to return.
 
 Output Format:
 --------------
 Line-1: An array, comma-separated integers in descending order of frequency. 
 If two elements have the same frequency, the higher number should appear first.
 
 
 Sample Input-1:
 --------------
 6
 1 1 1 2 2 3
 2
 
 Sample Output-1:
 ----------------
 [1, 2]
 
 
 Sample Input-2:
 --------------
 1
 1
 1
 
 Sample Output-2:
 ----------------
 [1]
 
 */
import java.util.*;

class Pair implements Comparable<Pair>{
    int a, f;
    public Pair(int a, int f){
        this.a = a;
        this.f = f;
    }
    @Override
    public int compareTo(Pair p2){
        if(p2.f == this.f){
            return this.a - p2.a;
        }
        return  this.f - p2.f;
    }
}

public class TopKfrequent{
    public static void solve(int arr[], int n, int k){
        HashMap<Integer, Integer> m = new HashMap<>();
        for(int a: arr){
            m.put(a,m.getOrDefault(a,0)+1);
        }
        PriorityQueue<Pair> al = new PriorityQueue<>(Collections.reverseOrder());
        for(Map.Entry<Integer,Integer> e: m.entrySet()){
            al.add(new Pair(e.getKey(), e.getValue()));
        }
        int res[] = new int[k];
        for(int i=0;i<k;i++){
            Pair p = al.poll();
            res[i] = p.a;
        }
        System.out.println(Arrays.toString(res));
    }
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        int k = sc.nextInt();
        solve(arr,n,k);
    }
}