#include<bits/stdc++. >
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;

    vector<int>v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.emplace_back(a);
    }
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[v[i]] = i;
    }
    int mx = 0;
    for(auto it:v){
        mx = max(mx,mmp);
    }

    return 0;
}