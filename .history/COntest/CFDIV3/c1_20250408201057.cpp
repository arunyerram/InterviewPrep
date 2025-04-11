#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // int a[n];
        if(n%2 == 0)
            cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            int a[n];
            for(int i = 0; i < n; i++){
                if(i%2 == 0){
                    a[i] = i + 1;
                }else{
                    a[i] = -(i + 1);
                }
            }
            for(int i = 0; i < n; i++){
                cout << a[i] << " ";
            }cout << endl;
        }
    }return 0;
}