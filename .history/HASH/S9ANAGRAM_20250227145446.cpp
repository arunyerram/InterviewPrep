#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isAnagram(string s, string t) {
            sort(s.begin(),s.end());
            sort(t.begin(),t.end());
            return s==t;
            map<char,int>mp;
            for(auto it:s){
                mp[it]++;
            }
    
            for(auto it:t){
                mp[it]--;
                if(mp[it] == 0){
                    mp.erase(it);
                }
            }return mp.size() == 0;
        }
    };
    int main(){
        
    }