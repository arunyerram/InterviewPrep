

// Link -> https://www.desiqna.in/18814/meesho-oa-ctc-35l-tree-climber-29th-june-set-7-kumar-k 

// Pre-requisite Warmup DSA + OA + CP Course - https://docs.google.com/document/d/1DMJKY_L2wem72ygUCao4IpZ7_jOW9LxZMyOPlH-gZQA/edit?tab=t.0 




// -> Always try to solve the easier version by considering a linear tree ⇒ array 

// -> Given an array -> for each index “j” find how many “i” exist in the range [0….j-1] such that a[i]*a[j] ⇒ perfect square; 

// -> Brute Force :-> TC :- O(N^2);

// -> Optimization :-> Any number y == k1.(g)^2; 

// :-> Each number in the array -> we will represent it as :-> k1*(g2)^2; 


// -> Problem solved; 

// -> create k1[] 

// -> for any “j” you need to find how many k1[i] in the range “0 to j-1” have their value == k1[j];

// -> use hashmap for it -> RRRRR 

// -> how will you convert the given number “y” to k1*(g)^2; 

// -> You will do special prime factorization algorithm and multiply factors with odd frequency to generate k1 for the given number -> further explained in video 


// -> Once you have done on the array -> do it on the tree using DFS;

// C++ - https://ideone.com/76ycom ; 
// Java - https://ideone.com/ZicDRU 
// Py -  https://ideone.com/eP5Ot1 


#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define fo(i, start, end) for (ll i = start; i <= end; i++)
#define pfo(i, end, start) for (ll i = end; i >= start; i--)
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sortall(v) sort(all(v))
#define sumv(v) accumulate(all(v), 0LL)
unordered_map <ll,ll> u;ll c = 0 ; 


const ll MAXN = 1000000+1;

vector<ll> spf(MAXN + 1); // spf[i] will store the smallest prime factor of i

void computeSPF() {
    // Initialize spf for every number to itself
    for (ll i = 2; i <= MAXN; i++) {
        spf[i] = i;
    }

    // Start the sieve process
    for (ll i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) { // Check if i is prime
            for (ll j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j) { // Update spf[j] to the smallest prime factor
                    spf[j] = i;
                }
            }
        }
    }
}

unordered_map <ll,ll> cl(ll vl){ unordered_map <ll,ll> a2;
    while(vl!=1){
        ll d = spf[vl]; a2[d]++;
        vl = vl/d;
    }
    return a2;
}







void dfs(ll node,vector <ll> &used,vector <ll> G[],vector <ll> &p,ll b[]){
    used[node] = 1 ;
    //cout<<node<<"\n";
    c = c + u[b[node]];
    u[b[node]]++;
    for(auto u : G[node]){
        if(used[u]==0){
            p[u] = node ;
            dfs(u,used,G,p,b);
        }
        else
        {
 
        }
 
    }
    u[b[node]]--;
}






