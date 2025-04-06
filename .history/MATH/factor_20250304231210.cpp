#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll ; 
vector <ll> printDivisors(ll n)
{
	vector<ll> v;
	for (ll i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if (n / i == i){
				v.push_back(i);
			}
			else {
				v.push_back(i);
				v.push_back(n / i);
			}
		}
	}
	
	return v;
}
 
int main()
{
	
	vector <ll> d = printDivisors(12);
	for (int i = d.size() - 1; i >= 0; i--){
		printf("%d ", d[i]);
	}
	
	return 0;
}