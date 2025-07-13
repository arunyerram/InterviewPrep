
import java.util.*;

public class IndexPairs {
    public int[][] indexPairs(String text, String[] words) {
        // build trie of all words
        TrieNode trie = new TrieNode();
        for (String w : words) {
            TrieNode cur = trie;
            for (char c : w.toCharArray()) {
                int idx = c - 'a';
                if (cur.children[idx] == null) cur.children[idx] = new TrieNode();
                cur = cur.children[idx];
            }
            cur.isEnd = true;
        }

        List<int[]> out = new ArrayList<>();
        int n = text.length();
        for (int i = 0; i < n; i++) {
            TrieNode cur = trie;
            for (int j = i; j < n; j++) {
                int idx = text.charAt(j) - 'a';
                if (cur.children[idx] == null) break;
                cur = cur.children[idx];
                if (cur.isEnd) out.add(new int[]{i, j});
            }
        }
        return out.toArray(new int[out.size()][]);
    }

    static class TrieNode{
        TrieNode[] children = new TrieNode[26];
        boolean isEnd;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = sc.nextLine();
        String[] words = sc.nextLine().split(" ");
        for (int[] p : new IndexPairs().indexPairs(text, words))
            System.out.println(p[0] + " " + p[1]);
    }
}
