#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ; 

int main() {
	int n;
	cin>>n ; 
	int a[n+1];
	int i = 1 ; 
	while(i<=n){
		cin>>a[i];
		i++;
	}
    int ans = 0;
    unordered_map<int,int>mp;
	unordered_map <ll,ll> kk ; 
	int count = 0 ; 
	i = 1 ; 
	while(i<=n){
        count += kk[a[a[a[i]]]];
        kk[a[a[a[i]]]]++;
        i++;
	}
    //  OOOOOOOOORRRRRRRRRRRRRRR...................................

    
    for(int i=1; i<=n; i++)
        mp[a[a[a[i]]]]++;
    
    for(auto it: mp){
        ll x=it.second;
        ans+=(x)*(x-1)/2;
    }

	cout<<count<<" ";
    cout<<ans<<endl;
	return 0;
}

