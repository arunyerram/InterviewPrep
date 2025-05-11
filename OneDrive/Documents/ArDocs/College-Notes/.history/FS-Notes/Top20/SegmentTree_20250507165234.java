import java.util.*;

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
        // printTree(root); // Optional for debug
    }

    // Optional Debug Method
    public void printTree(SegmentTreeNode root) {
        if (root == null) return;
        System.out.println("[" + root.start + "," + root.end + "] -> " + root.sum);
        printTree(root.left);
        printTree(root.right);
    }

    private SegmentTreeNode buildTree(int[] nums, int start, int end) {
        if (start > end) return null;

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

    public void update(int index, int val) {
        update(root, index, val);
    }

    private void update(SegmentTreeNode root, int index, int val) {
        if (root.start == root.end) {
            root.sum = val;
        } else {
            int mid = (root.start + root.end) / 2;
            if (index <= mid) {
                update(root.left, index, val);
            } else {
                update(root.right, index, val);
            }
            root.sum = root.left.sum + root.right.sum;
        }
    }

    public int sumRange(int i, int j) {
        return sumRange(root, i, j);
    }

    private int sumRange(SegmentTreeNode root, int start, int end) {
        if (root.start == start && root.end == end) {
            return root.sum;
        }

        int mid = (root.start + root.end) / 2;
        if (end <= mid) {
            return sumRange(root.left, start, end);
        } else if (start >= mid + 1) {
            return sumRange(root.right, start, end);
        } else {
            return sumRange(root.left, start, mid) + sumRange(root.right, mid + 1, end);
        }
    }

    // Main method inside same class (or move to separate class as needed)
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt(); // size of array
        int q = scan.nextInt(); // number of queries
        int[] nums = new int[n];

        for (int i = 0; i < n; i++) {
            nums[i] = scan.nextInt();
        }

        SegmentTree st = new SegmentTree(nums);

        while (q-- > 0) {
            int opt = scan.nextInt();
            if (opt == 1) {
                int l = scan.nextInt();
                int r = scan.nextInt();
                System.out.println(st.sumRange(l, r));
            } else {
                int index = scan.nextInt();
                int val = scan.nextInt();
                st.update(index, val);
            }
        }
    }
}
