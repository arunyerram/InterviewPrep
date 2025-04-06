#include <bits/stdc++.h>
using namespace std;

int countShortestSubarrays(vector<int>& arr, int k) {
    unordered_map<int, int> prefixSumIndex;  // Stores the first occurrence of a prefix sum
    int sum = 0, count = 0;
    int minLength = arr.size() + 1;  // Initialize with a large value
    prefixSumIndex[0] = -1;  // To handle subarrays starting from index 0

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if (prefixSumIndex.find(sum - k) != prefixSumIndex.end()) {
            int subarrayLength = i - prefixSumIndex[sum - k];

            if (subarrayLength < minLength) {
                minLength = subarrayLength;  // Update minimum length
                count = 1;  // Reset count for new shortest length
            } else if (subarrayLength == minLength) {
                count++;  // Count another subarray with the shortest length
            }
        }

        // Only store the first occurrence of each prefix sum to ensure shortest length
        if (prefixSumIndex.find(sum) == prefixSumIndex.end()) {
            prefixSumIndex[sum] = i;
        }
    }

    return count;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 5;
    cout << "Count of shortest subarrays with sum " << k << ": " << countShortestSubarrays(arr, k) << endl;
    return 0;
}
