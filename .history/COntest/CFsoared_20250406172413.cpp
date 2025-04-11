#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n), b(n);vector <pair<ll,ll>> p;
        map<pair<ll, ll>, ll> bondFreq;
        map<pair<ll, ll>, pair<ll, ll>> hashmap1;ll iu = -1;
        for (ll i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        for (ll i = 0; i < n; i++) {
        	if(a[i]==b[i]){
        		
        		iu = i;
        	}
            pair<ll, ll> bond = {min(a[i], b[i]), max(a[i], b[i])};
            bondFreq[bond]++;
            
        }
        
        ll oddCount = 0;
        for (auto &entry : bondFreq) {
            if (entry.second % 2 != 0) {
                oddCount++;
            }
        }
        
        if (oddCount > 1){ cout << "-1\n";
                           continue;
        }
        else{ //cout << "Possible\n";
       
    if(n%2!=0){
    	if(a[n/2]==b[n/2]){
    		
    	}else{swap(a[n/2],a[iu]);
    		swap(b[n/2],b[iu]);p.push_back({(n/2 + 1),(iu+1)});//cout<<"lol";
    	}
    }
    for (ll i = 0; i < n; i++) {
            pair<ll, ll> bond = {min(a[i], b[i]), max(a[i], b[i])};
            
            if (hashmap1.count(bond) == 0) {
            hashmap1[bond] = {i + 1, -1};
        } else {
            hashmap1[bond].second = i + 1;
        }
        }
    
    
    
    
    for (ll i = 1; i <= n/2; i++) {
        pair<ll, ll> bond = {min(a[i - 1], b[i - 1]),max(a[i - 1], b[i - 1])};
        auto [firstIdx, secondIdx] = hashmap1[bond];
        pair<ll, ll> bond2 = {min(a[n - i], b[n - i]),max(a[n - i], b[n - i])};
        auto [f, k] = hashmap1[bond2];
        
        //cout<<secondIdx<<" "<<n-i+1<<"\n";
        if(bond!=bond2){
        swap(a[secondIdx-1],a[n-i]);
        swap(b[secondIdx-1],b[n-i]);
        if(secondIdx!=(n-i+1)){
        	p.push_back({secondIdx,(n-i+1)});
        }
        
        hashmap1[bond].second = n-i+1;
        vector <ll> c;
        if(f!=(n-i+1)){
        	c.push_back(f);
        }
        if(k!=(n-i+1)){
        	c.push_back(k);
        }
        if(secondIdx!=(n-i+1)){
        	c.push_back(secondIdx);
        }
        
        sort(c.begin(),c.end());
        
        hashmap1[bond2].first = c[0];
        hashmap1[bond2].second = c[1]; 
         // for (ll i = 0; i < n; i++) {
            // cout << a[i] << " ";
        // }cout<<"\n";
        // for (ll i = 0; i < n; i++) {
            // cout << b[i] << " ";
        // }cout<<"\n";
        }else{
        		
        		
        	}
        }
    }
    
    ll up = p.size();
    cout<<up<<"\n";
    
    for (ll i = 0; i < up; i++){
    	cout<<p[i].first<<" "<<p[i].second<<"\n";
    	}
    }
                
    return 0;
}