
import java.util.*;

class Trie {
    static class TrieNode {
        TrieNode[] children = new TrieNode[26];
        boolean isEndOfWord = false;
    }

    TrieNode root = new TrieNode();

    // Insert word into Trie
    void insert(String word) {
        TrieNode current = root;
        for (char ch : word.toCharArray()) {
            int idx = ch - 'a';
            if (current.children[idx] == null) {
                current.children[idx] = new TrieNode();
            }
            current = current.children[idx];
        }
        current.isEndOfWord = true;
    }

    // Search word in Trie
    boolean search(String word) {
        TrieNode current = root;
        for (char ch : word.toCharArray()) {
            int idx = ch - 'a';
            if (current.children[idx] == null) {
                return false;
            }
            current = current.children[idx];
        }
        return current.isEndOfWord;
    }
}

public class SearchList{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = Integer.parseInt(sc.nextLine());
        String[] source = sc.nextLine().split(" ");

        int m = Integer.parseInt(sc.nextLine());
        String[] target = sc.nextLine().split(" ");

        Trie trie = new Trie();
        for (String word : source) {
            trie.insert(word);
        }

        List<Boolean> result = new ArrayList<>();
        for (String word : target) {
            result.add(trie.search(word));
        }

        System.out.println(result);
    }
}

