#include<bits/stdc++.h>
using namespace std;
typedef long long int ll; 
// https://www.codechef.com/problems/CNTR
ll mod =  998244353;


int main (){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int>vec;

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            vec.push_back(x);
        }   
        ll tot = 0;
        ll dp[n + 1] = {0};
        for(ll i=1;i<n;i++){
            ll num = dp[i];
            ll sum= 0;
            dp[num] = dp[num] + 1;  
            for(ll j=1;j<num;j++){
                sum += dp[j];
            }
            // weéneed sum from 1 num - 1;

            //  seg Tree

            
            dp[num] += sum;



        }



    return 0;
}