#include <bits/stdc++.h>

using namespace std;

int b[10000][10000];
int main() {
    
    int n,m;
    cin>>n>>m ; 
    for(int i=1;i<=m;i++){
        //taking input of un-directed graph.
        int x,y; 
        cin>>x>>y;
        b[x][y] = 1 ; 
        b[y][x] = 1 ; 
    }
    
    
    for(int i=0;i<=n-1;i++){
        int c = 0 ; 
        for(int j=0;j<=n-1;j++){
            
            if(b[i][j]==1){
                c++;
            }
            
        }
        cout<<i<<" "<<c; 
        cout<<"\n";
    }
}