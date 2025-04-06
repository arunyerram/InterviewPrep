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
        vector<int>vec(m,0);
        for(int i=0;i<m;i++)
            int x;
            cin>>x;
            vec[i] = x;
        }
        for(ll i=0;i<m;i++){
            vec[i] = min(vec[i],n-1);
        }
        
        sort(vec.begin(),vec.end());
        int j = m-1;
        ll ans = 0;
        ll sum = 0;
        
        for(ll i=0;i<m;i++){
            while(j >= 0 && vec[j]   vec[i] >= n){
                sum += vec[j];
                j--;
            }
            ans += sum + (m-j-1)*(vec[i] - n + 1); 
        }
        for(ll i = 0;i<m;i++){
            if(2*vec[i] >= n){
                ans -= 2*vec[i] - n + 1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}