// Sridhar brought his latest Apple iPhone 12 pro. He started his conversation 
// with one of his friend on WhatsApp with list of words.

// Now it’s our task to find and return what are the most common words 
// in the list of words he used in sorted order based on occurrence from 
// largest to smallest. If any of words he used are having same occurrence 
// then consider the lexicographic order.

// You will be given a list of words, you need to print top P number of 
// most common used words as described in the statement. 

// Input Format:
// -------------
// Line-1: comma separated line of words, list of words.
// Line-2: An integer P, number of words to display. 

// Output Format:
// --------------
// Print P number of most common used words.


// Sample Input-1:
// ---------------
// ball,are,case,doll,egg,case,doll,egg,are,are,egg,case,are,egg,are,case
// 3

// Sample Output-1:
// ----------------
// [are, case, egg]

// Sample Input-2:
// ---------------
// ball,are,case,doll,egg,case,doll,egg,are,are,egg,case,are,egg,are
// 3

// Sample Output-2:
// ----------------
// [are, egg, case]


import java.util.*;

class TrieNode {
    TrieNode[] children = new TrieNode[26];
    int freq = 0;
    boolean isEnd = false;
}

class Trie {
    TrieNode root = new TrieNode();
    
    void insert(String word) {
        TrieNode curr = root;
        for (char ch : word.toCharArray()) {
            int idx = ch - 'a';
            if (curr.children[idx] == null)
                curr.children[idx] = new TrieNode();
            curr = curr.children[idx];
        }
        curr.isEnd = true;
        curr.freq++;
    }

    void collectWords(TrieNode node, StringBuilder sb, List<String> result, Map<String, Integer> freqMap) {
        if (node == null) return;
        if (node.isEnd) {
            String word = sb.toString();
            result.add(word);
            freqMap.put(word, node.freq);
        }
        for (char c = 'a'; c <= 'z'; c++) {
            int idx = c - 'a';
            if (node.children[idx] != null) {
                sb.append(c);
                collectWords(node.children[idx], sb, result, freqMap);
                sb.deleteCharAt(sb.length() - 1);
            }
        }
    }
}

public class FrequentWord {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] words = sc.nextLine().split(",");
        int P = Integer.parseInt(sc.nextLine());

        Trie trie = new Trie();
        for (String word : words) {
            trie.insert(word);
        }

        List<String> wordList = new ArrayList<>();
        Map<String, Integer> freqMap = new HashMap<>();

        trie.collectWords(trie.root, new StringBuilder(), wordList, freqMap);

        Collections.sort(wordList, (a, b) -> {
            int freqA = freqMap.get(a);
            int freqB = freqMap.get(b);
            if (freqA != freqB) return freqB - freqA;
            return a.compareTo(b);
        });

        System.out.println(wordList.subList(0, P));
    }
}
