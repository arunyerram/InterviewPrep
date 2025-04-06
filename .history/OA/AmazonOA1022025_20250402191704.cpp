

new code
samples
recent codes
sign in

fork  download copy
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll h[200005]; ll dp[200005];vector <ll> G[200005];
void dfs(ll node,vector <ll> &used,vector <ll> G[],vector <ll> &p){
   used[node] = 1 ;
   //cout<<node;
   //cout<<"\n";

   for(auto u : G[node]){
       if(used[u]==0){
           p[u] = node ;
           dfs(u,used,G,p);
       }
       else
       {

       }

   }




   ll d = 0 ;
    for(auto u : G[node]){
       if(u!=p[node]){
         d = max(d,h[u]);
       }
       else
       {

       }
    }
    h[node] = d + 1;
    //cout<<node<<" "<<h[node]<<"\n";
}

void dfs2(ll node,vector <ll> &used,vector <ll> G[],vector <ll> &p){
   used[node] = 1 ;
   //cout<<node;
   //cout<<"\n";

   for(auto u : G[node]){
       if(used[u]==0){
           p[u] = node ;
           dfs2(u,used,G,p);
       }
       else
       {

       }

   }
   vector <ll> child;
   for(auto u : G[node]){
       if(u!=p[node]){
         child.push_back(u);
         }
   }


   ll n = child.size();

   if(n>=1){
   vector <ll> prefix(n,0);prefix[0] = dp[child[0]];
   vector <ll> suffix(n,0);suffix[n-1] = dp[child[n-1]]; 
   for(ll i=1;i<n;i++){
       prefix[i] = prefix[i-1] + dp[child[i]]; 
   }
   for(ll i=n-2;i>=0;i--){
       suffix[i] = suffix[i+1] + dp[child[i]]; 
   }




   ll d = 0 ;ll id = 0 ; 
   for(auto u : G[node]){
       if(u!=p[node]){ll z = 0 ; 
         // for(auto u2 : G[node]){
             // if(u2!=p[node] && u!=u2){
                 // z = z + dp[u2]; 
             // }
         // }

         if(id-1>=0){
             z = z + prefix[id-1];
         }
         if(id+1<=n-1){
             z = z + suffix[id+1];
         }


         dp[node] = max(dp[node],z + dp[u] + 2*h[u] + 1);id++;
       }
       else
       {

       }

   }
   }
   if(G[node].size()==0){
       dp[node] = 1;
   }
   //cout<<node<<" "<<dp[node]<<"\n";
}


int main() {
   ll t;
   cin>>t;
   while(t--){
       ll n;cin>>n; 
       for(ll i=1;i<=n;i++){
           G[i].clear();
       }
       for(ll i=1;i<=n-1;i++){
           ll d;cin>>d;G[d].push_back(i+1);dp[i]=0;h[i]=0;
           //cout<<d<<" "<<i+1<<"\n";
       }vector <ll> used(n+1,0); vector <ll> p(n+1,-1);dp[n]=0;h[n]=0;
       dfs(1,used,G,p);vector <ll> used2(n+1,0);
       dfs2(1,used2,G,p);
       cout<<dp[1]<<"\n";
   }



   return 0;
}
Success #stdin #stdout 0.01s 9520KB comments (0)
stdin copy
2
5
1 2 3 3 
7
1 1 2 2 3 3  
stdout copy
17
15

https://ideone.com/Rze38x
language:C++14 (gcc 8.3)
created:2 hours ago
visibility: secret

Share or Embed source code
<script src="https://ideone.com/e.js/Rze38x" type="text/javascript" ></script>
    


Discover > Sphere Engine API
The brand new service which powers Ideone!

Discover > IDE Widget
Widget for compiling and running the source code in a web browser!

Sphere Research Labs. Ideone is powered by Sphere Engine™
Home API Language FAQ Credits desktop mobile
Terms of Service Privacy Policy GDPR Info

Feedback & Bugs
Popular languages:

Bash Pascal C Perl C# PHP C++ Python C++14 Python3 Haskell Ruby Java SQLite Objective-C Swift VB.net
List of all supported programming languages


new code
samples
recent codes
sign in

fork  download copy
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
ll h[200005]; ll dp[200005];vector <ll> G[200005];
void dfs(ll node,vector <ll> &used,vector <ll> G[],vector <ll> &p){
   used[node] = 1 ;
   //cout<<node;
   //cout<<"\n";

   for(auto u : G[node]){
       if(used[u]==0){
           p[u] = node ;
           dfs(u,used,G,p);
       }
       else
       {

       }

   }




   ll d = 0 ;
    for(auto u : G[node]){
       if(u!=p[node]){
         d = max(d,h[u]);
       }
       else
       {

       }
    }
    h[node] = d + 1;
    //cout<<node<<" "<<h[node]<<"\n";
}

