#include<bits/stdc++.h>
using namespace std;

void Recrse(string a,string b){
    map<int,vector<char>>mp1;
    for(int i=0;i<a.size();i++){
        if(i&1 == 0)
            mp1[0].push_back(a[i]);
        else{
            mp1[1].push_back(a[i]);
        }
    }
    map<char,int>help1;
    map<char,int>help2;

    for(auto i=0;i<b.size();i++){
        if(i&1 == 0){
            if(find(mp1[0].begin(),mp1[0].end(),b[i]) == mp1[0].end()){
                cout<<"NO";
                return ;
            }else{
                mp1[0].erase(find(mp1[0].begin(),mp1[0].end(),b[i]));
            }
        }else {
                if(find(mp1[1].begin(),mp1[1].end(),b[i]) == mp1[1].end()){
                    cout<<"NO";
                    return ;
                }else{
                    mp1[1].erase(find(mp1[1].begin(),mp1[1].end(),b[i]));
                }
            }
        }
    cout<<"YES";
    return ;
}

int main(){
    string a,b;
    cin>>a>>b;

    vector<string>v1,v2;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v1.push_back(s);
    }

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v2.push_back(s);
    }

    for(int i=0;i<n;i++){
        Recrse(v1[i],v2[i]);
        cout<<endl;
    }
    return 0;
}