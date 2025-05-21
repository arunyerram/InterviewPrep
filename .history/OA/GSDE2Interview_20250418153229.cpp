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
    for(int i=0;i<n;i++){
        char c = 'a';
        int mnidx = 0;

        for(int j=i;j<n;j++){

        if(str[i] > c){
            c = str[i];
            mnidx = i;  
        }
    }
}





    return 0;
}