

import java.util.*;

// A Treap Node
class TreapNode {
    int key, priority;
    TreapNode left, right;
}

public class treap {

    // Right Rotation
    public static TreapNode rightRotate(TreapNode y) {
        System.out.println("rightRotate " + y.key);
        TreapNode x = y.left;
        TreapNode T2 = x.right;

        // Perform rotation
        x.right = y;
        y.left = T2;

        // Return new root
        return x;
    }

    // Left Rotation
    public static TreapNode leftRotate(TreapNode x) {
        System.out.println("leftRotate " + x.key);
        TreapNode y = x.right;
        TreapNode T2 = y.left;

        // Perform rotation
        y.left = x;
        x.right = T2;

        // Return new root
        return y;
    }

    // Create a new Treap node
    public static TreapNode newNode(int key) {
        TreapNode temp = new TreapNode();
        temp.key = key;
        temp.priority = (int)(Math.random() * 100);
        temp.left = temp.right = null;
        return temp;
    }

    // Insert a new key
    public static TreapNode insertNode(TreapNode root, int key) {
        if (root == null) {
            return newNode(key);
        }

        if (key <= root.key) {
            root.left = insertNode(root.left, key);
            if (root.left.priority > root.priority) {
                root = rightRotate(root);
            }
        } else {
            root.right = insertNode(root.right, key);
            if (root.right.priority > root.priority) {
                root = leftRotate(root);
            }
        }

        return root;
    }

    // Delete a key
    public static TreapNode deleteNode(TreapNode root, int key) {
        if (root == null)
            return root;

        if (key < root.key) {
            root.left = deleteNode(root.left, key);
        } else if (key > root.key) {
            root.right = deleteNode(root.right, key);
        } else {
            if (root.left == null) {
                TreapNode temp = root.right;
                root = temp;
            } else if (root.right == null) {
                TreapNode temp = root.left;
                root = temp;
            } else if (root.left.priority < root.right.priority) {
                root = leftRotate(root);
                root.left = deleteNode(root.left, key);
            } else {
                root = rightRotate(root);
                root.right = deleteNode(root.right, key);
            }
        }

        return root;
    }

    // Search for a key
    public static TreapNode search(TreapNode root, int key) {
        if (root == null || root.key == key)
            return root;

        if (root.key < key)
            return search(root.right, key);
        else
            return search(root.left, key);
    }

    // Preorder traversal
    static void preorder(TreapNode root) {
        if (root != null) {
            System.out.println("key: " + root.key + " | priority: " + root.priority);
            preorder(root.left);
            preorder(root.right);
        }
    }

    // Main method
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        TreapNode root = null;
        for (int a : arr) {
            root = insertNode(root, a);
        }

        System.out.println("Initial Treap (Preorder):");
        preorder(root);

        System.out.println("Enter item to search:");
        int key = sc.nextInt();
        TreapNode result = search(root, key);

        if (result != null)
            System.out.println("Search result: " + result.key + " " + result.priority);
        else
            System.out.println("Key " + key + " not found");

        do {
            System.out.println("Enter item to delete:");
            key = sc.nextInt();
            root = deleteNode(root, key);
            System.out.println("After delete:");
            preorder(root);
        } while (key != -1 && root != null);

        sc.close();
    }
}