int main() {
	computeSPF();
	ll n;cin>>n;
	ll b[n]={0};
	fo(i,0,n-1){
		cin>>b[i];
		unordered_map <ll,ll> a2 = cl(b[i]);ll k1 = 1;
        //cout<<"for index i->";
        for(auto itr = a2.begin();itr!=a2.end();++itr){
            ll d = itr->second; 
            if(d%2!=0){
            	k1 = k1*(itr->first);
            }
        }
        b[i] = k1;//cout<<b[i]<<" ";
	}
	
	
	
	
	
	
	
	
	
	vector <ll> G[n];
	fo(i,1,n-1){
		ll u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector <ll> used(n+1,0);
	vector <ll> p(n+1,-1);
	dfs(0,used,G,p,b);
	cout<<c;
    
    return 0;
}




// import java.util.*;

// public class Main {
//     static final int MAXN = 1000001;
//     static int[] spf = new int[MAXN];
//     static long c = 0;
//     static HashMap<Long, Long> u = new HashMap<>();

//     // Sieve to compute smallest prime factor
//     static void computeSPF() {
//         for (int i = 2; i < MAXN; i++) spf[i] = i;
//         for (int i = 2; i * i < MAXN; i++) {
//             if (spf[i] == i) {
//                 for (int j = i * i; j < MAXN; j += i) {
//                     if (spf[j] == j) spf[j] = i;
//                 }
//             }
//         }
//     }

//     // Prime factor count map for one number
//     static HashMap<Integer, Integer> cl(int vl) {
//         HashMap<Integer, Integer> res = new HashMap<>();
//         while (vl != 1) {
//             int d = spf[vl];
//             res.put(d, res.getOrDefault(d, 0) + 1);
//             vl /= d;
//         }
//         return res;
//     }

//     static void dfs(int node, int[] used, List<Integer>[] G, int[] b, int[] parent) {
//         used[node] = 1;
//         long freq = u.getOrDefault((long) b[node], 0L);
//         c += freq;
//         u.put((long) b[node], freq + 1);

//         for (int neigh : G[node]) {
//             if (used[neigh] == 0) {
//                 parent[neigh] = node;
//                 dfs(neigh, used, G, b, parent);
//             }
//         }

//         u.put((long) b[node], u.get((long) b[node]) - 1); // backtrack
//     }

//     public static void main(String[] args) {
//         computeSPF();
//         Scanner sc = new Scanner(System.in);
//         int n = sc.nextInt();
//         int[] b = new int[n];

//         // Step 1: Transform each element into product of odd-count primes
//         for (int i = 0; i < n; i++) {
//             int x = sc.nextInt();
//             HashMap<Integer, Integer> f = cl(x);
//             int k1 = 1;
//             for (Map.Entry<Integer, Integer> e : f.entrySet()) {
//                 if (e.getValue() % 2 != 0) {
//                     k1 *= e.getKey();
//                 }
//             }
//             b[i] = k1;
//         }

//         // Step 2: Build tree
//         List<Integer>[] G = new ArrayList[n];
//         for (int i = 0; i < n; i++) G[i] = new ArrayList<>();
//         for (int i = 1; i < n; i++) {
//             int u = sc.nextInt();
//             int v = sc.nextInt();
//             G[u].add(v);
//             G[v].add(u);
//         }

//         // Step 3: DFS traversal
//         int[] used = new int[n + 1];
//         int[] parent = new int[n + 1];
//         Arrays.fill(parent, -1);
//         dfs(0, used, G, b, parent);
//         System.out.println(c);
//     }
// }



// import sys
// import threading
// from collections import defaultdict

// sys.setrecursionlimit(1 << 25)

// def main():
//     MAXN = 10**6 + 1
//     spf = [0] * MAXN

//     # Step 1: Compute SPF (Smallest Prime Factor)
//     def compute_spf():
//         for i in range(2, MAXN):
//             spf[i] = i
//         for i in range(2, int(MAXN ** 0.5) + 1):
//             if spf[i] == i:
//                 for j in range(i * i, MAXN, i):
//                     if spf[j] == j:
//                         spf[j] = i

//     compute_spf()

//     # Step 2: Prime factorization with SPF
//     def cl(vl):
//         a2 = defaultdict(int)
//         while vl != 1:
//             d = spf[vl]
//             a2[d] += 1
//             vl //= d
//         return a2

//     # Input
//     n = int(input())
//     b = list(map(int, input().split()))

//     # Step 3: Reduce b[i] to square-free part (product of primes with odd count)
//     for i in range(n):
//         a2 = cl(b[i])
//         k1 = 1
//         for prime, cnt in a2.items():
//             if cnt % 2 != 0:
//                 k1 *= prime
//         b[i] = k1

//     # Step 4: Build tree
//     G = [[] for _ in range(n)]
//     for _ in range(n - 1):
//         u, v = map(int, input().split())
//         G[u].append(v)
//         G[v].append(u)

//     used = [0] * (n + 1)
//     p = [-1] * (n + 1)
//     freq_map = defaultdict(int)
//     c = 0

//     # Step 5: DFS traversal
//     def dfs(node):
//         nonlocal c
//         val = b[node]
//         c += freq_map[val]
//         freq_map[val] += 1
//         for nei in G[node]:
//             if not used[nei]:
//                 used[nei] = 1
//                 p[nei] = node
//                 dfs(nei)
//         freq_map[val] -= 1  # backtrack

//     used[0] = 1
//     dfs(0)
//     print(c)

// # Run main in a separate thread to handle recursion depth
// threading.Thread(target=main).start()
