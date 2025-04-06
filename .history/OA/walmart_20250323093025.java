import java.util.*;

public class walmart{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        // String input = sc.nextLine();
        Map<String,Integer>mp = new Hashmap<>();
        while(sc.hasNextLine()){
            String input = sc.nextLine();
            
            for(String str : input.split("->")){
                // System.out.println(str);
                mp.put(mp.getOrDefault(str,0)+1);
            }
        }
    }
}