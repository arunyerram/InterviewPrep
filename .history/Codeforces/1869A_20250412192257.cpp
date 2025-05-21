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
        int i = 1;
        // sort(v.begin(),v.end());
        if(v[0] == v[n-1] && v[0] == 0)cout<<0<<endl;
        else if(v[0] == v[n-1]){
            cout<<1<<endl;
        else{
            // 1 2 3 4 6
            int x = 0;
            for(int j=0;j<n;j++){
                x ^= v[j];
            }
            if(x == 0){
                cout<<1<<endl;
                cout<<i<<" "<<n<<endl;
            }
            else if(n%2 == 0){
                cout<<2<<endl;
                // while (i < 2)
                // {   
                    cout<<i<<" "<<n<<endl;
                    cout<<i<<" "<<n<<endl;
            }else{
                cout<<3<<endl;
                // while (i < 3)
                // {   
                    cout<<i <<" "<<n<<endl;
                    cout<<i<<" "<<n-1<<endl;
                    cout<<n<<" "<<n<<endl;
                //

            }
    }
        // }
    }
        return 0;
}