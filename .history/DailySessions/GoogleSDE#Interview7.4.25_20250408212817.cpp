
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){