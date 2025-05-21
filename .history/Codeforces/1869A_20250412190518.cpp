// 1 3 4 5 6

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll t;
    cin>>t;

    while(t-- > 0){
        ll n;
        cin>>n;
        vector<ll>v;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            v.push_back(x);
        }
        int i = 0;
        sort(v.begin(),v.en());
        cout<<2<<endl;
        // while (i < 2)
        // {   
            cout<<i<<" "<<n-1<<endl;
            cout<<i<<" "<<n-1<<endl;
        // }
    }
        return 0;
}