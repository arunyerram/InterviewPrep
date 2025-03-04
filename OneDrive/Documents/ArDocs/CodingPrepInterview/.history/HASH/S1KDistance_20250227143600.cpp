#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool containsNearbyDuplicateOptimized(const std::vector<int>& nums, int k) {
	
    unordered_map<int, int> numIndices;
    
    for (int i = 0; i < nums.size(); ++i) {
        if (numIndices.find(nums[i]) != numIndices.end() && i - numIndices[nums[i]] <= k) {
            return true;
        }
        
        numIndices[nums[i]] = i;
        
    }
    return false;
}

int main() {
    vector<int> nums = {1, 2, 2, 1, 2, 3};
    int k = 2;
    if (containsNearbyDuplicateOptimized(nums, k)) {
        cout << "There are two equal numbers within distance " << k << std::endl;
    } else {
        cout << "No two equal numbers found within distance " << k << std::endl;
    }
    return 0;
}






// JAVA -----------

