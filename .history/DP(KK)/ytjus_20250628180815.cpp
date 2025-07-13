
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll g;cin>>g;
    ll n;cin>>n;

    ll c[n + 1] = {0};
    ll r[n + 1] = {0};

    for(int i=1;i<n;i ){
        cin>>c[i];
    }
    ll mx = 0;
    for(int j = 1;j<n;j++){
        cin>>r[j];
        mx = max(mx, r[j]);
    }

    return 0;
}