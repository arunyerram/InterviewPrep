#include<bits/stdc++.h>
using namespace std;

void subarray_problem(vector<int> &arr,int k)
{
    int maxi = -1e9;
    int sum = 0;
    unordered_map<int,int> mpp;
    mpp[0] = -1;
    for(int i = 0;i<arr.size();i++)
    {
        sum += arr[i];
        if(mpp.find(sum-k) != mpp.end())
        {
            maxi = max(maxi,i-mpp[sum-k]);
        }
        else{
            if(mpp.find(sum) == mpp.end())
                mpp[sum] = i;
        }
    }
    if(maxi != -1e9)
    {
        int i = 0,cnt = 0;
        int j =0;
        int s = 0;
        int k1 = maxi;
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


// S6--------------
int countSubarraysOptimized(vector<int>& arr, int k) {
    unordered_map<int, int> prefixSumCount;
    int sum = 0, count = 0;
    int mn = arr.size();
    prefixSumCount[0] = 1;
    map<int,int>mp;
    mp[0] = -1;
    for (int i=0 ;i<arr.size();i++) {
        sum += arr[i];

        if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
            count += prefixSumCount[sum - k];
            mn = min(mn,i - mp[sum - k]);
        }

        prefixSumCount[sum]++;
        mp[sum] = i;
    }

    return mn;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 5;
    cout << "Number of subarrays with sum " << k << ": " << countSubarraysOptimized(arr, k) << endl;
    return 0;
}

