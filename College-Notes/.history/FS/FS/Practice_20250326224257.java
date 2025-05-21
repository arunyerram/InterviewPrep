import java.util.*;
public class Practice{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[] arr = new int[5];
        ArrayList<Integer>lst = new ArrayList<>();
        for(int i=0;i<5;i++){
            // System.out.println(arr[i]);
            int ele  = sc.nextInt();
            lst.add(ele);
            arr[i] = ele;
        }
        for(int i=0;i<5;i++){
            System.out.println(arr[i]);
        }

        PriorityQueue<Integer>pq= new PriorityQueue<>();
        pq.push(10)
        // System.out.println(arr);
        // System.out.println(lst);
        // Set<Integer>st = new TreeSet<>();
        // st.add(10);
        // st.add(10);
        // st.add(20);
        // st.add(30);

        // System.out.println(st);
    }
}