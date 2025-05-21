import java.util.*;
public class Code1{
    public static void main(String[] args){
        List<Integer>ar = new ArrayList<>();
        ar.add(1);
        ar.add(2);
        ar.add(3);

        

        System.out.println(ar.get(1));
        ar.set(1,20);
        ar.remove(2);

        System.out.println(ar.size());
        System.out.println(ar.contains(2));
        Collections.sort(ar);

        Collections.reverse(ar);
       
        System.out.println(ar); 
        ar.clear();
        System.out.println(ar.size());


        List<List<Integer>>arr = new ArrayList<>();

        arr.add(new ArrayList<>(Arrays.asList(1,2,3)));
        arr.add(new ArrayList<>(Arrays.asList(2,3,4)));
        arr.add(new ArrayList<>(Arrays.asList(3,4,5)));
        arr.add(new ArrayList<>(Arrays.asList(4,5,6)));
        System.out.println(arr); 

        System.out.println(arr.get(0).get(2));

        System.out.println(arr.get(0).remove(2));
        arr.get(0).add(123);

        for(List<Integer>it:arr){
            for(int a:it){
                System.out.print(a);
            }
            System.out.println();
        }

        arr.clear();

        
    }
}