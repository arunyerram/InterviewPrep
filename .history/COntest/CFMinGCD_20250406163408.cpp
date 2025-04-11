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
        for(int i=n-1;i>0;i--){
            suf[i]=__gcd(a[i],suf[i+1]);
        }
    }return 0;
}