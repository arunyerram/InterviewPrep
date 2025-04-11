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
        // ll res = 0;
