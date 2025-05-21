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
    // string ans = "";
    char c = 'a';
    vector<int>suff(n);
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
    string ans = "";
    // abczbczz
    // ans : zc
    int i = 0;
    while(i<n){
        ans += str[suff[i]];
        i = suff[i]+1;
        break;
    }
    while(i<n){
        int j = i;
        char c = 'a';
        int idx = n;
        while(j<n && str[j] < str[i]){
            if(str[j] > c){
                c = str[j];
                idx = j;
            }
            j++;
        }ans += str[idx];
        i = idx+1;
    }

    cout<<ans<<endl;

    return 0;
}