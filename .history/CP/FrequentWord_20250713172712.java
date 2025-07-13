
import java.util.*;


static class Node {
    int count;
    String word;
    Node[] nxt = new Node[26];
}

class Trie {
    Node root = new Node();
    void insert(String w) {
        Node cur = root;
        for (char ch : w.toCharArray()) {
            int i = ch - 'a';
            if (cur.nxt[i] == null) cur.nxt[i] = new Node();
            cur = cur.nxt[i];
        }
        cur.count++;
        cur.word = w;
    }
    void traverse(Node r, PriorityQueue<Node> pq) {
        if (r.count > 0) pq.offer(r);
        for (Node c : r.nxt) if (c != null) traverse(c, pq);
    }
}

public class FrequentWord {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();   // comma-separated words
        int k = sc.nextInt();
        String[] words = line.split(",");
        Trie t = new Trie();
        for (String w : words) t.insert(w);

        PriorityQueue<Node> pq = new PriorityQueue<>(
            (a,b) -> a.count!=b.count ? b.count-a.count : a.word.compareTo(b.word)
        );
        t.traverse(t.root, pq);

        List<String> ans = new ArrayList<>();
        while (k-- > 0 && !pq.isEmpty()) ans.add(pq.poll().word);
        System.out.println(ans);
    }
}
