
#include<bits/stdc++.h>
using namespace std;
bool isSquare(long long int n){
    long long int m = sqrt(n);
    if(m*m == n) return true;
    return false;
}
int main(){
    // 2**a * b**2  = n  
    long long int n;
    cin>>n;
    int cnt = 0;
    for(int i=1;i<=60;i++){
        long long int m = pow(2,i);

        long long int c;
        if(n%m == 0) c = n/m;
        else continue;
        
        if(isSquare(c))
            cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}