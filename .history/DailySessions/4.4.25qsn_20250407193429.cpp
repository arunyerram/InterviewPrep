#include<bits/stdc++.h>
using namespace std;
typedef long long int ll; 
// https://www.codechef.com/problems/CNTR
ll mod =  998244353;
ll seg[1000000];
ll dp[100005];
void build(ll node,ll start,ll end){
    if(start == end){
        seg[node] = dp[start];
    }
    else{
        ll mid = start + (end - start)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        seg[node] = seg[2*node] + seg[2*node+1];
    }
}

ll query(ll node,ll start,ll end,ll l,ll r){
    if(start > r || end < l){
        return 0;
    }
    if(start >= l && end <= r){
        return seg[node];
    }
    ll mid = start + (end - start)/2;
    ll p1 = query(2*node,start,mid,l,r);
    ll p2 = query(2*node+1,mid+1,end,l,r);
    return (p1 + p2)%mod;
}

void update(ll node,ll start,ll end,ll ind,ll val){
    if(start  == end){
        seg[node] += val;
    }
}
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
        // ll dp[100005];
        for(ll i=1;i<n;i++){
            ll num = vec[i];
            ll sum= 0;
            dp[num] = dp[num] + 1;  
            // for(ll j=1;j<num;j++){
            //     sum += dp[j];
            // }
            // we need sum from 1 num - 1;
            //  .....................seg Tree///////////////////////////////
            dp[num] += sum;
        }
        for(int i=1;i<=100000;i++){
            tot = ( tot + dp[i] )%mod;
        }
        cout<<tot<<endl;
    }
    return 0;
}