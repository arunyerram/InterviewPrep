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
        pq.push(10);
        pq.push(20);

        while(!pq.isEmpty()){
            System.out.println(pq.pop());
        }
        PriorityQueue<Integer>pq1 = new PriorityQueue<>((a,b) -> b-a);
        pq1.push(203);
        pq1.push(230);
        while(!pq1.isEmpty()){
            System.out.println(pq1.pop());
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