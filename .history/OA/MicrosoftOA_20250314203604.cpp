#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; 
    cin>>n;

    vector<int>arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int mx = -1;
    map<int,priority_queue<int>>mp;

    for(auto it:arr){
        int ele = it;
        int sum = 0;
        while(ele > 0){
            sum += ele % 10;
            ele /= 10;
        }mp[sum].push(it);
    }

    for(auto it:mp){
        if(it.second.size() >= 2){
            int e1 = it.second.top();
            it.second.pop();
            int e2 = it.second.top();
            it.second.pop();
            mx = max(e1,e2);
        }
    }
    return 0;
}