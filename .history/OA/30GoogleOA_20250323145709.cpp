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
	unordered_map <ll,ll> kk ; 
	int count = 0 ; 
	i = 1 ; 
	while(i<=n){
        count += kk[a[a[a[i]]]];
        kk[a[a[a[i]]]]++;
        i++;
	}
	cout<<count ; 
	return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

ll n;
cin>>n;

vector<int> v(n+1);
for(int i=1; i<=n; i++){
    cin>>v[i];
}
map<int,int> mp;    ll ans=0;

for(int i=1; i<=n; i++){
    mp[v[v[v[i]]]]++;
    // ans=max(ans,mp[v[v[v[i]]]]);
}
for(auto it: mp){
    ll x=it.ss;
    ans+=(x)*(x-1)/2;
}

cout<<ans<<'\n';