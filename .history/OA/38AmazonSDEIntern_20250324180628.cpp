#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>vec;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        vec.push_back(a);
    }

    vector<int>help(n+1,0);

    for(int j=1;j<=n;j++){
        for(int i=1;i<j;i++){
            if(vec[i] < vec[j]){
                help[j] = help[i] + 1;
            }
        }
    }
    bool f = true;
    for(auto it:help){
        if(it >= 3){
            cout<< true;
            f = false;
            break;
        }
    }
    for(auto it:help){
        cout<<it<<" ";
    }cout<<endl;
    if(f)cout<<false<<endl;
    // return false;
    // return 0;
}