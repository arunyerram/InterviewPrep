#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>arr;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int k;
    cin>>k;

    map<int,int>mp1;
    for(auto it:arr){
        mp1[it]++;
    }
    map<int,vector<int>>mp2;
    for(auto it:mp1){
        mp2[it.second].push_back(it.first);
    }
    priority_queue<int>pq;
    for(auto it:mp2){
        pq.push(it.first);
    }
    int m = pq.size();
    while(k > 0){
        
    }
}