void dfs2(ll node,vector <ll> &used,vector <ll> G[],vector <ll> &p){
   used[node] = 1 ;
   //cout<<node;
   //cout<<"\n";

   for(auto u : G[node]){
       if(used[u]==0){
           p[u] = node ;
           dfs2(u,used,G,p);
       }
       else
       {

       }

   }
   vector <ll> child;
   for(auto u : G[node]){
       if(u!=p[node]){
         child.push_back(u);
         }
   }


   ll n = child.size();

   if(n>=1){
   vector <ll> prefix(n,0);prefix[0] = dp[child[0]];
   vector <ll> suffix(n,0);suffix[n-1] = dp[child[n-1]]; 
   for(ll i=1;i<n;i++){
       prefix[i] = prefix[i-1] + dp[child[i]]; 
   }
   for(ll i=n-2;i>=0;i--){
       suffix[i] = suffix[i+1] + dp[child[i]]; 
   }




   ll d = 0 ;ll id = 0 ; 
   for(auto u : G[node]){
       if(u!=p[node]){ll z = 0 ; 
         // for(auto u2 : G[node]){
             // if(u2!=p[node] && u!=u2){
                 // z = z + dp[u2]; 
             // }
         // }

         if(id-1>=0){
             z = z + prefix[id-1];
         }
         if(id+1<=n-1){
             z = z + suffix[id+1];
         }


         dp[node] = max(dp[node],z + dp[u] + 2*h[u] + 1);id++;
       }
       else
       {

       }

   }
   }
   if(G[node].size()==0){
       dp[node] = 1;
   }
   //cout<<node<<" "<<dp[node]<<"\n";
}


int main() {
   ll t;
   cin>>t;
   while(t--){
       ll n;cin>>n; 
       for(ll i=1;i<=n;i++){
           G[i].clear();
       }
       for(ll i=1;i<=n-1;i++){
           ll d;cin>>d;G[d].push_back(i+1);dp[i]=0;h[i]=0;
           //cout<<d<<" "<<i+1<<"\n";
       }vector <ll> used(n+1,0); vector <ll> p(n+1,-1);dp[n]=0;h[n]=0;
       dfs(1,used,G,p);vector <ll> used2(n+1,0);
       dfs2(1,used2,G,p);
       cout<<dp[1]<<"\n";
   }



   return 0;
}
Success #stdin #stdout 0.01s 9520KB comments (0)
stdin copy
2
5
1 2 3 3 
7
1 1 2 2 3 3  
stdout copy
17
15

https://ideone.com/Rze38x
language:C++14 (gcc 8.3)
created:2 hours ago
visibility: secret

Share or Embed source code
<script src="https://ideone.com/e.js/Rze38x" type="text/javascript" ></script>
    


Discover > Sphere Engine API
The brand new service which powers Ideone!

Discover > IDE Widget
Widget for compiling and running the source code in a web browser!

Sphere Research Labs. Ideone is powered by Sphere Engine™
Home API Language FAQ Credits desktop mobile
Terms of Service Privacy Policy GDPR Info

Feedback & Bugs
Popular languages:

Bash Pascal C Perl C# PHP C++ Python C++14 Python3 Haskell Ruby Java SQLite Objective-C Swift VB.net
List of all supported programming languages


