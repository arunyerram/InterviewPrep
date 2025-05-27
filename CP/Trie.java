
import java.util.*;

class Trie {
    static final int NUM_CHARS = 26;
    static boolean isDeleted = false;  // helper for delete()

    // Trie node
    static class TrieNode {
        TrieNode[] children = new TrieNode[NUM_CHARS];
        boolean isEndOfWord;
        TrieNode() {
            isEndOfWord = false;
            for (int i = 0; i < NUM_CHARS; i++)
                children[i] = null;
        }
    }

    static TrieNode root = new TrieNode();

    // Insert key into trie
    static void insert(String key) {
        TrieNode curr = root;
        for (char c : key.toCharArray()) {
            int idx = c - 'a';
            if (curr.children[idx] == null)
                curr.children[idx] = new TrieNode();
            curr = curr.children[idx];
        }
        curr.isEndOfWord = true;
    }

    // Search full word (or prefix if you uncomment the prefix line)
    static boolean search(String key) {
        TrieNode curr = root;
        for (char c : key.toCharArray()) {
            int idx = c - 'a';
            if (curr.children[idx] == null) return false;
            curr = curr.children[idx];
        }
        // return true;                // for prefix‐search
        return curr.isEndOfWord;      // for whole‐word search
    }

    // Check if node has no children
    static boolean isEmpty(TrieNode node) {
        for (int i = 0; i < NUM_CHARS; i++)
            if (node.children[i] != null) return false;
        return true;
    }

    // Delete key recursively
    static TrieNode delete(TrieNode node, String key, int depth) {
        if (node == null) return null;
        if (depth == key.length()) {
            isDeleted = node.isEndOfWord;
            if (node.isEndOfWord) node.isEndOfWord = false;
            if (isEmpty(node)) return null;
            return node;
        }
        int idx = key.charAt(depth) - 'a';
        node.children[idx] = delete(node.children[idx], key, depth + 1);
        if (isEmpty(node) && !node.isEndOfWord) return null;
        return node;
    }

    // Print all words in trie
    static void print(TrieNode node, char[] str, int level) {
        if (node.isEndOfWord) {
            System.out.println(new String(str, 0, level));
        }
        for (int i = 0; i < NUM_CHARS; i++) {
            if (node.children[i] != null) {
                str[level] = (char) (i + 'a');
                print(node.children[i], str, level + 1);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Read initial space‐separated keys
        String[] keys = sc.nextLine().split(" ");
        for (String k : keys) insert(k);

        char[] buffer = new char[50];
        while (true) {
            int op = sc.nextInt();
            sc.nextLine();
            switch (op) {
                case 1: // insert
                    insert(sc.nextLine());
                    print(root, buffer, 0);
                    break;
                case 2: // search
                    String w1 = sc.next();
                    System.out.println(w1 + (search(w1) ? " is present" : " is not present"));
                    break;
                case 3: // delete
                    String w2 = sc.next();
                    TrieNode res = delete(root, w2, 0);
                    System.out.println(w2 + (isDeleted ? " is deleted" : " not found"));
                    print(root, buffer, 0);
                    break;
                case 4: // print all
                    print(root, buffer, 0);
                    break;
                case 5: // exit
                    return;
            }
        }
    }
}
