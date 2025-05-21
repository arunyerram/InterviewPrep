
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
// ..........GRAPH...............
int main(){
    int t;
    cin>>t;

    while(t-- > 0){
        int n,c;
        cin >> n >> c;
        vector<int>v(n + 1);
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            v[i + 1] = x;
        }
        ll sum = 0;
        ll s1 = 0;ll cnt = 0;
        for(int i=0;i<n;i++){

            sum += v[i];
        }   


    }
    

    

}