ShareThis Copy and Pastenew code samples recent codes sign in fork download copy #include <bits/stdc++.h>   using namespace std; typedef long long int ll; ll h[200005]; ll dp[200005];vector <ll> G[200005]; void dfs(ll node,vector <ll> &used,vector <ll> G[],vector <ll> &p){ used[node] = 1 ; //cout<<node; //cout<<"\n";   for(auto u : G[node]){ if(used[u]==0){ p[u] = node ; dfs(u,used,G,p); } else {   }   }         ll d = 0 ; for(auto u : G[node]){ if(u!=p[node]){ d = max(d,h[u]); } else {   } } h[node] = d + 1; //cout<<node<<" "<<h[node]<<"\n"; }   void dfs2(ll node,vector <ll> &used,vector <ll> G[],vector <ll> &p){ used[node] = 1 ; //cout<<node; //cout<<"\n";   for(auto u : G[node]){ if(used[u]==0){ p[u] = node ; dfs2(u,used,G,p); } else {   }   } vector <ll> child; for(auto u : G[node]){ if(u!=p[node]){ child.push_back(u); } }     ll n = child.size();   if(n>=1){ vector <ll> prefix(n,0);prefix[0] = dp[child[0]]; vector <ll> suffix(n,0);suffix[n-1] = dp[child[n-1]]; for(ll i=1;i<n;i++){ prefix[i] = prefix[i-1] + dp[child[i]]; } for(ll i=n-2;i>=0;i--){ suffix[i] = suffix[i+1] + dp[child[i]]; }         ll d = 0 ;ll id = 0 ; for(auto u : G[node]){ if(u!=p[node]){ll z = 0 ; // for(auto u2 : G[node]){ // if(u2!=p[node] && u!=u2){ // z = z + dp[u2]; // } // }   if(id-1>=0){ z = z + prefix[id-1]; } if(id+1<=n-1){ z = z + suffix[id+1]; }     dp[node] = max(dp[node],z + dp[u] + 2*h[u] + 1);id++; } else {   }   } } if(G[node].size()==0){ dp[node] = 1; } //cout<<node<<" "<<dp[node]<<"\n"; }     int main() { ll t; cin>>t; while(t--){ ll n;cin>>n; for(ll i=1;i<=n;i++){ G[i].clear(); } for(ll i=1;i<=n-1;i++){ ll d;cin>>d;G[d].push_back(i+1);dp[i]=0;h[i]=0; //cout<<d<<" "<<i+1<<"\n"; }vector <ll> used(n+1,0); vector <ll> p(n+1,-1);dp[n]=0;h[n]=0; dfs(1,used,G,p);vector <ll> used2(n+1,0); dfs2(1,used2,G,p); cout<<dp[1]<<"\n"; }       return 0; } Success #stdin #stdout 0.01s 9520KB comments (0) stdin copy 2 5 1 2 3 3 7 1 1 2 2 3 3 stdout copy 17 15 https://ideone.com/Rze38x language:C++14 (gcc 8.3) created:2 hours ago visibility: secret Share or Embed source code Discover > Sphere Engine API The brand new service which powers Ideone! Discover > IDE Widget Widget for compiling and running the source code in a web browser! Sphere Research Labs. Ideone is powered by Sphere Engine™ home api language faq credits desktop mobile terms of service privacy policy gdpr info Feedback & Bugs popular languages: bash pascal c perl c# php c++ python c++14 python3 haskell ruby java sqlite objective-c swift vb.net list of all supported programming languages How would you rate your experience? Hate Love Next new code samples recent codes sign in fork download copy #include <bits/stdc++.h>   using namespace std; typedef long long int ll; ll h[200005]; ll dp[200005];vector <ll> G[200005]; void dfs(ll node,vector <ll> &used,vector <ll> G[],vector <ll> &p){ used[node] = 1 ; //cout<<node; //cout<<"\n";   for(auto u : G[node]){ if(used[u]==0){ p[u] = node ; dfs(u,used,G,p); } else {   }   }         ll d = 0 ; for(auto u : G[node]){ if(u!=p[node]){ d = max(d,h[u]); } else {   } } h[node] = d + 1; //cout<<node<<" "<<h[node]<<"\n"; }   void dfs2(ll node,vector <ll> &used,vector <ll> G[],vector <ll> &p){ used[node] = 1 ; //cout<<node; //cout<<"\n";   for(auto u : G[node]){ if(used[u]==0){ p[u] = node ; dfs2(u,used,G,p); } else {   }   } vector <ll> child; for(auto u : G[node]){ if(u!=p[node]){ child.push_back(u); } }     ll n = child.size();   if(n>=1){ vector <ll> prefix(n,0);prefix[0] = dp[child[0]]; vector <ll> suffix(n,0);suffix[n-1] = dp[child[n-1]]; for(ll i=1;i<n;i++){ prefix[i] = prefix[i-1] + dp[child[i]]; } for(ll i=n-2;i>=0;i--){ suffix[i] = suffix[i+1] + dp[child[i]]; }         ll d = 0 ;ll id = 0 ; for(auto u : G[node]){ if(u!=p[node]){ll z = 0 ; // for(auto u2 : G[node]){ // if(u2!=p[node] && u!=u2){ // z = z + dp[u2]; // } // }   if(id-1>=0){ z = z + prefix[id-1]; } if(id+1<=n-1){ z = z + suffix[id+1]; }     dp[node] = max(dp[node],z + dp[u] + 2*h[u] + 1);id++; } else {   }   } } if(G[node].size()==0){ dp[node] = 1; } //cout<<node<<" "<<dp[node]<<"\n"; }     int main() { ll t; cin>>t; while(t--){ ll n;cin>>n; for(ll i=1;i<=n;i++){ G[i].clear(); } for(ll i=1;i<=n-1;i++){ ll d;cin>>d;G[d].push_back(i+1);dp[i]=0;h[i]=0; //cout<<d<<" "<<i+1<<"\n"; }vector <ll> used(n+1,0); vector <ll> p(n+1,-1);dp[n]=0;h[n]=0; dfs(1,used,G,p);vector <ll> used2(n+1,0); dfs2(1,used2,G,p); cout<<dp[1]<<"\n"; }       return 0; } Success #stdin #stdout 0.01s 9520KB comments (0) stdin copy 2 5 1 2 3 3 7 1 1 2 2 3 3 stdout copy 17 15 https://ideone.com/Rze38x language:C++14 (gcc 8.3) created:2 hours ago visibility: secret Share or Embed source code Discover > Sphere Engine API The brand new service which powers Ideone! Discover > IDE Widget Widget for compiling and running the source code in a web browser! Sphere Research Labs. Ideone is powered by Sphere Engine™ home api language faq credits desktop mobile terms of service privacy policy gdpr info Feedback & Bugs popular languages: bash pascal c perl c# php c++ python c++14 python3 haskell ruby java sqlite objective-c swift vb.net list of all supported programming languages How would you rate your experience? Hate Love Next ShareThis Copy and Paste