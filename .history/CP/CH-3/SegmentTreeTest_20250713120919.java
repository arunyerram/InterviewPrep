
import java.util.*;



class SegmentTreeTest {
    public static void main(String args[]) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        int q = scan.nextInt();

        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scan.nextInt();
        }

        SegmentTree st = new SegmentTree(nums);

        while (q-- > 0) {
            int opt = scan.nextInt();
            if (opt == 1) {
                int s1 = scan.nextInt();
                int s2 = scan.nextInt();
                System.out.println(st.sumRange(s1, s2));
            } else {
                int ind = scan.nextInt();
                int val = scan.nextInt();
                st.update(ind, val);
            }
        }

        scan.close();
    }
}



public class SegmentTree {

    class SegmentTreeNode {
        int start, end;
        SegmentTreeNode left, right;
        int sum;

        public SegmentTreeNode(int start, int end) {
            this.start = start;
            this.end = end;
            this.left = null;
            this.right = null;
            this.sum = 0;
        }
    }

    SegmentTreeNode root = null;

    public SegmentTree(int[] nums) {
        root = buildTree(nums, 0, nums.length - 1);
        printTree(root); // Optional debug method
    }

    private void printTree(SegmentTreeNode root) {
        if (root == null) return;
        printTree(root.left);
        printTree(root.right);
    }

    private SegmentTreeNode buildTree(int[] nums, int start, int end) {
        if (start > end) {
            return null;
        }

        SegmentTreeNode node = new SegmentTreeNode(start, end);

        if (start == end) {
            node.sum = nums[start];
        } else {
            int mid = (start + end) / 2;
            node.left = buildTree(nums, start, mid);
            node.right = buildTree(nums, mid + 1, end);
            node.sum = node.left.sum + node.right.sum;
        }

        return node;
    }

    public void update(int i, int val) {
        update(root, i, val);
    }

    private void update(SegmentTreeNode node, int pos, int val) {
        if (node.start == node.end) {
            node.sum = val;
        } else {
            int mid = (node.start + node.end) / 2;
            if (pos <= mid) {
                update(node.left, pos, val);
            } else {
                update(node.right, pos, val);
            }
            node.sum = node.left.sum + node.right.sum;
        }
        printTree(root); // Optional debug method
    }

    public int sumRange(int i, int j) {
        return sumRange(root, i, j);
    }

    private int sumRange(SegmentTreeNode node, int start, int end) {
        if (node.start == start && node.end == end) {
            return node.sum;
        }

        int mid = (node.start + node.end) / 2;

        if (end <= mid) {
            return sumRange(node.left, start, end);
        } else if (start >= mid + 1) {
            return sumRange(node.right, start, end);
        } else {
            return sumRange(node.left, start, mid) +
                   sumRange(node.right, mid + 1, end);
        }
    }
}
