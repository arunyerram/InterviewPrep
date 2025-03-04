#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestSubarray(vector<int>& nums, int limit) {
            int n = nums.size();
    
            int i = 0;
            int mx = 0;
            int cnt = 0;
            multiset<int>st;
            int d = 0;
            for(int j=0;j<n;j++){
                
                st.insert(nums[j]);
                d = *st.rbegin() - *st.begin();
    
                while(d > limit){
                    st.erase(st.find(nums[i]));
                    i++;
                    if(!st.empty())
                        d = *st.end() - *st.begin();
                }
                mx = max(mx,j-i+1);
            }
            return mx;
        }
    };