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
        //    int LHS = a[a[a[i]]]; 
        //    kk[LHS] = kk[LHS] + 1 ;//storing the elment in the map 
        // maintaining its frequency
            kk[a[a[a[i]]]]++;
            i++;
	}
	cout<<count ; 
	return 0;
}