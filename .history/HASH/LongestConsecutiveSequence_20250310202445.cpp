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