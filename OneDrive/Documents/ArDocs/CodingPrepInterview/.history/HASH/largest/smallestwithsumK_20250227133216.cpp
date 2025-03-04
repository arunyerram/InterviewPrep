#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countSubarraysOptimized(vector<int>& arr, int k) {
    unordered_map<int, int> prefixSumCount;
    int sum = 0, count = 0;

    prefixSumCount[0] = 1;

    for (int num : arr) {
        sum += num;

        if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
            count += prefixSumCount[sum - k];
        }

        if()
        prefixSumCount[sum]++;
    }

    return count;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 5;
    cout << "Number of subarrays with sum " << k << ": " << countSubarraysOptimized(arr, k) << endl;
    return 0;
}
