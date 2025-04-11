// #include<bits/stdc++.h>
// using namespace std;
// bool isSquare(long long int n){
//     long long int m = sqrt(n);
//     return (m*m == n);
// }
// int main(){
//     // 2**a * b**2  = n  
//     long long int n;
//     cin>>n;
//     int cnt = 0;
//     set<long long int> s;
//     for(int i=2;i<=(n);i+=2){
//         for(int j=1;j<=60;j++){
//             long long int m = pow(2,j);
//             long long int c;
//             if(m > i)break;
//             if(i%m == 0) c = i/m;
//             else continue;
//             if(isSquare(c)) {
//                 // 2**a * b**2 == i
//                 // cout<<i<< " "<<j<<" "<<sqrt(c)<<endl;
//                     // cnt++;
//                     s.insert(i);
//             }
//         }
//     }cout<<s.size()<<endl;
// }


#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin>>n;
    
    cout << (int)sqrt(n/2) + (int)sqrt(n/4);

    return 0;
}