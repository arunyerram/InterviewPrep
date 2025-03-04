#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            int n = nums.size();
            int i = 0,j = n-1;
            if(n == 1)return nums[0];
            while(i <= j){
                int mid = (i+j)/2;
    
                if((mid-1>=0 && nums[mid] != nums[mid-1])&&(mid+1<n && nums[mid] != nums[mid+1]) || (mid-1<0 && mid+1 < n && nums[mid] != nums[mid+1]) || (mid+1>=n && mid-1>=0 && nums[mid] != nums[mid-1]))return nums[mid];
                else if((mid - 1 >= 0 && nums[mid] == nums[mid-1] && mid%2 == 0) || (mid + 1 < n && nums[mid] == nums[mid+1] && mid%2 != 0) ){
                    j = mid-1;
                }else i = mid+1;
            }return -1;
        }
    };