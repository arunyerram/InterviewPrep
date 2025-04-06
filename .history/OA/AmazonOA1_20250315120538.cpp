#include<bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin>>s>>t;

    int answer = INT_MAX;
    map<char,int>mp1;
    map<char,int>mp2;
    for(auto it:s){
        mp1[it]++;
    }
    for(auto it:t){
        mp2[it]++;
    }

    for(auto it:t){
        answer = min(answer,mp1[it]/mp2[it]);
    }
    // return answer;
    
}