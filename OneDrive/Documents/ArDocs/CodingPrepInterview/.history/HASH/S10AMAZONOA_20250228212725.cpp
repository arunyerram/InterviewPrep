#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum subarray sum ending at each index from the left
vector<int> calculatePrefixMaxSum(const vector<int>& nums) {
    int n = nums.size();
    vector<int> prefixMaxSum(n+1, 0);
    int currentMax = nums[1];
    prefixMaxSum[1] = nums[1];
    
    for (int i = 2; i <= n; ++i) {
        currentMax = max({0, nums[i], currentMax + nums[i]});
        prefixMaxSum[i] = currentMax;
    }
    
    return prefixMaxSum;
}

// Function to calculate the maximum subarray sum starting at each index from the right
vector<int> calculateSuffixMaxSum(const vector<int>& nums) {
    int n = nums.size();
    vector<int> suffixMaxSum(n+1, 0);
    int currentMax = nums[n];
    suffixMaxSum[n] = nums[n];
    
    for (int i = n - 1; i >= 1; --i) {
        currentMax = max({0, nums[i], currentMax + nums[i]});
        suffixMaxSum[i] = currentMax;
    }
    
    return suffixMaxSum;
}

int maxTwoNonOverlappingSubarraysSum(const vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    // Calculate prefix and suffix max subarray sums
    vector<int> prefixMaxSum = calculatePrefixMaxSum(nums);
    vector<int> suffixMaxSum = calculateSuffixMaxSum(nums);

    vector<int> maxPrefixSum(n+2, 0);
    maxPrefixSum[1] = prefixMaxSum[1];
    for (int i = 2; i <= n; ++i) {
        maxPrefixSum[i] = max(maxPrefixSum[i - 1], prefixMaxSum[i]);
    }

    vector<int> maxSuffixSum(n+2, 0);
    maxSuffixSum[n] = suffixMaxSum[n];
    for (int i = n - 1; i > 0; --i) {
        maxSuffixSum[i] = max(maxSuffixSum[i + 1], suffixMaxSum[i]);
    }

    // Find the maximum sum of two non-overlapping subarrays
    int maxSum = 0;
    for (int i = 0; i <= n ; ++i) {
    	// cout<<maxSum<<"i is "<<i<<endl;
        maxSum = max(maxSum, maxPrefixSum[i] + maxSuffixSum[i + 1]);
    }

    return maxSum;
}

int main() {
	int n;cin>>n;
    vector<int> nums(n+1);
    for(int i=1;i<=n;i++){
    	cin>>nums[i];
    }
    cout << "Maximum sum of two non-overlapping subarrays: " << maxTwoNonOverlappingSubarraysSum(nums) << endl;
    return 0;
}
