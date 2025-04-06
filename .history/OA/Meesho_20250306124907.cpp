#include<bits/stdc++.h>
using namespace std;

map<int,int>mp;
int sum = 0;
int cnt = 0;

void Recrse(int i,vector<int>G[],int used[],int parent[],int m){
    used[i] = 1;
    sum += i;
    mp[sum%3]++;
    if(mp[sum%3] > 1)
        cnt += mp[(sum)%3];

    for(auto it:G[i]){
        if(used[it] == 0){
            parent[it] = i;
            Recrse(it,G,used,parent);
        }
    }
    mp[sum%3]--;
    sum -= i;
    used[i] = 0;
}
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;

    vector<int>G[n+1];

    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int used[n+1] = {0};
    int parent[n+1] = {0};
    used[1] = 1;
    Recrse(1,G,used,parent,m);
    cout<<cnt<<endl;
    return 0;
}