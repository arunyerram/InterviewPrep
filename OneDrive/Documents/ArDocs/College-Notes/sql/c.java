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
        Map<String ,String>mp =new HashMap<>();
        // for (String s : ar) {
        Collections.sort(ar);
        String ans = "";
        boolean f = true;
        // for(String it:ar)System.out.println(it);
        for(int i=0;i<ar.get(0).length();i++){
            char c = ar.get(0).charAt(i);
            for(String it:ar){
                if(c != it.charAt(i)){
                    f = false;
                    break;
                }
            }
            if(f == false)break;
            ans += c;
        }
        System.out.println(ans + " "  + ar.size());
    }
}
