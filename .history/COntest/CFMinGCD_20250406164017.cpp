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
        int mn = INT_MAX;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            mn = min(mn,a[i]);
        }
        sort(a,a+n);

        int suf[n];
        suf[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i] =__gcd(a[i],suf[i+1]);
        }
        bool f = false;
        for(int i=0;i<n-1;i++){
            if(a[0] == suf[i + 1]){
                f = true;
                break;
            }
        }

        if(f){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }return 0;
}