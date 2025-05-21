#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.emplace_back(a);
    }
    map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[v[i]] = i;
    }
    int mx = 0;
    int mn = n;
    bool f = false;
    for(auto i=0;i<n;i++){
        mx = max(mx,mp[v[i]]);
        if(mx == i){
            int j = i + 1;
            while(j<n-1 && v[j] <= v[j+1]){
                j++;
            }
            if(j == n-1){
                set<int>st;
                int k = 0;
                while (k <= i){
                    st.insert(k);
                    k++;
                }
                mn = min(mn, (int)st.size());
                f = true;
            }
        }
        if(f)break;
    }
    cout<<mn<<endl;
    return 0;
}