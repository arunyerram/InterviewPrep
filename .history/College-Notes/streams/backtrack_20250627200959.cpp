

#include<bits/stdc++.h> 
using namespace std;


vector<char>help = {'a','b','c'};

void Recrse(string st,string &s,vector<string>&vec){
    if(s.size() >= st.size()){
        vec.push_back(s);
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
    // for(auto it:vec)cout<<it<<" ";
    // cout<<endl;
    sort(vec.begin(),vec.end());
    if(vec.size() < m)cout<<""<<endl;
    else cout<<vec[m-1]<<endl;
    return 0;
}