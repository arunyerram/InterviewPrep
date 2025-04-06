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
    vector<int>result;
    for(auto it:vec){
        int sum = 0;
        for(int j = 0; j < it.size(); j++){
            char ch = it[j];
            mp[ch - 'a'][j]--;
        }
        for(int j = 0; j < it.size(); j++){
            char ch = it[j];
            sum += mp[ch - 'a'][j];
        }
        result.push_back(sum);
    }
    for(int i = 0; i < result.size(); i++){ 
        cout << result[i] << " ";
    }



    return 0;
}


// {char,{index,freq}};

// a- {1,freq}
// b- {2,freq}
// c - {1,frequency}
// e - {1,freq}
// d - {1,freq}






