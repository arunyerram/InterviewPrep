import java.util.*;
public class Practice{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        HashMap<Integer,Integer>mp = new HashMap<>();
        mp.put(1,1);
        mp.put(5,2);
        mp.put(2,2);
        mp.put(3,3);

        System.out.println(mp.get(2));
        System.out.println(mp.containsKey(3));
        System.out.println(mp.size());
        mp.clear();
        System.out.println(mp.size());
        System.out.println(mp.containsValue(2));
        System.out.println(mp.remove(1));

        mp.put(13,12);
        mp.put(122,12);
        mp.put(14,12);
        mp.put(105,12);
        for(HashMap.Entry<Integer,Integer>e:mp.entrySet()){
            System.out.println(e.getKey() + " " + e.getValue());
        }

        Map<Integer,Integer>m1 = new TreeMap<>(mp);
        m1.put(1,1);
        System.out.println(m1);

        List<Map.Entry<Integer,Integer>>lst = new ArrayList<>(mp.entrySet());
        lst.sort(Map.Entry.comparingByValue());

        
        // int[] arr = {1,2,3,4,5};
        // ArrayList<Integer>lst = new ArrayList<>();
        // for(int i=0;i<5;i++){
        //     // System.out.println(arr[i]);
        //     int ele  = sc.nextInt();
        //     lst.add(ele);
        //     arr[i] = ele;
        // }
        // for(int i=0;i<5;i++){
            // System.out.println(arr[i]);
        // }

        // Set<Integer>s1 = new HashSet<>();
        // Set<Integer>s2 = new LinkedHashSet<>();
        // Set<Integer>s3 = new TreeSet<>(s1);

        // s1.add(10);
        // s1.add(20);
        // s1.add(30);

        // s2.add(10);
        // s2.add(30);
        // s2.add(20);

        // // s3.add(30);
        // // s3.add(10);
        // // s3.add(20);
        
        // System.out.println(s1);
        // System.out.println(s2);
        // System.out.println(s3);


        // int[][] arr = new int[3][3];
        // for(int i=0;i<3;i++){
        //     for(int j=0;j<3;j++){
        //         arr[i][j] = sc.nextInt();
        //     }
        // }
        // for(int i=0;i<3;i++){
        //     for(int j=0;j<3;j++){
        //         System.out.print(arr[i][j] + " ");
        //     }
        //     System.out.println();
        // }
        // ArrayList<ArrayList<Integer>>lst = new ArrayList<>();
        // for(int i=0;i<3;i++){
        //     ArrayList<Integer>al = new ArrayList<>();
        //     for(int j=0;j<3;j++){
        //         al.add(sc.nextInt());
        //     }
        //     lst.add(al);
        // }
        // for(int i=0;i<3;i++){
        //     for(int j=0;j<3;j++){
        //         System.out.print(lst.get(i).get(j) + " ");
        //     }
        //     System.out.println();
        // }

        // for(int i=0;i<3;i++){
        //     for(int j=0;j<3;j++){
        //         System.out.print(lst.get(i).get(j) + " ");
        //     }
        //     System.out.println();
        // }




        // PriorityQueue<Integer>pq= new PriorityQueue<>();
        // pq.add(10);
        // pq.add(20);

        // while(!pq.isEmpty()){
        //     System.out.println(pq.poll());
        // }
        // PriorityQueue<Integer>pq1 = new PriorityQueue<>((a,b) -> b-a);
        // pq1.add(203);
        // pq1.add(230);

        // Object[] ar = pq1.toArray();
        // for(Object it:ar){
        //     System.out.print(it + " ");
        // }
        // System.out.println(pq1.size());
        // System.out.println(pq1.isEmpty());

        // while(!pq1.isEmpty()){
        //     int ele = pq1.peek();
        //     System.out.println(ele);
        //     pq1.poll();
        // }
        // pq1.clear();
        // System.out.println(pq1.isEmpty());
        // System.out.println(pq1.size());
        
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