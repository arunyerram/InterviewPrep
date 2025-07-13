package CH-3;

import java.util.*;

class TreapNode {
    int data;
    int priority;
    TreapNode left, right;

    TreapNode(int data) {
        this.data = data;
        this.priority = new Random().nextInt(1000);
        this.left = this.right = null;
    }
}

public class KtHLargest {
    static int k;

    public static TreapNode rotateLeft(TreapNode root) {
        TreapNode R = root.right;
        TreapNode X = R.left;
        R.left = root;
        root.right = X;
        return R;
    }

    public static TreapNode rotateRight(TreapNode root) {
        TreapNode L = root.left;
        TreapNode Y = L.right;
        L.right = root;
        root.left = Y;
        return L;
    }

    public static TreapNode insertNode(TreapNode root, int data) {
        if (root == null) {
            return new TreapNode(data);
        }

        if (data < root.data) {
            root.left = insertNode(root.left, data);
            if (root.left != null && root.left.priority > root.priority) {
                root = rotateRight(root);
            }
        } else {
            root.right = insertNode(root.right, data);
            if (root.right != null && root.right.priority > root.priority) {
                root = rotateLeft(root);
            }
        }

        return root;
    }

    static void inorder(TreapNode root) {
        if (root == null) return;

        inorder(root.left);
        k--;
        if (k == 0) {
            System.out.print(root.data);
            return;
        }
        inorder(root.right);
    }

    static void printTreap(TreapNode root) {
        if (root == null) return;

        printTreap(root.left);
        System.out.println(root.data + " " + root.priority);
        printTreap(root.right);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();  // Size of array
        int p = sc.nextInt();  // p-th largest

        k = n - p + 1;         // Convert to k-th smallest

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        TreapNode root = null;
        for (int a : arr) {
            root = insertNode(root, a);
        }

        System.out.println("Treap (inorder with priorities):");
        printTreap(root);

        System.out.println("Kth Largest Element:");
        inorder(root);

        sc.close();
    }
}
