#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string>vec;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        vec.push_back(s);
    }
    map<int,vector<pair<int,int>>>mp;
    vector<int>ans;
    vector<int>help(26,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<vec[i].size();j++){
            help[vec[i][j]-'a']++;
        }
    }



    return 0;
}


// a- {1,i}
// b- {2,idx}
// c - {1}
// e - {1}
// d - {1}






