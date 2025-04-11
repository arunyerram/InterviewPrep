#include<bits/stdc++.h>
using namespace std;
bool isSquare(long long int n){
    long long int m = sqrt(n);
    return (m*m == n);
}

long long b_sqrt(long long int n){
    long long low = 1;
    long long HigH = sqrt(n);
    long long ans = 0;

    while (low <= HigH)
    {
        long long mid = (low + HigH)/2;
        if(mid*mid <= n){
            ans = mid;
            low = mid+1;
        }else{
            
        }
    }
    
}
int main(){
    // 2**a * b**2  = n  
    long long int n;
    cin>>n;
    long long int a = 2;
    int cnt = 0;
    // for(int i=1;i<=60;i++){
        while(a <= n){
            int m = n/a;
            int c = b_sqrt(m);
            if(c%2 != 0) c = c/2 + 1;
            else c = c/2;

            cnt += c;
            a *= 2;
        }
        // else break;
        // a *= 2;
        cout<<cnt;
        return 0;
    }
// }


// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     long long int n;
//     cin>>n;
    
//     cout << (int)sqrt(n/2) + (int)sqrt(n/4);

//     return 0;
// }