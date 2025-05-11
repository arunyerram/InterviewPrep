import java.util.*;

class Node {
    int val;
    Node left;
    Node right;

    public Node(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        String[] s = sc.nextLine().split(" ");
        
        int[] arr = new int[s.length];
        for (int i = 0; i < s.length; i++) {
            arr[i] = Integer.parseInt(s[i]);
        }
        
        Node root = build(arr);
        
        int totalSum = Sum(root, 0);
        System.out.println("Sum of all nodes: " + totalSum);
        
        System.out.print("Inorder Traversal: ");
        Inorder(root);
        System.out.println();
    }
    
    // Function to build a binary tree from the array
    public static Node build(int[] arr) {
        if (arr.length == 0) return null;

        Queue<Node> queue = new LinkedList<>();
        Node root = new Node(arr[0]);
        queue.add(root);
        
        int i = 1;
        while (i < arr.length) {
            Node parent = queue.poll();
            
            if (i < arr.length) {
                parent.left = new Node(arr[i++]);
                queue.add(parent.left);
            }
            if (i < arr.length) {
                parent.right = new Node(arr[i++]);
                queue.add(parent.right);
            }
        }
        return root;
    }
    
    // Function to compute sum of all nodes
    public static int Sum(Node root, int sum) {
        if (root == null) return sum;
        sum = root.val + Sum(root.left, sum) + Sum(root.right, sum);
        return sum;
    }
    
    // Function to perform inorder traversal
    public static void Inorder(Node root) {
        if (root == null) return;
        
        Inorder(root.left);
        System.out.print(root.val + " ");
        Inorder(root.right);
    }
}
