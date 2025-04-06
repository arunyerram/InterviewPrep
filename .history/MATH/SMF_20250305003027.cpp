#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const ll MAXN = 1000000;

vector<ll> spf(MAXN + 1); // spf[i] will store the smallest prime factor of i

void computeSPF() {
    // Initialize spf for every number to itself
    for (ll i = 2; i <= MAXN; i++) {
        spf[i] = i;
    }

    // Start the sieve process
    for (ll i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) { // Check if i is prime
            for (ll j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j) { // Update spf[j] to the smallest prime factor
                    spf[j] = i;
                }
            }
        }
    }
}

int main() {
    // Compute SPF for all numbers from 2 to MAXN
    computeSPF();

    // Example: Print the smallest prime factor for the first 20 numbers
    for (ll i = 2; i <= 20; i++) {
        cout << "Smallest prime factor of " << i << " is " << spf[i] << "\n";
    }

    return 0;
}
