#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ; 
// A function to print all prime
// factors of a given number n
 
unordered_map<ll,ll> primeFactors(ll n)
{
	unordered_map <ll,ll> a2 ;
	// Print the number of 2s that divide n
	while (n % 2 == 0)
	{
		a2[2]++;
		n = n/2;
	}

	// n must be odd at this point. So we can skip
	// one element (Note i = i +2)
	for (ll i = 3; i <= sqrt(n); i = i + 2)
	{
		// While i divides n, print i and divide n
		while (n % i == 0)
		{
			a2[i]++;
			n = n/i;
		}
	}

	// This condition is to handle the case when n
	// is a prime number greater than 2
	if (n > 2)
		a2[n]++;
		
	return a2;
}

/* Driver code */
int main()
{
	ll n = 18;
	unordered_map <ll,ll> a2 = primeFactors(n);
	for(auto itr=a2.begin();itr!=a2.end();++itr){
		cout<<itr->first<<" "<<itr->second;
		cout<<"\n";
	}
	return 0;
}

// This is code is contributed by rathbhupendra
