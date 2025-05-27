
import java.util.*;

class TrieHelper {
    static class Node {
        Node[] c = new Node[26];
        boolean isWord;
    }

    Node root = new Node();
    String res = "";

    public String longestWord(String[] words) {
        for (String w : words) add(w);
        for (String w : words) check(w);
        return res;
    }

    void add(String w) {
        Node cur = root;
        for (char ch : w.toCharArray()) {
            if (cur.c[ch-'a'] == null) cur.c[ch-'a'] = new Node();
            cur = cur.c[ch-'a'];
        }
        cur.isWord = true;
    }

    void check(String w) {
        Node cur = root;
        for (char ch : w.toCharArray()) {
            cur = cur.c[ch-'a'];
            if (!cur.isWord) return;
        }
        if (w.length() > res.length() ||
           (w.length()==res.length() && w.compareTo(res)<0)) {
            res = w;
        }
    }
}

public class LongestWord {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] words = sc.nextLine().split(" ");
        System.out.println(new TrieHelper().longestWord(words));
    }
}

