import java.util.*;
public class smootyincreasing{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // String[] input = sc.nextLine();
        Map<String, Integer> mp = new TreeMap<>();
        while(sc.hasNextLine()){
            String s = sc.nextLine();
            String[] parts = s.split(" ");
            mp.put(parts[0],mp.getOrDefault(parts[0],0) + 1);
            mp.put(parts[1],mp.getOrDefault(parts[1],0) + 1);
        }

        while (true) {  // Keep reading lines
            String s = sc.nextLine().trim();
            if (s.isEmpty()) break;  // Stop input on empty line

            String[] parts = s.split("->");
            for (String word : parts) {
                mp.put(word, mp.getOrDefault(word, 0) + 1);
            }
        }
        for(Map.Entry<String,Integer>ent:mp.entrySet()){
            String key = ent.getKey();
            int value = ent.getValue();
            System.out.println(key + " " + value);
        }
        sc.close();
    }
}