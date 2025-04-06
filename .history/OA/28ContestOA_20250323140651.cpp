#include<bits/stdc++.h>
using namespace std;

void subarray_problem(vector<int> &arr,int k)
{
    int mini = INT_MAX;
    int sum = 0;
    unordered_map<int,int> mpp;
    mpp[0] = -1;
    for(int i = 0;i<arr.size();i++)
    {
        sum += arr[i];
        if(mpp.find(sum-k) != mpp.end())
        {
            mini = max(mini,i-mpp[sum-k]);
        }
        // else{
            // if(mpp.find(sum) == mpp.end())
                mpp[sum] = i;
        // }
    }
    if(mini != -1e9)
    {
        int i = 0,cnt = 0;
        int j =0;
        int s = 0;
        int k1 = mini;
        while(j<arr.size())
        {
            s += arr[j];
            if(j-i+1<k1)
            {
              j++;
            }
            else if(j-i+1==k1)
            {
                if(s==k)
                {
                    cnt++;
                }
                s -= arr[i];
                i++;
                j++;            
            }
        }
        cout<<cnt;
    }
}

int main() {
	vector<int> arr = { -8, -8, -3, 8 };
    int k = 5;
 
    subarray_problem(arr,k);
    // cout<<result;
	return 0;
}




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



// // S6--------------
// int countSubarraysOptimized(vector<int>& arr, int k) {
//     unordered_map<int, int> prefixSumCount;
//     int sum = 0, count = 0;
//     int mn = arr.size();
//     prefixSumCount[0] = 1;
//     map<int,int>mp;
//     mp[0] = -1;
//     for (int i=0 ;i<arr.size();i++) {
//         sum += arr[i];

//         if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
//             count += prefixSumCount[sum - k];
//             mn = min(mn,i - mp[sum - k]);
//         }

//         prefixSumCount[sum]++;
//         mp[sum] = i;
//     }

//     return mn;
// }

// int main() {
//     vector<int> arr = {1, 2, 3, 4, 5};
//     int k = 5;
//     cout << "Number of subarrays with sum " << k << ": " << countSubarraysOptimized(arr, k) << endl;
//     return 0;
// }

