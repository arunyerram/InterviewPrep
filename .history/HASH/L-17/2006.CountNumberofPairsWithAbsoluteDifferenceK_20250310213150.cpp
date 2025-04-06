#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countKDifference(vector<int>& nums, int k) {
            int n = nums.size();
            int cnt = 0;
    
            // nums[i] = nums[j]+K;
            // nums[i]= nums[j] - k;
    
            map<int,int>mp;
            for(int i=0;i<n;i++){
    
                if(mp.find(nums[i] + k) != mp.end()){
                    cnt += mp[nums[i] + k];
                }
                if(k!= 0 && mp.find(nums[i] - k) != mp.end()){
                    cnt += mp[nums[i] - k];
                }
    
                mp[nums[i]]++;
            }
            return cnt;
        }
    };