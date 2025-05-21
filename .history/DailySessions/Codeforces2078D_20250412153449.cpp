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

        vector<vector<string>> matrix(n, vector<string>(4));

        for (int i = 0; i < n; ++i) {
            // string token;
            for (int j = 0; j < 4; ++j) {
                cin >> matrix[i][j];
            }
        }
        ll l = 1;
        ll r = 1;

        for(int i = 0; i < n; ++i) {
            string c1 = matrix[i][0];
            string c2 =  matrix[i][2];
            int num1 = stoi(matrix[i][1]);
            int num2 = stoi(matrix[i][3]);
            cout<<num1<<" "<<num2<<endl;

            int tot = 0;
            if(c1 == "+" && c2 == "+") {
                tot = num1 + num2;
            }else if(c1 == "+" && c2 == "*") {
                tot = num1;
                tot += (r*num2 - r);
            }
            else if(c1 == "*" && c2 == "+") {
                tot = num2;
                tot += (l*num1 - l);
            }
            else if(c1 == "*" && c2 == "*") {
                tot = (l*num1 - l)  + (r*num2 - r);
            }
            cout<<"tot: "<<tot<<endl;

            
            if(c1 == "+" && c2 == "+") {
                if(tot%2 == 0){
                    l += tot/2;
                    r += tot/2;
                }else{
                    r += tot/2 + 1;
                    l += tot/2;
                }
                cout<<"l: "<<l<<" r: "<<r<<endl;
            }
            else if(c1 == "+" && c2 == "*") {
                if((l + tot) >= (r + tot)){
                    l += (tot);
                    r += 0;
                }else{
                    l += 0;
                    r += (tot);
                }
                cout<<"l: "<<l<<" r: "<<r<<endl;
            }
            else if(c1 == "*" && c2 == "+") {
                if((l + tot) >= (r + tot)){
                    l += 0;
                    r += (tot);
                }else{
                    l += (tot);
                    r += 0;
                }
                cout<<"l: "<<l<<" r: "<<r<<endl;
            }
            else if(c1 == "*" && c2 == "*") {
                if(num1 >= num2){
                    if(l  + tot >= r + tot){
                        l += (tot);
                        r += 0;
                    }else{
                        l += 0;
                        r += (tot);
                    }
                    l += (tot);
                    r += 0;
                }else{
                    l += 0;
                    r += (tot);
                }
                cout<<"l: "<<l<<" r: "<<r<<endl;
            }
        }
        cout<<(l + r)<<endl;
    }
    return 0;
}