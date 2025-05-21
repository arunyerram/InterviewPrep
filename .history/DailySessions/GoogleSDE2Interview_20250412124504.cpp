#include<bits/stdc++.h>
using namespace std;

// 4 2
// 1101, 1100, 1011, 1001, 0110, 0101, 0011, 0001, 1110, 1111, 1100, 1010, 1000, 0111, 0100, 0010


int main(){

    int n;
    int k;
    cin>>n>>k;

    // vector<int>q;
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin>>x;
    //     q.push_back(x);
    // }
    // int cnt = 0;
    int dp1[n + 1];
    int dp2[n + 1];
    int dp3[n + 1];

    dp1[0] = 0;
    dp2[0] = 0;
    dp3[0] = 0;

    for(int i=1;i<=n;i++){
        if(i == 1){
            dp1[i] = 1;
            dp2[i] = 0;
            dp3[i] = 0;
        }
        else{
            dp1[i] = (dp1[i-1] + dp2[i-1] + dp3[i-1]) * (k - 1);
            dp2[i] = (dp1[i-2]  + dp2[i-2] + dp3[i-2]) * (k - 1);
            if(i >= 3)
                dp3[i] = (dp1[i-3] + dp2[i-3] + dp3[i-3]) * (k - 1);
            else 
                dp3[i] = 0;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dp1[i]<<" "<<dp2[i]<<" "<<dp3[i]<<endl;
    }
    // cout<<dp1[n]<<endl;
    // cout<<dp2[n]<<endl;
    // cout<<dp3[n]<<endl;
    cout<<dp1[n] + dp2[n] + dp3[n]<<endl;
    return 0;
}