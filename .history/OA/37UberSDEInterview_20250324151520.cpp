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
    map<int,map<int,int>>mp;
    // int - 26
    // int index
    // int frequesnvy

    for(int i = 0; i < n; i++){
        string s = vec[i];
        for(int j = 0; j < s.size(); j++){
            mp[s[j] - 'a'][j]++;
        }
    }

    for(auto it:vec){
        int sum = 0;
        for(int j = 0; j < it.size(); j++){
            char ch = it[j];
            mp[ch - 'a'][j]--;
        }
        
    }


    // for(auto it:mp){
    //     int letter = it.first;
    //     // cout<<char(letter +'a' )<<" ";
    //     map<int,int>freq = it.second;
    //     for(auto it1:freq){
    //     cout<<char(letter +'a' )<<" ";
    //         cout<<it1.first<<" "<<it1.second<<endl;
    //     }
    // }









    return 0;
}


// a- {1,i}
// b- {2,idx}
// c - {1}
// e - {1}
// d - {1}






