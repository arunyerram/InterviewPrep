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
        int g1 = a[1];
        int g2 = a[0];
        int mn = a[n-1];
        // for(int i=0;i<n-1;i++)
        // {
        //     mn = min(mn,a[i]);
        // }
        for(int i=1;i<n-1;i++)
        {
            g1 = __gcd(g1,a[i+1]);
        }
        for(int i=0;i<n-1;i++)
        {
            g2 = __gcd(g2,a[i+1);
        }
        if(g1 == a[0] || g2 == a[1])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }return 0;
}