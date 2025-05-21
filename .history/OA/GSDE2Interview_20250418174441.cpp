// #include<bits/stdc.
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main(){
    string str;
    cin>>str;

    // lexigrapHically largest  

    // sort(str.begin(),str.end());
    // reverse(str.begin(),str.end());
    int n = str.size();
    int j = 0;
    int mnidx = 0;
    string ans = "";
    char c = 'a';
    vector<int>suff(n + 1);
    for(int i=n-1;i>=0;i--){
        if(str[i] > c){
            c = str[i];
            suff[i] = i;
        }else if(str[i] == c){
            suff[i] = i;
        }else{
            suff[i] = suff[i+1];
        }
    }
    int i = 0;
    while(i < n){
        
    // for(int i=0;i<n;i+=mnidx + 1){
    //     mnidx = n;

    //     for(j=i;j<n;j++){

    //         if(str[j] >= c){
    //             c = str[j];
    //             mnidx = min(mnidx,j);  
    //         }
    //     // suffix
    //     }
    //     ans += c;
    // }
    cout<<ans<<endl;
    return 0;
}