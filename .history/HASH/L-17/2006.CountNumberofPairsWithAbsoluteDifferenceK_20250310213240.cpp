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




    // import java.util.*;

    // class Solution {
    //     public int countKDifference(int[] nums, int k) {
    //         int n = nums.length;
    //         int cnt = 0;
            
    //         Map<Integer, Integer> mp = new HashMap<>();
            
    //         for (int i = 0; i < n; i++) {
    //             // Check for nums[i] + k
    //             if (mp.containsKey(nums[i] + k)) {
    //                 cnt += mp.get(nums[i] + k);
    //             }
    //             // Check for nums[i] - k (only if k != 0)
    //             if (k != 0 && mp.containsKey(nums[i] - k)) {
    //                 cnt += mp.get(nums[i] - k);
    //             }
                
    //             // Update frequency map
    //             mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
    //         }
            
    //         return cnt;
    //     }
    
    //     public static void main(String[] args) {
    //         Solution sol = new Solution();
    //         int[] nums = {1, 2, 2, 1};
    //         int k = 1;
    //         System.out.println(sol.countKDifference(nums, k)); // Output: 4
    //     }
    // }


    def count_k_difference(nums, k):
    cnt = 0
    mp = {}

    for num in nums:
        # Check for num + k
        if num + k in mp:
            cnt += mp[num + k]
        # Check for num - k (only if k != 0)
        if k != 0 and num - k in mp:
            cnt += mp[num - k]
        
        # Update frequency map
        mp[num] = mp.get(num, 0) + 1

    return cnt

# Example usage
nums = [1, 2, 2, 1]
k = 1
print(count_k_difference(nums, k))  # Output: 4
