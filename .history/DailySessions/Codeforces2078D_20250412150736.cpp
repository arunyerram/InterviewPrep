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
            for (int j = 0; j < 4; ++j) {
                cin >> matrix[i][j];
            }
        }
        ll l = 1;
        ll r = 1;

        for(int i = 0; i < n; ++i) {
            string c1 = matrix[i][0].c_str();
            string c2 =  matrix[i][2].c_str();
            int num1 = 0;
            int num2 = 0;

            for (int j = 0; j < 4; ++j) {
                if(j == 1) {
                    num1 = stoi(matrix[i][j]);
                } else if(j == 3) {
                    num2 = stoi(matrix[i][j]);
                }
            }

            int tot = 0;
            if(c1 == '+' && c2 == '+') {
                tot = num1 + num2;
            }else if(c1 == '+' && c2 == '*') {
                tot = num1;
                tot += (r*num2 - r);
            }
            else if(c1 == '*' && c2 == '+') {
                tot = num2;
                tot += (l*num1 - l);
            }
            else if(c1 == '*' && c2 == '*') {
                tot = (l*num1 - l) * (r*num2 - r);
            }


            
            if(c1 == '+' && c2 == '+') {
                if(tot%2 == 0){
                    l += tot/2;
                    r += tot/2;
                }else{
                    r += tot/2 + 1;
                    l += tot/2;
                }
            }
            else if(c1 == '+' && c2 == '*') {
                l += 0;
                r += (tot*num2);
            }
            else if(c1 == '*' && c2 == '+') {
                l += (tot*num1);
                r += 0;
            }
            else if(c1 == '*' && c2 == '*') {
                if(num1 >= num2){
                    l += (tot*num1);
                    r += 0;
                }else{
                    l += 0;
                    r += (tot*num2);
                }
            }
        }
        cout<<(l + r)<<endl;
    }
    return 0;
}