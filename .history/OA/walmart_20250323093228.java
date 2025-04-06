
import java.util.*;

public class walmart {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in, "UTF-8");
        List<String> words = new ArrayList<>();

        while (sc.hasNextLine()) {  // Reads input until EOF
            String input = sc.nextLine();
            words.addAll(Arrays.asList(input.split(" "))); // Split words and store
        }

        System.out.println(words);
        sc.close();
    }
}
