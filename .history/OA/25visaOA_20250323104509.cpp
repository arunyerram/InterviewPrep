#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<vector<int>>pts = {{1,7},{5,9},{7,11}};
    vector<int>points;
    int mx = 0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        points.push_back(x);
    }
    vector<int>ans(mx+2,0);

    for(int i=0;i<pts.size();i++){
        int l = pts[i][0];
        int r = pts[i][1];
        ans[l] += 1;
        if(r+1 <= n)
        ans[r+1] -= 1;
    }
    for(int i=1;i<ans.size();i++){
        ans[i] += ans[i-1];
    }

    for(auto it:points){
        cout<<ans[it]<<" ";
    }
    return 0;
}