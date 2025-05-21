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
        vector<vector<int>>v(n,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>v[i][j];
            }
        }
        vector<int>p(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                p[i + j]= v[i][j]; 
        }
    }


    return 0;
}