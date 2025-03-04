#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    map<int,int>mp;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int x;
    cin>>x;
    // for(auto it:arr){
    //     mp[it]++;
    // }
    int ans[2]= {0};
    for(int i=0;i<n;i++){
        if(mp.find(x - arr[i]) != mp.end()){
            ans[0] = x-arr[i];
            ans[1] = arr[i];
            break;
        }else{
            mp[arr[i]]++;
        }
    }
    cout<<ans[0]<<ans[1]<<endl;
    return 0;
}

