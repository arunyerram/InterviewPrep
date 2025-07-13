#include<bits/stdc++.h>
using namespace std;

void Recrse(vector<int>&vec, vector<char>&charvec, vector<string>&help, int i, int &mn){
    if(i == vec.size() - 1){
        int sum = vec[0];
        for(int j = 0; j < help.size(); j++){
            if(help[j] == "+"){
                sum += vec[j + 1];
            }else if(help[j] == "-"){
                sum -= vec[j + 1];
            }else{
                sum *= vec[j + 1];
            }
        }
        mn = min(mn, sum);
        return;
    }

    for(int j = 0; j < charvec.size(); j++){
        
        help.push_back(to_string(charvec[j]));
        Recrse(vec, charvec, help, i + 1, mn);
        help.pop_back();
    }
}
int main(){
    vector<int>vec = {12,23,3,1};
    vector<char>charvec = {'-','*','+'};
    
    int mn = INT_MAX;
    vector<string>help;

    Recrse(vec,charvec, help, 0, mn);
    cout<<mn<<endl;
    return 0;
}