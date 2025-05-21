#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n; 
        string st;
        cin>>st;

        char c= st[0];
        int i = 0;
        int cnt = 0;
        for(int j=97;j<=122;j++){
            if(st[i] == char(j)){
                while (i<n && st[i] == char(j)){
                    i++;
                }
            }
            c = st[i];
        }
    }
    return 0;
}