#include<bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;

    map<int,vector<int>>mp1;
    for(int i=0;i<a.size();i++){
        if(i&1 == 0)
            mp1[0].push_back(a[i]);
        else{
            mp1[1].push_back(a[i]);
        }
    }

    for(auto i=0;i<b.size();i++){
        if(i&1 == 0){
            if(mp[0])
        }
    }
}