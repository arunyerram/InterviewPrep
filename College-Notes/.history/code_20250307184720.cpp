#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>dir={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};

int main(){
    int m,n;
    cin>>m>>n;

    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    

    return 0;
}