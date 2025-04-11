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

        if(n%2 == 0 || n%3 == 0)cout<<"NO"<<endl;
        else{
            // prime cHeck
            for(ll i=5;i*i<=n;i+=6){
                if(n%i == 0 || n%(i+2) == 0){
                    cout<<"NO"<<endl;
                    break;
                }
            }
            cout<<"YES"<<endl;
        }

        // ll res = 0;
    }
