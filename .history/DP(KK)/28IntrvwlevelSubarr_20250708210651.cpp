
// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.


// https://drive.google.com/file/d/1rL0N177U5NssmAnqumR-UYlE9huYskdy/view
// 



#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 
// 1 letter is also called as palindrome
int dp[5000][5000]; 
int dp1[5000][5000];
int main() {
    string s ; 
    cin>>s ; 
    int n = s.size();
    int i,j,k ; 
    
    //length 1 string
    i = 0 ; int g = 0 ; 
    while(i<n){
        dp[i][i] = 1 ; //true-->1 
        dp1[i][i] = 1 ;  
        i++;
    }
    
    //length 2 string 
    i = 0 ; 
    while(i<n-1){
        
        if(s[i]==s[i+1]){
            dp[i][i+1] = 1 ; 
        }
        
        dp1[i][i+1] = dp1[i][i] + dp1[i+1][i+1] + dp[i][i+1];
        
        i++;
    }
    
    //length 3 ; length 4 ; length 5...length n 
    cout<<dp1[0][1];
    cout<<'\n';
    
    ll length = 3 ; 
    while(length<=n){
        i = 0 ; 
        while(i<n-length+1){
            ll j = i + length - 1 ; 
            
            if(s[i]==s[j] && dp[i+1][j-1]==1){
                dp[i][j] = 1 ; 
                //j-i+1..... 
            }
            dp1[i][j] = dp1[i][j-1] + dp1[i+1][j] - dp1[i+1][j-1] + dp[i][j] ; 
            
            i++;
        }
        length++;
    }
    //cout<<dp[1][2];
    //cout<<'\n';
    int q ; 
    cin>>q ; 
    for(int i=0;i<q;i++){
    	int l,r ; 
    	cin>>l>>r ; 
    	
    	cout<<dp1[l][r];
    	cout<<'\n';
    }
    
    //cout<<g ; 
    
    
    return 0 ; 
}
