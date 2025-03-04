#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<pair<double, int>> threat(n);
        
        // Calculate threat level for each enemy: (time_to_kill / damage[i])
        for (int i = 0; i < n; i++) {
            double time_to_kill = ceil((double)health[i] / power);
            threat[i] = {time_to_kill / damage[i], i};
        }
        
        sort(threat.begin(), threat.end());
        
        ll totalDamage = 0;
        ll cumulativeDamage = accumulate(damage.begin(), damage.end(), 0LL);
        
        for (int i = 0; i < n; i++) {
            int idx = threat[i].second;
            int time_to_kill = ceil((double)health[idx] / power);
            
            // Add the damage dealt by all enemies during the time it takes to kill the current one
            totalDamage += cumulativeDamage * time_to_kill;
            
            // After this enemy is killed, subtract its damage from the cumulative damage
            cumulativeDamage -= damage[idx];
        }
        
        return totalDamage;
    }
};