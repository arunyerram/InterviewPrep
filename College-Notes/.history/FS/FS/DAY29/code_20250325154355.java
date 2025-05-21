
// Treap

package FS.FS.DAY29;

import java.util.Random;

class TreapNode {
    int key, priority;
    TreapNode left, right;

    public TreapNode(int key) {
        this.key = key;
        this.priority = new Random().nextInt();
        this.left = this.right = null;
    }
}

class Treap {
    private TreapNode root;

    private TreapNode rightRotate(TreapNode y) {
        TreapNode x = y.left;
        TreapNode T = x.right;
        x.right = y;
        y.left = T;
        return x;
    }

    private TreapNode leftRotate(TreapNode x) {
        TreapNode y = x.right;
        TreapNode T = y.left;
        y.left = x;
        x.right = T;
        return y;
    }

    private TreapNode insert(TreapNode root, int key) {
        if (root == null) return new TreapNode(key);

        if (key < root.key) {
            root.left = insert(root.left, key);
            if (root.left.priority > root.priority)
                root = rightRotate(root);
        } else if (key > root.key) {
            root.right = insert(root.right, key);
            if (root.right.priority > root.priority)
                root = leftRotate(root);
        }
        return root;
    }

    private TreapNode delete(TreapNode root, int key) {
        if (root == null) return null;

        if (key < root.key) {
            root.left = delete(root.left, key);
        } else if (key > root.key) {
            root.right = delete(root.right, key);
        } else {
            if (root.left == null) {
                return root.right;
            } else if (root.right == null) {
                return root.left;
            } else {
                if (root.left.priority > root.right.priority) {
                    root = rightRotate(root);
                    root.right = delete(root.right, key);
                } else {
                    root = leftRotate(root);
                    root.left = delete(root.left, key);
                }
            }
        }
        return root;
    }

    private boolean search(TreapNode root, int key) {
        if (root == null) return false;
        if (root.key == key) return true;
        return key < root.key ? search(root.left, key) : search(root.right, key);
    }

    private void inorder(TreapNode root) {
        if (root != null) {
            inorder(root.left);
            System.out.println("Key: " + root.key + " | Priority: " + root.priority);
            inorder(root.right);
        }
    }

    public void insert(int key) {
        root = insert(root, key);
    }

    public void delete(int key) {
        root = delete(root, key);
    }

    public boolean search(int key) {
        return search(root, key);
    }

    public void inorder() {
        inorder(root);
    }

    public static void main(String[] args) {
        Treap treap = new Treap();

        treap.insert(50);
        treap.insert(30);
        treap.insert(20);
        treap.insert(40);
        treap.insert(70);
        treap.insert(60);
        treap.insert(80);

        System.out.println("Inorder traversal of Treap:");
        treap.inorder();

        System.out.println("\nDeleting key 40");
        treap.delete(40);
        treap.inorder();

        System.out.println("\nSearch key 30: " + treap.search(30));
        System.out.println("Search key 100: " + treap.search(100));
    }
}
