
import java.util.*;

class Suffix {

    static class SuffixTrieNode {
        static final int MAX_CHAR = 26;
        SuffixTrieNode[] children = new SuffixTrieNode[MAX_CHAR];

        SuffixTrieNode() {
            for (int i = 0; i < MAX_CHAR; i++)
                children[i] = null;
        }

        void insertSuffix(String s) {
            if (s.length() > 0) {
                int index = s.charAt(0) - 'a';
                if (children[index] == null) {
                    children[index] = new SuffixTrieNode();
                }
                children[index].insertSuffix(s.substring(1));
            }
        }
    }

    static class SuffixTrie {
        static final int MAX_CHAR = 26;
        SuffixTrieNode root;

        SuffixTrie(String s) {
            root = new SuffixTrieNode();
            for (int i = 0; i < s.length(); i++) {
                root.insertSuffix(s.substring(i));
            }
        }

        private int _countNodesInTrie(SuffixTrieNode node) {
            if (node == null) return 0;

            int count = 0;
            for (int i = 0; i < MAX_CHAR; i++) {
                if (node.children[i] != null)
                    count += _countNodesInTrie(node.children[i]);
            }
            return 1 + count; // Count this node + its children
        }

        int countNodesInTrie() {
            return _countNodesInTrie(root);
        }

        static int countDistinctSubstrings(String str) {
            SuffixTrie sTrie = new SuffixTrie(str);
            return sTrie.countNodesInTrie();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter any string to construct suffix tree:");
        String str = sc.nextLine();
        int result = SuffixTrie.countDistinctSubstrings(str);
        System.out.println("Count of distinct substrings is: " + (result - 1));
    }
}
