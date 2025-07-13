

import java.util.*;

public class DistinctSubstrings {

    static class TrieNode {
        TrieNode[] children = new TrieNode[26];
    }

    static class SuffixTrie {
        TrieNode root = new TrieNode();
        int count = 0;

        void insertSuffixes(String str) {
            for (int i = 0; i < str.length(); i++) {
                insert(str.substring(i));
            }
        }

        void insert(String word) {
            TrieNode node = root;
            for (char c : word.toCharArray()) {
                int idx = c - 'a';
                if (node.children[idx] == null) {
                    node.children[idx] = new TrieNode();
                    count++; // new node = new unique substring
                }
                node = node.children[idx];
            }
        }

        int countDistinctSubstrings() {
            return count;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string:");
        String input = sc.nextLine();

        SuffixTrie trie = new SuffixTrie();
        trie.insertSuffixes(input);

        System.out.println("Number of distinct substrings: " + trie.countDistinctSubstrings());
    }
}
