import java.util.*;

class SuffixTree {
    static final int NUM_CHARS = 26;

    static class SuffixTrieNode {
        SuffixTrieNode[] children = new SuffixTrieNode[NUM_CHARS];
        boolean isEndOfWord;

        SuffixTrieNode() {
            isEndOfWord = false;
        }
    }

    static SuffixTrieNode root = new SuffixTrieNode();

    // Insert all suffixes of the word into the trie
    static void buildSuffixTrie(String word) {
        for (int i = 0; i < word.length(); i++) {
            insert(word.substring(i));
        }
    }

    // Insert a single word/suffix into the trie
    static void insert(String word) {
        SuffixTrieNode curr = root;
        for (char ch : word.toCharArray()) {
            int idx = ch - 'a';
            if (curr.children[idx] == null) {
                curr.children[idx] = new SuffixTrieNode();
            }
            curr = curr.children[idx];
        }
        curr.isEndOfWord = true;
    }

    // Check if the node is a leaf
    // static boolean isLeafNode(SuffixTrieNode node) {
    //     for (int i = 0; i < NUM_CHARS; i++) {
    //         if (node.children[i] != null) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // Print all suffixes stored in the Trie
    static void print(SuffixTrieNode node, char[] str, int level) {
        if (node.isEndOfWord) {
            System.out.println(new String(str, 0, level));
        }

        for (int i = 0; i < NUM_CHARS; i++) {
            if (node.children[i] != null) {
                str[level] = (char) ('a' + i);
                print(node.children[i], str, level + 1);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine().toLowerCase();
        buildSuffixTrie(input);
        // System.out.println("All suffixes in the trie:");
        print(root, new char[100], 0);
    }
}
