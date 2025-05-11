package sql;
import java.util.*;
public class c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<String>ar = new ArrayList<>();
        while(sc.hasNextLine()) {
            String s = sc.nextLine();
            String[] parts = s.split(" ");
            for (String part : parts) {
                ar.add(part);
            }
        }
        for(String it:ar)System.out.println(it);
    }
}
