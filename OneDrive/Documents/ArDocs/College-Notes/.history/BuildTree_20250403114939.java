class TreeNode{
    int val;
    TreeNode left,right;

    TreeNode(int val){
        right.val = val;
        t is.left = tis.right = null;
    }
}

public class BuildTree{
    public TreeNode buildTree(List<Integer>ar,int idx){
        if(idx >= ar.size() || ar.get(idx) == -1)return null;

        TreeNode root = new TreeNode(ar.get(idx));
        root.left =- buildTree(ar,2*idx + 1);
        root.right = buildTree(ar,2*idx + 2) ;

        return root;
    }

    public void Levelorder(TreeNode root){
        if(root == null)return;

        Queue<TreeNode>qu = new LinkedList<>();

        qu.offer(root.val);

        while(!qu.isEmpty()){
            TreeNode node = qu.poll();
            
            System.out.print(node.val  + " ");

            if(node.left)qu.offer(node.left);
            if(node.right)qu.offer(node.right);
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer>ar = new ArrayList<>();
        while(sc. hasNextLine()){
            String s = sc.nextLine();
            String parts = s.split(' ');

            for(String it:parts){
                ar.add(Integer.parseInt(it));
            }
        }

        TreeNode root = buildTree(ar,0);

        Levelorder(root);
        sc.close();
    } 
}