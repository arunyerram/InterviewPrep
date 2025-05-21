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
    for(int i=0;i<n;i+=mnidx + 1){
        mnidx = 0;

        for(j=i;j<n;j++){

            if(str[j] >= c){
                c = str[j];
                mnidx = j;  
            }
        }ans += c;
    }
    cout<<ans<<endl;
    return 0;
}