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
    int k;
    cin >> k;
    bool f = false;
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        if(mp.find(arr[i]) == mp.end()){
            mp[arr[i]] = i;
        }else{
            if((i - mp[arr[i]]) <= k){
                cout<<"true"<<endl;
                f = true;
                break;
            } mp[arr[i]]++;
        }if(f)break;
    }
}


// for(Map.Entry<Integer,Integer>m:mp.entrySet()){
//     System.out.println(m.getKey()+" "+m.getValue());
// }