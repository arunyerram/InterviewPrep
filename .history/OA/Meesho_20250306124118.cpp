#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>G[n+1];

    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int used[n+1] = {0};
    int parent[n+1] = {0};

    Recrse();
}