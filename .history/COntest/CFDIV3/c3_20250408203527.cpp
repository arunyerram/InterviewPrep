#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n;
        cin>>k;
        string s = to_string(n);
        if(n%2 == 0 || n%3 == 0 || n%5 == 0 || n%7 == 0 || n%11 == 0)cout<<"NO"<<endl;
        else{
            // prime cHeck
            
            bool f= false;
            for(ll i=5;i*i<=n;i+=6){
                if(n%i == 0 || n%(i+2) == 0){
                    f = true;
                    cout<<"NO"<<endl;
                    break;
                }
            }
            if(!f) cout<<"YES"<<endl;
        }

        // ll res = 0;
    }
    return 0;
}
