

#include<bits/stdc++.h> 
using namespace std;


vector<char>help = {'a','b','c'};
// -2500 -2500 -2000 -1900


//  1500 1600 2500

//  -2500 -1700 -1550 -1550


//  1800 2100 2200

void Recrse(string st,string &s,vector<string>&vec){
    if(s.size() >= st.size()){
        vec.push_back(st);
        return;
    }
    
    for(auto it:help){
        if(s.size() == 0 || s.back() != it)s.push_back(it);
        else continue;
        Recrse(st,s,vec);
        s.pop_back();
    }
    
}

int main(){
    int n, m;
    cin>>n>>m;
    string st;
    cin>>st;
    vector<string>vec;
    string s = "";
    Recrse(st,s,vec);
    for(au)
    sort(vec.begin(),vec.end());
    // if(vec.size() < m)cout<<""<<endl;
    // else cout<<vec[m-1]<<endl;
    return 0;
}