
// public class SegmentTree {
//     class Node {
//         int start, end;
//         Node left, right;
//         int sum;

//         public Node(int start, int end) {
//             this.start = start;
//             this.end = end;
//             this.left = null;
//             this.right = null;
//             this.sum = 0;
//         }
//     }

//     Node root;

//     public SegmentTree(int[] nums) {
//         root = buildTree(nums, 0, nums.length - 1);
//         printTree(root);
//     }

//     public void printTree(Node root) {
//         if (root == null) {
//             return;
//         }
//         printTree(root.left);
//         printTree(root.right);
//         System.out.println(root.start + " " + root.end + " " + root.sum);
//     }

//     public Node buildTree(int[] nums, int start, int end) {

//         Node node = new Node(start, end);
//         if (start == end) {
//             node.sum = nums[start];
//             // return node;
//         } else {
//             int mid = start + (end - start) / 2;
//             node.left = buildTree(nums, start, mid);
//             node.right = buildTree(nums, mid + 1, end);
//             node.sum = node.left.sum + node.right.sum;
//         }
//         return node;
//     }

//     public static void main(String[] args) {
//         int[] nums = { 1, 3, 5 };
//         SegmentTree st = new SegmentTree(nums);

//     }

// }

import java.util.*;

class Node{
    int sum;
    int start, end;
    public Node left, right;
    public Node(int start, int end){
        this.start = start;
        this.end = end;
        this.right = null;
        this.left = null;
        this.sum = 0;
    }
}

public class SegmentTreeTest{
    
    Node root = null;
    
    public SegmentTreeTest(int arr[]){
        root = build(arr, 0, arr.length-1);
    }
    
    public Node build(int arr[], int start, int end){
        if(start > end){
            return null;
        }else{
            Node n = new Node(start, end);
            if(start == end){
                n.sum = arr[start];
            }else{
                int mid = (start+end)/2;
                n.left = build(arr, start, mid);
                n.right = build(arr,mid+1, end);
                n.sum = n.left.sum + n.right.sum;
            }
            return n;   
        }
    }
    
    public void update(int idx, int val){
        update(root,idx,val);
    }
    
    public void update(Node root, int idx, int val){
        if (root.start == root.end){
            root.sum = val;
        }else{
            int mid = (root.start + root.end) / 2;
            if (idx <= mid){
                update(root.left, idx, val);
            }else{
                update(root.right, idx, val);
            }
            root.sum = root.left.sum + root.right.sum;
        }
    }

    public int sumRange(int i, int j){
        return sumRange(root, i, j);
    }

    public int sumRange(Node root, int start, int end){
        if (root.start == start && root.end == end){
            return root.sum;
        }else{
            int mid = (root.start + root.end) / 2;
            if (end <= mid){
                return sumRange(root.left, start, end);
            } else {
                if (start >= mid + 1){
                    return sumRange(root.right, start, end);
                } else{
                    return sumRange(root.left, start, mid) + sumRange(root.right, mid + 1, end);
                }
            }
        }
    }
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int arr[] = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        SegmentTreeTest s = new SegmentTreeTest(arr);
        while(q != 0){
            int op = sc.nextInt();
            if(op == 1){
                int st = sc.nextInt();
                int en = sc.nextInt();
                System.out.println(s.sumRange(st,en));
            }else{
                int idx = sc.nextInt();
                int val = sc.nextInt();
                s.update(idx, val);
            }
            q = q - 1;
        }
    }
}