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
        string s = "";
        if(n < 10 && k > 1)
        if(n%2 == 0 || n%3 == 0 || n%5)cout<<"NO"<<endl;
        else{
            // prime cHeck
            for(int i=0;i<k;i++){
                s += to_string(n); 
            }

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
