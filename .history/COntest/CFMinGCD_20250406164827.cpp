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
        int mc = 0;
        for(int i=0;i<n;i++){
            if(a[i] == mn){
                mc++;
            }
        }
        vector<int>Help;
        for(int i=0;i<n;i++){
            if(a[i] % mn == 0){
                Help.push_back(a[i]/mn);
            }
        }
        int m = Help.size();
        
        bool f = false;
        
        if(mc > 1){
            f = true;
        }

        if(f){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }return 0;
}