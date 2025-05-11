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

class SegmentTree{
    class SegmentTreeNode{
        int start,end,sum=0;
        SegmentTreeNode left,right;

        SegmentTreeNode(int start,int end){
            this.left = null;
            this.right  = null;
            this.start = start;
            this.end = end;
            this.sum = 0;
        }
    }
    SegmentTreeNode root = null;
    SegmentTree(int[] nums){
        root = BuildTree(nums, 0, nums.length - 1);
    }
    public SegmentTreeNode BuildTree(int[] nums, int start, int end){
        if(start > end){
            // root = null;
            return null;
        }
        // int mid = (start + end) / 2;
        else{
            SegmentTreeNode node = new SegmentTreeNode(start, end);
            if(start == end){
                node.sum = nums[start];
            }
            else{
                int mid = (start + end) / 2;
                node.left = BuildTree(nums,start,mid);
                node.right = BuildTree(nums,mid+1,end);
                
                node.sum = node.left.sum + node.right.sum;
            }
            return node;
        }
    }

    public void update(int ind,int val){
        update(root,ind,val);
    }

    public void update(SegmentTreeNode root, int ind, int val){
        if(root.start == root.end){
            root.sum = val;
            // return;
        }
        int mid = (root.start + root.end)/2;
        if(mid <= ind){
            update(root.left,ind,val);
        } else{
            update(root.right,ind,val);
        }
        root.sum = root.left.sum + root.right.sum;
    }
    public int sumRange(int start,int end){
        return sumRange(root,start,end);
    }
    public int sumRange(SegmentTreeNode root,int start,int end){
        if(root.start == start && root.end == end){
            root.sum = root.start;
            return root.sum;
        }

        int mid = (root.start + root.end) / 2;
        if(end <= mid){
            return sumRange(root.left,start,end);
        }else if(start > mid){
            return sumRange(root.right,start,end);
        }else{
            return sumRange(root.left, start,mid)  + sumRange(root.right,mid + 1,end);
        }
    }
}