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

        int suf[n];
        suf[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=__gcd(a[i],suf[i+1]);
        }
    }return 0;
}