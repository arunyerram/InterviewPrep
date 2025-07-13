
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
ll func(ll mid, ll c[], ll r[]){
    ll sum = 0;
    for(int j=1;j<N;j++){
        sum = sum + c[j]*(((mid-1)/r[j]) + 1); 
    }
    return sum;
}

int main(){
    ll g;cin>>g;
    ll n;cin>>n;
    N = n;
    ll c[n + 1] = {0};
    ll r[n + 1] = {0};

    for(int i=1;i<n;i++){
        cin>>c[i];
    }
    ll mx = -1;
    for(int j = 1;j<n;j++){
        cin>>r[j];
        mx = max(mx, r[j]);
    }
    ll low = 1;ll lst = 1e18;
    while(low <= lst){
        ll mid = (low + lst) / 2;
        if(func(mid,c,r) >= g){
            mx = mid;
            lst = mid-1;
        }else low = mid + 1; 
    }
    cout<<mx<<endl;
    return 0;
}