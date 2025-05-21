import java.util.*;

public class Test {
    public static void main(String[] args) {
        // int arr[] = {5,1,2,3,4};
        // System.out.println(Arrays.binarySearch(arr, 0));
        // Set<Integer> s = new HashSet<>();
        // s.add(23);
        // s.add("5");
        // s.add(45);
        // s.add(2);
        // System.out.println(s);
        // ArrayList<String>al = new ArrayList<>();
        // al.add("kmit");
        // al.add(Boolean.TRUE);
        // al.add(1,21);
        // System.out.println(al);
        // System.out.println(al.remove("kmit"));
        // System.out.println(al);
        // System.out.println(al.remove(1));
        // System.out.println(al);
        // al.set(0, "keshav");
        // System.out.println(al);
        // al.clear();
        // System.out.println(al.contains("e"));
        // ArrayList al = new ArrayList();
        // al.add(1);
        // al.add(2);
        // ArrayList al2 = new ArrayList();
        // al2.add(2);
        // al2.add(1);
        // System.out.println(al.equals(al2));

        // ArrayList<String> al = new ArrayList<>();
        // al.add("kmit");
        // al.add("ngit");
        // Object[] obj = al.toArray();
        // System.out.println(obj.length + " " + Arrays.toString(obj));
        // al.add("hello");
        // // String[] arr = al.toArray(new String[0]);
        // // System.out.println(arr.length);
        // obj[0] = "hello";
        // System.err.println(Arrays.toString(obj)+" "+al);

        // String[] strs = {"kmit", "ngit"};
        // List<String> list = Arrays.asList(strs);
        // System.out.println(list);
        // list.set(0, "genisis");
        // strs[0] = "india";
        // for(String s: strs){
        //     System.out.print(s+" ");
        // }
        // // list.remove(0);
        // System.err.println(list);
        // System.err.println(Arrays.toString(strs));
        // System.out.println("=====================================");
        // List<String> list2 = List.of("kmit", "ngit");
        // System.out.println(list2);
        // list2.set(1,"genisis");

        List<String> list = new ArrayList<>();
        list.add("kmit");
        list.add("ngit");

        List<String> unmodify = Collections.unmodifiableList(list);
        list.add("keshav");                 
        System.out.println(unmodify);


    }
}
