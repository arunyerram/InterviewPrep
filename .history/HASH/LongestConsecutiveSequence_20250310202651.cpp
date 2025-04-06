#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();

    unordered_map<int,bool>check;
    unordered_map<int,bool>present;

    for(auto it:nums){
        present[it] = true;
    }
    int mx = 0;
    for(auto it:nums){
        if(present.find(it - 1) == present.end() && !check[it]){
            int cnt = 0;
            int start = it;

            while(present.find(start) != present.end()){
                cnt++;
                check[start] = true;
                start++;
            }mx = max(mx,cnt);
        }
    }return mx;
}

int main(){
    vector<int>nums = {100,4,200,1,3,2};
    cout<<longestConsecutive(nums)<<endl;
    return 0;
}








// import java.util.*;

// public class LongestConsecutiveSequence {
//     public static int longestConsecutive(int[] nums) {
//         int n = nums.length;
//         Map<Integer, Boolean> present = new HashMap<>();
//         Map<Integer, Boolean> check = new HashMap<>();

//         for (int num : nums) {
//             present.put(num, true);
//         }

//         int mx = 0;
//         for (int num : nums) {
//             if (!present.containsKey(num - 1) && !check.getOrDefault(num, false)) {
//                 int cnt = 0;
//                 int start = num;

//                 while (present.containsKey(start)) {
//                     cnt++;
//                     check.put(start, true);
//                     start++;
//                 }
//                 mx = Math.max(mx, cnt);
//             }
//         }
//         return mx;
//     }

//     public static void main(String[] args) {
//         int[] nums = {100, 4, 200, 1, 3, 2};
//         System.out.println(longestConsecutive(nums));
//     }
// }




// def longest_consecutive(nums):
//     present = {num: True for num in nums}
//     check = {}

//     mx = 0
//     for num in nums:
//         if num - 1 not in present and not check.get(num, False):
//             cnt = 0
//             start = num

//             while start in present:
//                 cnt += 1
//                 check[start] = True
//                 start += 1

//             mx = max(mx, cnt)
//     return mx

// # Example usage
// nums = [100, 4, 200, 1, 3, 2]
// print(longest_consecutive(nums))
