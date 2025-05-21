// You're given a binary tree represented in level-order (with -1 denoting nulls). Your task is to print all paths from each leaf node to the root, preserving the order from leaf → parent → … → root. Each path should be printed on a new line, with node values joined by " —> ".
// If the current node is null, return.
// If the current node is a leaf (no left or right children), print the current path.

// Input Format:
// ------------
// Line-1: A single line containing space-separated integers representing the binary tree in level-order.
// Use -1 to represent a null (no child).

// Output Format:
// --------------
// Each line represents one path from a leaf node to the root.
// Node values must be joined using " —> ".
// Order of output paths may vary based on traversal, but all valid paths must be included

// Constraints:
// -------------
// 1 ≤ number of nodes ≤ 10^4
// Node values are integers in the range [-10^9, 10^9]
// Input tree is binary (each node has at most two children)
// Input is provided in level-order, and -1 denotes nulls

// Sample Input-1:
// ------------------
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1

// Sample Output-1:
// --------------
// 4 —> 2 —> 1  
// 5 —> 2 —> 1  
// 8 —> 6 —> 3 —> 1  
// 9 —> 6 —> 3 —> 1  
// 7 —> 3 —> 1

// Sample Input-2:
// -------------
// 1 -1 2 -1 3 -1 4

// Sample Output-2:
// -------------------
// 4 —> 3 —> 2 —> 1


import java.util.*;

public class Main2 {

    static class TreeNode {
        int val;
        TreeNode left, right;

        TreeNode(int v) {
            val = v;
        }
    }

    public static TreeNode buildTree(List<Integer> nodes) {
        if (nodes.size() == 0 || nodes.get(0) == -1) return null;

        TreeNode root = new TreeNode(nodes.get(0));
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        int i = 1;
        while (i < nodes.size()) {
            TreeNode curr = q.poll();

            if (i < nodes.size() && nodes.get(i) != -1) {
                curr.left = new TreeNode(nodes.get(i));
                q.offer(curr.left);
            }
            i++;

            if (i < nodes.size() && nodes.get(i) != -1) {
                curr.right = new TreeNode(nodes.get(i));
                q.offer(curr.right);
            }
            i++;
        }

        return root;
    }

    public static void dfs(TreeNode node, List<Integer> path) {
        if (node == null) return;

        path.add(node.val);

        if (node.left == null && node.right == null) {
            for (int i = path.size() - 1; i >= 0; i--) {
                System.out.print(path.get(i));
                if (i > 0) System.out.print(" —> ");
            }
            System.out.println();
        } else {
            dfs(node.left, path);
            dfs(node.right, path);
        }

        path.remove(path.size() - 1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] parts = sc.nextLine().trim().split("\\s+");

        List<Integer> levelOrder = new ArrayList<>();
        for (String part : parts) {
            levelOrder.add(Integer.parseInt(part));
        }

        TreeNode root = buildTree(levelOrder);
        dfs(root, new ArrayList<>());
    }
}
