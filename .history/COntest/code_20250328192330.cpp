#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll m;
        cin>>m;
        vector<int>vec;
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            vec.push_back(x);
        }
        for(ll i=0;i<m;i++){
            vec[i] = min(vec[i],n-1);
        }
        sort(vec.begin(),vec.end());
    }
    
    return 0;
}