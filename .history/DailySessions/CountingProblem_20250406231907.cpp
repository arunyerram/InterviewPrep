#include<bits/stdc++.h>
using namespace std;
bool isSquare(long long int n){
    long long int m = sqrt(n);
    return (m*m == n);
}
int main(){
    // 2**a * b**2  = n  
    long long int n;
    cin>>n;
    int cnt = 0;
    for(int i=2;i<=(n);i){
        for(int j=1;j<=60;j++){
    
            long long int m = pow(2,j);
            long long int c;
            if(m >= sqrt(i))break;

            if(i!=m && i%m == 0) c = i/m;
            else continue;

            if(isSquare(c)) cnt++;
        }
    }cout<<cnt<<endl;
}