
// Program to implement Disjoint Set Data Structure.

/*
5 = number of friends
3 = number of relationships
2 = number of friendship check
input=5
3
0 2
4 2
3 1
2
4 0
1 0
output=4 is a friend of 0
1 is not a friend of 0

*/




import java.util.*;

class DisjointUnionSets {
    int[] rank, parent;
    int n;

    public DisjointUnionSets(int n){
        rank = new int[n];
        parent = new int[n];
        this.n = n;
        makeSet();
    }

    void makeSet(){
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x){
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }

    void union(int x, int y){
        int xRoot = find(x);
        int yRoot = find(y);

        if (xRoot == yRoot)
            return;

        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
}

public class test {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt(); 
        DisjointUnionSets dsu = new DisjointUnionSets(n);

        int relations = sc.nextInt(); 
        for (int i = 0; i < relations; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            dsu.union(a, b);
        }

        int queries = sc.nextInt(); 
        for (int i = 0; i < queries; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            if (dsu.find(a) == dsu.find(b)) {
                System.out.println(a + " is a friend of " + b);
            } else {
                System.out.println(a + " is not a friend of " + b);
            }
        }
        sc.close();
    }
}


