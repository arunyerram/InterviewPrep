#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_map<int, bool> hmap;
    for (int num : nums) {
        hmap[num] = true;
    }

    int longestSequence = 0;
    unordered_map<int, int> checkMap;

    for (int i = 0; i < nums.size(); i++) {
        if (!hmap[nums[i]]) continue;
        int num = nums[i];
        int flag = 0;

        while (hmap.find(num) != hmap.end()) {
            if (checkMap.find(num) != checkMap.end()) {
                checkMap[nums[i]] = checkMap[num];
                flag = -1;
                break;
            }
            hmap[num] = false;
            num--;
        }

        if (flag == 0) checkMap[nums[i]] = num + 1;
        int sequenceLength = nums[i] + 1 - checkMap[nums[i]];
        longestSequence = max(longestSequence, sequenceLength);
    }
    return longestSequence;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << longestConsecutive(nums) << endl;
    return 0;
}
