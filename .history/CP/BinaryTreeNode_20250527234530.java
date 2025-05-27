

import java.util.*;

class BinaryTreeNode {
    public int data;
    public BinaryTreeNode left, right;
    public BinaryTreeNode(int data) {
        this.data = data;
        left = right = null;
    }
}

public class LowestCommonAncestor {
    static int[] depth, parent;
    static boolean[] visited;
    static BinaryTreeNode root;

    // Insert nodes in level order
    static void insert(BinaryTreeNode temp, int key) {
        if (temp == null) {
            root = new BinaryTreeNode(key);
            return;
        }
        Queue<BinaryTreeNode> q = new LinkedList<>();
        q.add(temp);
        while (!q.isEmpty()) {
            temp = q.poll();
            if (temp.left == null) {
                temp.left = new BinaryTreeNode(key);
                break;
            } else {
                q.add(temp.left);
            }
            if (temp.right == null) {
                temp.right = new BinaryTreeNode(key);
                break;
            } else {
                q.add(temp.right);
            }
        }
    }

    // DFS to populate depth[] and parent[] arrays
    static void dfs(BinaryTreeNode node) {
        visited[node.data] = true;
        if (node.left != null) {
            depth[node.left.data] = depth[node.data] + 1;
            parent[node.left.data] = node.data;
            dfs(node.left);
        }
        if (node.right != null) {
            depth[node.right.data] = depth[node.data] + 1;
            parent[node.right.data] = node.data;
            dfs(node.right);
        }
    }

    // Bring both nodes to same depth, then climb up until they meet
    static BinaryTreeNode lca(BinaryTreeNode root, BinaryTreeNode u, BinaryTreeNode v) {
        while (depth[u.data] != depth[v.data]) {
            if (depth[u.data] > depth[v.data]) {
                depth[u.data] = depth[parent[u.data]];
                u.data = parent[u.data];
            } else {
                depth[v.data] = depth[parent[v.data]];
                v.data = parent[v.data];
            }
        }
        while (u.data != v.data) {
            u.data = parent[u.data];
            v.data = parent[v.data];
        }
        return u;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Read tree nodes for level-order insertion
        String[] nodes = sc.nextLine().split(" ");
        root = new BinaryTreeNode(Integer.parseInt(nodes[0]));
        for (int i = 1; i < nodes.length; i++) {
            insert(root, Integer.parseInt(nodes[i]));
        }
        // Read the two target nodes
        BinaryTreeNode p = new BinaryTreeNode(sc.nextInt());
        BinaryTreeNode q = new BinaryTreeNode(sc.nextInt());
        sc.close();

        // Initialize helper arrays (assuming max node value < 100)
        depth = new int[100];
        parent = new int[100];
        visited = new boolean[100];

        depth[root.data] = 1;
        dfs(root);

        BinaryTreeNode ancestor = lca(root, p, q);
        System.out.println(ancestor.data);
    }
}
