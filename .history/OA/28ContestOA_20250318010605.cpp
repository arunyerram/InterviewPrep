#include<bits/stdc++.h>
using namespace std;

void subarray_problem(vector<int> &arr,int k)
{
    int mini = 1e9;
    int sum = 0;
    unordered_map<int,int> mpp;
    mpp[0] = -1;
    for(int i = 0;i<arr.size();i++)
    {
        sum += arr[i];
        if(mpp.find(sum-k) != mpp.end())
        {
            mini = min(mini,i-mpp[sum-k]);
        }
        mpp[sum] = i;
    }
    if(mini != 1e9)
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