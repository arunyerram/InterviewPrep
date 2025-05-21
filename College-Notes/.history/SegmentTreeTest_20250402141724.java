import java.util.*;

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

