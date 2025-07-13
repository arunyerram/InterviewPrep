// given two arrays find max sum possible and no two adjacent elements pick up from 2 arrays




#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int>v1;
    vector<int>v2;
    cin>>n;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v1.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v2.push_back(x);
    }
    vector<int>dp(n+1,0);   
    dp[0] = 0;
}