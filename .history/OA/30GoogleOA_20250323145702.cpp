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

