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
    long long int a = 2;
    int cnt = 0;
    for(int i=1;i<=60;i++){
        if(a <= n){
            int m = n/a;
            
            
        }
        else break;
        a *= 2;
    }
}


// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     long long int n;
//     cin>>n;
    
//     cout << (int)sqrt(n/2) + (int)sqrt(n/4);

//     return 0;
// }