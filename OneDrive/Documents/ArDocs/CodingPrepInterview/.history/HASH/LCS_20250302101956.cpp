#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_map<int, bool> checked;
    unordered_map<int, bool> present;
    int result = 0;

    // Mark all numbers as present
    for (int val : nums) {
        present[val] = true;
    }

    for (int val : nums) {
        if (!checked[val] && present.find(val - 1) == present.end()) {
            int curr_seq = 0;
            int start = val;

            while (present.find(start) != present.end()) {
                checked[start] = true;
                start++;
                curr_seq++;
            }

            result = max(result, curr_seq);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums) << endl;
    cout << longestConsecutive2(nums) << endl;
    return 0;
}




int main() {
    vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    
    return 0;
}
