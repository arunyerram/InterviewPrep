#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin >> n;
        cin.ignore(); // To consume the newline after the integer input

        vector<vector<string>> matrix(n, vector<string>(n));

        for (int i = 0; i < n; ++i) {
            string token;
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
            }
        }
        



    }
    
    
    return 0;
}