// -> Given an array of size “N”; find -> find the number of unordered quadruplets (i,j,k,l) such that b[i] + b[j] + b[k] + b[l] = 0 

// -> [1 2 3 4 -1 -2 -2] 

// -> 3 [1,2,5,6]  [1,2,5,7] [1,3,6,7] 



#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    int cnt = 0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
                for(int l=k+1;l<n;l++)
                    if(a[i]+a[j]+a[k]+a[l]==0) cnt++;    //....... O(n^4) TC,  O(1) SC......

    

    int tot = 0;
    map<int,int>mp;
    for(int i=1;i<=n;i++) mp[a[i]]++;
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++) 
    for(int k=j+1;k<=n;k++)
    {
        int sum = 0 - a[i] - a[j] - a[k];
        if(mp.find(sum) != mp.end()){
            tot 
        }
    
    cout<<cnt<<endl;
    return 0;
}