#include <bits/stdc++.h>

using namespace std;

int main() {
        int n,target;
        
        vector<int>ans,nums(n);
        
        cin>>n;
        
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        
        cin>>target;
        
        
        
        int l=0,r=n-1,first=-1,last=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>=target){
                if(nums[mid]==target) first=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        ans.push_back(first);
        l=0,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]<=target){
                if(nums[mid]==target) last=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        ans.push_back(last);
        for(auto it:ans) cout<<it<<" ";
        cout<<endl;
}
/*Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4] */
