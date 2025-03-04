#include<bits/stdc++.h>
using namespace std;

int Recrse(int n){
    if(n == 0)return 0;

    return n + Recrse(n-1);
}
int main()
{
    int n;
    cin>>n;
    // cout<<n<<endl;

    cout<<Recrse(n)<<endl;
    return 0;
}