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
        int cnt = 0,j=97;
        // for(int j=97;j<=122;j++){
            while(i < n){
                cnt = 0;
                if(st[i] == char(j)){
                    while (i<n && st[i] == char(j)){
                        i++;
                        cnt++;
                    }j++;
                }else if(cnt == 0){
                    break;
                }
            }
            if(i < n)
                c = st[i];
            ++i;
            while(i < n){
                if(st[i] < c){
                    swap(st[i],c);
                    break;
                }i++;
            }
            cout<<st<<endl;
        }
    // }
    return 0;
}