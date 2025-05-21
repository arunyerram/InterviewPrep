
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
        vector<ll>v(n + 1);ll sum = 0;
        for(int i=0;i<n;i++){
            ll x;
            cin >> x;
            v[i + 1] = x;
            sum += x;
        }
        ll s1 = 0;ll cnt = 0;
        ll mn = INT_MAX;
        ll rmv = 0;
        sort(v.begin(),v.end());
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i != j){
                    s1 += v[i]*v[j];
                }
            }
            mn = min(mn,s1*(sum - s1));
            s1 = 0;
            if(mn <= s1){

            }
        }
        



    }
    

    

}