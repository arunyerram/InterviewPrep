import java.util.*;
public class array{
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
        ar.clear();
        System.out.println(ar);

        Collections.sort(a)
    }
}