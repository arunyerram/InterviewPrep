#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        if (k == 0) {
            if (n == 1) {
                cout << "A\nB\n";
            } else {
                cout << "-1\n";
            }
            continue;
        }
        if (k == n) {
            string s;
            for (ll i = 0; i < n; ++i) {
                s += char('A' + i % 3);
            }
            cout << s << '\n' << s << '\n';
            continue;
        }
        ll d = n / 2;
        if (k >= d) {
            string s(n, 'A');
            string t(n, 'A');
            ll diff = n - k;
            for (ll i = 1; i < n && diff > 0; i += 2) {
                s[i] = 'B';
                t[i] = 'C';
                diff--;
            }
            //cout << s << '\n' << t << '\n';
            if(diff==0){
            for (ll i = 0; i < n-1; i++) {
                if (s[i] == 'A' && s[i+1] == 'A') {
                    s[i+1] = 'B';
                    t[i+1] = 'B';
                }
            }}else{
                
                s = ""; t = "";
                for (ll i = 0; i < n; i++) {
                    if(i%2==0){
                        s.push_back('B');
                        t.push_back('C');
                    }else{
                        s.push_back('A');
                        t.push_back('A');
                    }
                }
        }
            
            
            cout << s << '\n' << t << '\n';
        } else {
            cout << "-1\n";
        }
    }
    return 0;
}