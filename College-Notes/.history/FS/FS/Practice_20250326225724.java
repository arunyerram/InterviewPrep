import java.util.*;
public class Practice{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[] arr = {1,2,3,4,5};
        // ArrayList<Integer>lst = new ArrayList<>();
        // for(int i=0;i<5;i++){
        //     // System.out.println(arr[i]);
        //     int ele  = sc.nextInt();
        //     lst.add(ele);
        //     arr[i] = ele;
        // }
        for(int i=0;i<5;i++){
            System.out.println(arr[i]);
        }

        PriorityQueue<Integer>pq= new PriorityQueue<>();
        pq.add(10);
        pq.add(20);

        while(!pq.isEmpty()){
            System.out.println(pq.poll());
        }
        PriorityQueue<Integer>pq1 = new PriorityQueue<>((a,b) -> b-a);
        pq1.add(203);
        pq1.add(230);

        Object ar = pq1.toArray();
        for(int it:ar){
            System.out.print(it + " ");
        }
        System.out.println(pq1.size());
        System.out.println(pq1.isEmpty());

        while(!pq1.isEmpty()){
            int ele = pq1.peek();
            System.out.println(ele);
        }
        
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