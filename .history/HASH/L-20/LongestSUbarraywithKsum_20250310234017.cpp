int longestSubarray(vector<int>& arr, int k) {
    // code here
    int n= arr.size();
    int mx = 0;
    map<int,int>mp;
    int pre = 0;
    mp[0] = 0;
    for(int i=0;i<n;i++){
        pre += arr[i];
        
        if(pre == k)mx = i+1;
        
        else if(mp.find(pre-k) != mp.end()){
            mx = max(mx,i - mp[pre-k]);
        }
        
        if(mp.find(pre) == mp.end()){
            mp[pre] = i;
        }
    }
    return mx;
}