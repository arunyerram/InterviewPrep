#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
            int cnt = 0;
            int n = nums1.size();
            map<int,int>mp1;
            map<int,int>mp2;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mp1[(nums1[i]+nums2[j])]++;
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mp2[(nums3[i]+nums4[j])]++;
                }
            }
    
            for(auto it:mp1){
                int ele = it.first;
                if(mp2.find((-1*ele)) != mp2.end()){
                    cnt += mp1[(ele)]*mp2[(-1*ele)];
                }
            }
            return cnt;
        }
    };