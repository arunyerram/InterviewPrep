
#include<bits/stdc++.h>
using namespace std;

int main(){

    // 2**a * b**2  = n  

    // 2**a * b**2 = n
    long long int n;
    cin>>n;
    int cnt = 0;
    for(int i=1;i<=60;i++){
        long long int m = i*i;

        long long int c = n/m;

        if(isSquare(c)){

        }

    }
    cout<n<<endl;

    return 0;
}