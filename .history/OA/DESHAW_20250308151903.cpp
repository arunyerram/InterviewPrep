#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>dir={
    {0,1},{1,0},
    {0,-1},{-1,0}
};

int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<int>>vec(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>vec[i][j];
        }
    }
    vector<vector<bool>>vis(m,vector<bool>(n,false));
    queue<pair<int,int>>q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(vec[i][j]==1){
                q.push({i,j});
                vis[i][j]= true;
            }
        }
    }

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        int x = it.first;
        int y = it.second;

        for(auto d:dir){
            int nx = x+d.first;
            int ny = y+d.second;

            if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && ){
                vis[nx][ny]=true;
                vec[nx][ny] = 0;
                q.push({nx,ny});
            }
        }
    }

    return 0;
}