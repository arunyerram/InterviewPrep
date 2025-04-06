#include <bits/stdc++.h>
using namespace std;
void DFS(int node,vector <int> G[],vector <int> & used,vector <int> &parent){
    
    cout<<node;
    cout<<"\n";
    used[node] = 1 ; 
    
    for(auto u: G[node]){ //iterating all children "u" of "node"
        
        if(used[u]==0){
            //if this node/branch has never been visited before 
            //just go into it and search it using dfs in recursion
            parent[u] = node ; 
            DFS(u,G,used,parent);   
        }   
    }
}

int main() {
    int n ; 
    cin>>n ; 
    int m ; 
    cin>>m ; 
    vector <int> G[n+5] ; 
    int i = 1 ; 
    while(i<=m){
        int u,v ; 
        cin>>u>>v ; 
        G[u].push_back(v);
        G[v].push_back(u); 
        i++;
    }
    vector <int> used(n+5,0);
    vector <int> parent(n+5,0);
    DFS(1,G,used,parent); //starts from node 1  
    return 0 ; 
}








// import java.util.ArrayList;
// import java.util.List;
// import java.util.Scanner;

// public class Main {
//     public static void DFS(int node, List<Integer>[] G, List<Integer> used, List<Integer> parent) {
//         System.out.println(node);
//         used.set(node, 1);

//         for (int u : G[node]) {
//             if (used.get(u) == 0) {
//                 parent.set(u, node);
//                 DFS(u, G, used, parent);
//             }
//         }
//     }

//     public static void main(String[] args) {
//         Scanner scanner = new Scanner(System.in);

//         int n = scanner.nextInt();
//         int m = scanner.nextInt();
//         List<Integer>[] G = new List[n + 5];
//         for (int i = 0; i < n + 5; i++) {
//             G[i] = new ArrayList<>();
//         }

//         int i = 1;
//         while (i <= m) {
//             int u = scanner.nextInt();
//             int v = scanner.nextInt();
//             G[u].add(v);
//             G[v].add(u);
//             i++;
//         }

//         List<Integer> used = new ArrayList<>(n + 5);
//         List<Integer> parent = new ArrayList<>(n + 5);
//         for (int j = 0; j < n + 5; j++) {
//             used.add(0);
//             parent.add(0);
//         }

//         DFS(1, G, used, parent);
//     }
// }






// def DFS(node, G, used, parent):
//     print(node)
//     used[node] = 1
    
//     for u in G[node]:
//         if used[u] == 0:
//             parent[u] = node
//             DFS(u, G, used, parent)

// n = int(input())
// m = int(input())
// G = [[] for _ in range(n + 5)]

// for _ in range(m):
//     u, v = map(int, input().split())
//     G[u].append(v)
//     G[v].append(u)

// used = [0] * (n + 5)
// parent = [0] * (n + 5)

// DFS(1, G, used, parent)

