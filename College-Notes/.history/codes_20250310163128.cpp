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
    map<int,vector<int,greater<int>>>mp2;
    for(auto it:mp1){
        mp2[it.second].push_back(it.first);
    }
    priority_queue<int>pq;
    for(auto it:mp2){
        pq.push(it.first);
    }
    int m = pq.size();
    vector<int>ans;
    while(k > 0){
        auto ele = pq.top();
        pq.pop();
        
        if(mp2[ele].size() <= k){
            k -= mp2[ele].size();
            int j = 0;
            while(j < mp2[ele].size()){
                for(int i=0;i<ele;i++){
                    ans.push_back(mp2[ele][j]);
                }j++;
            }
        }else{
            while(k > 0){
                

                k--;
            }
        }
    }
    for(auto it:ans)cout<<it<<endl;
}