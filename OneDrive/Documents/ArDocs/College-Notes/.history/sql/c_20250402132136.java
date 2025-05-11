package sql;
import java.util.*;
public class c {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<String>ar = new ArrayList<>();
        while(sc.hasNextLine()) {
            String s = sc.nextLine();
            String[] parts = s.split(" ");
            if(parts.length == 0)break;
            for (String part : parts) {
                ar.add(part);
            }
        }
        Collections.sort(ar);
        // for(String it:ar)System.out.println(it);
        for(int i=0;i<ar.get(0).length();i++){
            
        }
    }
}
