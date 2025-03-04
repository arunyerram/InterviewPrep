// #include <iostream>
// #include <vector>
// #include <unordered_map>
#include<bits/stdc++.h>
using namespace std;

int countSubarraysOptimized(vector<int>& arr, int k) {
    unordered_map<int, int> prefixSumCount;
    int sum = 0, count = 0;

    // prefixSumCount[0] = 1;
    int mx = INT_MIN;
    for (int i=0;i<arr.size();i++) {
        sum += arr[i];

        // if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
        //     count += prefixSumCount[sum - k];
        // }

        if(prefixSumCount.find(sum - k) != prefixSumCount.end()) {
            // prefixSumCount[sum] = min(prefixSumCount[sum], i);
            mx = max(mx,i - prefixSumCount[sum-k]+ 1);
        }
        
        if(prefixSumCount.find(sum) == prefixSumCount.end()) {
            prefixSumCount[sum] =  i;
        }
        // prefixSumCount[sum]++;
    }
    return mx;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 5;
    cout << "Max size subarray with sum k is " << ": " << countSubarraysOptimized(arr, k) << endl;
    return 0;
}
