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
                cnt = 0;
                while (i<n && st[i] == char(j)){
                    i++;
                    cnt++;
                }
            }else if(cnt == 0){
                break;
            }
            c = st[i];
        }
    }
    return 0;
}