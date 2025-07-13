package SegTree;



// -> We will make a tree on the array 

// Tree will consist of nodes. 

// Each node will have an index and sum associated to it 

// If node[g] = b it means node with index g has sum “b” 

// For the “i” number node; left child is 2*i and right child is;
// 2*i + 1 

// Recursion :- Create the tree using recursion. In short fill the value of node array using recursion; 


// Node :- Index i ; Sum g  + Special parameter :- Range is also attached to a node which is invisible but you can calculate it 


// -> build(1(first index of node array),0,n-1) 

// void build(ll index,ll start,ll end)
// {
//     if(start==end)
//     {
//         node[index]=b[start];
//     }
//     else
//     {
//         ll mid=(start+end)/2;
//         build(2*index,start,mid);
//         build(2*index+1,mid+1,end);
//         node[index]=node[2*index]+node[2*index+1];
//     }
    
// }

// Flow :- 

// Let’s say the given array is :- 1,3,8,8 

// First you will call (1,0,3)  

// Then you call (2,0,1)

// Then you call (4,0,0) Yes start == end; node[4] = b[0] 

// Then you call (2,0,1) :- And you realize its left child is already have been;
// Executed so now you call :- (5,1,1) node[5] = b[1] 

// Now you again call (2,0,1) and you see both the childs have been processed so you execute the last line :-  node[2] = node[4] + node[5] 
// And like this you build the whole stuff. 

// —-----------------------------------------------------------------

// How to find the sum of range (l,r) in segment tree:- 

// Start at the top of the segment tree! 

// If the current range is not exactly equal to (l,r) divide it into two-parts. 

// ll query(ll node,ll start,ll end,ll l,ll r)
// {
 
//     if(start>r || end<l)
//     {
//         return 0;
//     }
 
//     if(start>=l && end<=r)
//     {
//         return segtree[node];
//     }
 
 
//         ll mid=(start+end)/2;
 
//         ll left=query(node*2,start,mid,l,r);
//         ll right=query(node*2+1,mid+1,end,l,r);
 
//         return (left+right);
 
 
 
// }

// Update Query :- b[i] = y  

// From the top root node; you need to reach the leaf. 

// void update(ll node,ll start,ll end,ll ind,ll value)
// {
//    if(start==end)
//    {
//        segtree[node]=value;
//        a[ind]=value;
//    }
//    else
//    {
//        ll mid=(start+end)/2;
 
//        if(ind<=mid)
//        {
//            update(2*node,start,mid,ind,value);
//        }
//        else
//        {
//             update(2*node+1,mid+1,end,ind,value);
//        }
 
//        segtree[node]=segtree[2*node] + segtree[2*node+1];
 
 
 
//    }
 
 
 
// }


// C++ https://ideone.com/04QTpf.  
// Java. https://ideone.com/mXtRUw
// Py https://ideone.com/fK317k






import java.util.Scanner;

public class SegTree {
    static long[] a = new long[200000];
    static long[] segtree = new long[1000000];

    static void build(int node, int start, int end) {
        if (start == end) {
            segtree[node] = a[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
        }
    }

    static long query(int node, int start, int end, int l, int r) {
        if (start > r || end < l) {
            return 0;
        }
        if (start >= l && end <= r) {
            return segtree[node];
        }
        int mid = (start + end) / 2;
        long left = query(2 * node, start, mid, l, r);
        long right = query(2 * node + 1, mid + 1, end, l, r);
        return left + right;
    }

    static void update(int node, int start, int end, int ind, long value) {
        if (start == end) {
            segtree[node] = value;
            a[ind] = value;
        } else {
            int mid = (start + end) / 2;
            if (ind <= mid) {
                update(2 * node, start, mid, ind, value);
            } else {
                update(2 * node + 1, mid + 1, end, ind, value);
            }
            segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int i = 0;
        while (i <= n - 1) {
            a[i] = sc.nextLong();
            i++;
        }
        build(1, 0, n - 1);
        update(1, 0, n - 1, 4, 100);
        System.out.println(query(1, 0, n - 1, 1, 4));
    }
}
