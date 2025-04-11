#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        int ans = 0;
        int mn = a[n-1];
        for(int i=0;i<n-1;i++)
        {
            mn = min(mn,a[i]);
        }
        for(int i=0;i<n-1;i++)
        {
            ans = __gcd(ans,a[i+1]-a[i]);
        }
        if(ans == mn)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;
    }
}