
import java.util.*;

public class walmart {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in, "UTF-8");
        List<String> words = new ArrayList<>();
        Map<String,Integer>mp = new HashMap<>();

        while (sc.hasNextLine()) {  // Reads input until EOF
            String input = sc.nextLine();
            // words.addAll(Arrays.asList(input.split("->"))); // Split words and store
            mp.put(input, mp.getOrDefault(input, 0) + 1);
        }

        // System.out.println(words);
        for (Map.Entry<String, Integer> entry : mp.entrySet()) {
            System.out.println(entry.getKey() + " -> " + entry.getValue());
        }
        sc.close();
    }
}
