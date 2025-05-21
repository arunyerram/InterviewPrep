import java.util.*;

public class SegmentTreeTest {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        
        SegmentTree st = new SegmentTree(nums);
        while (m-- > 0) {
            int op = sc.nextInt();
            if (op == 1) {
                int s1 = sc.nextInt();
                int s2 = sc.nextInt();
                System.out.println(st.sumRange(s1, s2));
            } else {
                int ind = sc.nextInt();
                int ele = sc.nextInt();
                st.update(ind, ele);
            }
        }
        sc.close();
    }
}


class SegmentTree {
    class SegmentTreeNode {
        int start, end, sum;
        SegmentTreeNode left, right;

        public SegmentTreeNode(int start, int end) {
            this.start = start;
            this.end = end;
            this.sum = 0;
            this.left = null;
            this.right = null;
        }
    }

    private SegmentTreeNode root;

    public SegmentTree(int[] nums) {
        root = buildTree(nums, 0, nums.length - 1);
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

    public void update(int index, int value) {
        update(root, index, value);
    }

    private void update(SegmentTreeNode root, int index, int value) {
        if (root.start == root.end) {
            root.sum = value;
            return;
        }
        
        int mid = (root.start + root.end) / 2;
        if (index <= mid) {
            update(root.left, index, value);
        } else {
            update(root.right, index, value);
        }
        root.sum = root.left.sum + root.right.sum;
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
        } else if (start > mid) {
            return sumRange(root.right, start, end);
        } else {
            return sumRange(root.left, start, mid) + sumRange(root.right, mid + 1, end);
        }
    }
}

