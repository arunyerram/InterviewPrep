#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    int k;
    cin >> k;
    int cnt = 0;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        if(mp.find(arr[i] + k) != mp.end()){
            cnt++;
        }

        if(k != 0 && mp.find(arr[i] - k) != mp.end()){
            cnt++;
        }
        mp[arr[i]]++;
    }return 0;
}