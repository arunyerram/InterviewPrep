/*All Permutations : https://i...content-available-to-author-only...e.com/JHFpoH
All Combinations : https://i...content-available-to-author-only...e.com/qKsREQ 
All Subsets : https://i...content-available-to-author-only...e.com/fHD0H3
*/
//print prime numbers from range..l....to....r
#include<bits/stdc++.h>
using namespace std; 
#define all(v) v.begin(), v.end() 
typedef long long int ll;
vector<ll> sieve(ll n) 
{ 
	vector<bool> prime(n + 1, true); 
 	prime[0] = false; 
	prime[1] = false; 
	long long int m = sqrt(n); 
 	for (ll p = 2; p <= m; p++) { 
 
		// If prime[p] is not changed, then it 
		// is a prime 
		if (prime[p]) { 
 
			// Update all multiples of p 
			for (ll i = p * p; i <= n; i += p) 
				prime[i] = false; 
		} 
	} 
 
	// push all the primes into the vector ans 
	vector<ll> ans; 
	for (ll i = 0; i < n; i++) 
		if (prime[i]) 
			ans.push_back(i); 
	return ans; 
} 

vector<ll> sieveRange(ll start, ll end) 
{ 
	// find primes from [0..end] range 
	vector<ll> ans = sieve(end); 
 
	// Find index of first prime greater than or 
	// equal to start 
	// O(sqrt(n)loglog(n)) 
	long long int lower_bound_index = lower_bound(all(ans), start) - 
											ans.begin(); 
 
	// Remove all elements smaller than start. 
	// O(logn) 
	ans.erase(ans.begin(), ans.begin() + lower_bound_index); 
 
	return ans; 
} 
 
 
int main() 
{
    ll f,l,r;
 
    vector<ll> a(1000070, 0);
    l = 1 ; 
    r = 100;
    f=0;
    r++;
    ll start = l; 
    ll end = r; 
    vector<ll> ans = sieveRange(start, end); 
    for (auto i : ans) {
    	a[i]=1;
        cout<<i<<endl ; 
    }
	return 0; 
}  