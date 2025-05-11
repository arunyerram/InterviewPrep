#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>dir={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};
vector<vector<int>>help;


void Recrse(int i,int j,int m,int n,vector<vector<int>>&arr,vector<vector<bool>>&vis){
    
    queue<pair<pair<int,int>,int>>q;
    q.push({{i,j},0});
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();

        int l = it.first.first;
        int r = it.first.second;
        int c = it.second;


        for(auto d:dir){
            int ni = l + d.first;
            int nj = r + d.second;
            // int c = d.second;

            if(ni >= 0 && nj >= 0 && ni < m && nj < n && !vis[ni][nj] && arr[ni][nj] == 1 && help[ni][nj] > c){
                help[ni][nj] = c + 1;
                vis[ni][nj] = true;
                q.push({{ni,nj},c+1});
            }
        }
    }
}

int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<int>>arr(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
     
    vector<vector<int>>help(m,vector<int>(n,INT_MAX));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] != 1){
                help[i][j] = 0;
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 2){
                vector<vector<bool>>vis(m,vector<bool>(n,false));
                Recrse(i,j,m,n,arr,vis);
            }
        }
    }
    int mn = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 1){
                mn = max(mn,help[i][j]);
            }
        }
    }
    if(mn != INT_MAX){
        cout<<mn<<endl;
    }else{
        cout<<-1<<endl;
    }
        return 0;
    }