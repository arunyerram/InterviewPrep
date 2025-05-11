
// In a joint family, every person is assigned with an ID, an integer value.
// and the entire family is arranged in the from of tree.

// You will be given the family tree and two persons IDs P1 and P2.
// Your task is to find the person ID, who is the latest common ascendant of P1 and P2.
// and return the Lowest Common Ascendant ID.

// Implement the class Solution:
//     - Node lowestCommonAscendant(Node root, Node P1, Node P2):
//         return the person ID who is the latest common ascendant of P1 and P2.

// Input Format:
// -------------
// Line-1: Single line of space separated integers, person ID's in the family.
// Line-2: Two Person IDs, P1 and P2.

// Output Format:
// --------------
// Return the latest common ascendant of P1 and P2.


// Sample Input-1:
// ---------------
// 3 5 1 6 2 0 8 -1 -1 7 4
// 6 4

// Sample Output-1:
// ----------------
// 5

// Sample Input-2:
// ---------------
// 11 99 88 77 22 33 66 55 10 20 30 40 50 60 44
// 66 55

// Sample Output-2:
// ----------------
// 11



import java.util.*;

class Node {
    public int data;
    public Node left;
    public Node right;
    public Node(int value) {
        data = value;
        left = null;
        right = null;
    }
}

public class LCA {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String[] arr = sc.nextLine().split(" ");
        String[] persons = sc.nextLine().split(" ");

        List<Integer> v = new ArrayList<>();
        for (String s : arr) {
            v.add(Integer.parseInt(s));
        }

        Node root = buildTree(v);

        int p1 = Integer.parseInt(persons[0]);
        int p2 = Integer.parseInt(persons[1]);

        Node res = new Solution().lowestCommonAscendant(root, p1, p2);
        System.out.println(res.data);
}

    static Node buildTree(List<Integer> v) {
        if (v.size() == 0 || v.get(0) == -1) return null;

        Node root = new Node(v.get(0));
        Queue<Node> q = new LinkedList<>();
        q.offer(root);
        int i = 1;

        while (i < v.size()) {
            Node curr = q.poll();
            if (i < v.size() && v.get(i) != -1) {
                curr.left = new Node(v.get(i));
                q.offer(curr.left);
        }
            i++;
            if (i < v.size() && v.get(i) != -1) {
                curr.right = new Node(v.get(i));
                q.offer(curr.right);
        }
            i++;
        }
        return root;
    }
}

class Solution {
    public Node lowestCommonAscendant(Node root, int p1, int p2) {

        if (root == null || root.data == p1 || root.data == p2)
            return root;

        Node left = lowestCommonAscendant(root.left, p1, p2);
        Node right = lowestCommonAscendant(root.right, p1, p2);

        if (left != null && right != null)
            return root;

        return (left != null) ? left : right;
        }
    }import java.util.*;

class Node {
    public int data;
    public Node left;
    public Node right;
    public Node(int value) {
        data = value;
        left = null;
        right = null;
    }
}

public class LCA {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String[] arr = sc.nextLine().split(" ");
        String[] persons = sc.nextLine().split(" ");

        List<Integer> v = new ArrayList<>();
        for (String s : arr) {
            v.add(Integer.parseInt(s));
        }

        Node root = buildTree(v);

        int p1 = Integer.parseInt(persons[0]);
        int p2 = Integer.parseInt(persons[1]);

        Node res = new Solution().lowestCommonAscendant(root, p1, p2);
        System.out.println(res.data);
}

    static Node buildTree(List<Integer> v) {
        if (v.size() == 0 || v.get(0) == -1) return null;

        Node root = new Node(v.get(0));
        Queue<Node> q = new LinkedList<>();
        q.offer(root);
        int i = 1;

        while (i < v.size()) {
            Node curr = q.poll();
            if (i < v.size() && v.get(i) != -1) {
                curr.left = new Node(v.get(i));
                q.offer(curr.left);
        }
            i++;
            if (i < v.size() && v.get(i) != -1) {
                curr.right = new Node(v.get(i));
                q.offer(curr.right);
        }
            i++;
        }
        return root;
    }
}

class Solution {
    public Node lowestCommonAscendant(Node root, int p1, int p2) {

        if (root == null || root.data == p1 || root.data == p2)
            return root;

        Node left = lowestCommonAscendant(root.left, p1, p2);
        Node right = lowestCommonAscendant(root.right, p1, p2);

        if (left != null && right != null)
            return root;

        return (left != null) ? left : right;
        }
    }