
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// ..........GRAPH...............
int main(){
    int t;
    cin>>t;

    while(t-- > 0){
        ll n,c;
        cin >> n >> c;
        vector<ll>v(n + 1);
        for(int i=0;i<n;i++){
            ll x;
            cin >> x;
            v[i + 1] = x;
        }
        ll sum = 0;
        ll s1 = 0;ll cnt = 0;
        sort(v.begin(),v.end());
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                s1 += v[i + ]*v[j + 1];
                sum += v[i];
            }   
        }
        



    }
    

    

}