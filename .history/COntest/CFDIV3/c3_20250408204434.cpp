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
        if(n < 10 && k > 1)cout<<"NO"<<endl;
        else if(n < 10 && k == 1){
            if(n == 2 || n == 3 || n == 5 || n == 7)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        // else if(n%2 == 0 || n%3 == 0 || n%5 == 0)cout<<"NO"<<endl;
        else{
            // prime cHeck
            for(int i=0;i<k;i++){
                s += to_string(n); 
            }
            ll num = stoll(s);
            if(num%2 == 0 || num %3 == 0 || num%5 == 0 || num%7 == 0) cout<<"NO"<<endl;
            else{
                bool f= false;
                for(ll i=5;i*i<=num;i+=6){
                    if(num%i == 0 || num%(i+2) == 0){
                        f = true;
                        cout<<"NO"<<endl;
                        break;
                    }
                }
                if(!f) cout<<"YES"<<endl;
            }
        }
        // ll res = 0;
    }
    return 0;
}
