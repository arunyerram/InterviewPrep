#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;

    vector<vector<int>>vec(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>vec[i][j];
        }
    }
    queue<pair<int,int>>q;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(vec[i][j]==1){
                q.push({i,j});
            }
        }
    }
}