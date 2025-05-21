
#include<bits/stdc++.h> 
using namespace std;


// -2500 -2500 -2000 -1900


//  1500 1600 2500

//  -2500 -1700 -1550 -1550


//  1800 2100 2200

int main(){
    int n;
    cin>>n;
    vector<int>b;
    vector<int>g;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        b.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        g.push_back(x);
    }
    sort(b.begin(),b.end());
    sort(g.begin(),g.end());
    vector<int>gn;
    vector<int>bn;
    vector<int>bp;
    vector<int>gp;

    for(int i=0;i<n;i++){
        if(b[i] < 0){
            bn.push_back(abs(b[i]));
        }else{
            bp.push_back(b[i]);
        }
    }
    sort(bn.begin(),bn.end());

    for(int i=0;i<n;i++){
        if(g[i] < 0){
            gn.push_back(abs(g[i]));
        }else{
            gp.push_back(g[i]);
        }
    }
    sort(gn.begin(),gn.end());
    int cnt = 0;
    int i = 0,j=0;
    while(i < bn.size() && j < gp.size()){
        if(bn[i] > gp[j]){
            cnt++;
            i++;
            j++;
        }else{
            i++;
        }
    }
    i = 0,j=0;
    while(i < bp.size() && j < gn.size()){
        if(bp[i] < gn[j]){
            cnt++;
            i++;
            j++;
        }else{
            j++;
        }
    }   
    cout<<cnt<<endl;
    return 0;
}