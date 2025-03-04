#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[51] = {0};
    unordered_map<int,int>mp;
    int n = 0;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x] = mp[x] + 1;
        // arr[x]++;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        // mp[x]++;
        cout<<mp[x]<<endl;
    }
    
}