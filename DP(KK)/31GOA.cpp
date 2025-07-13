




// Subarray DP -> 

// dp[i][j] = tells you the best answer for the array in range [i…..j] 

// First we calculate the answers for all subarray of length 1 

// -> dp[1][1] dp[2][2] dp[3][3] dp[4][4] dp[5][5] …………………dp[n][n] 

// Calculate for length 2. 

// ->dp[1][2] dp[2][3]                    ……………………………dp[n-1][n] 


// Calculate for length 3.

// .
// .
// .
// .
// .
// .
// .
// -> for length N.
// dp[1][N] = best answer for the whole array 



// For each subarray please tell me if it is a palindrome or not - 

// ->dp[i][j] = true means [i…………….j] is a palin-drome. 


// First we calculate the answers for all subarray of length 1 

// -> dp[1][1] dp[2][2] dp[3][3] dp[4][4] dp[5][5] …………………dp[n][n] 
// dp[i][i] =true.

// Calculate for length 2. 

// ->dp[1][2] dp[2][3]                    ……………………………dp[n-1][n] 
// if(s[i]==s[i+1]){
// dp[i][i+1] = true;
// }
// else
// {
// dp[i][i+1] =false;
// }

// Calculate for length 3.

// .
// .
// .
// .
// .
// .
// .
// -> for length N.
// dp[1][N] = best answer for the whole array 


// if(s[i]==s[j]){

// if(dp[i+1][j-1]==true){
// dp[i][j]=true;
// }
// }

// Follow up :- For any range [l,r] please tell how many palindromes are in that range. 

// Query - [L,R] = how many palindromes in it 

// C++ https://ideone.com/LDeLdW.
// Java. https://onlinegdb.com/aZyy3876y
// Py  https://onlinegdb.com/RwdRfr8vL



// —-------------------------------------------------------

// Given a string please tell how many substring pairs are in the palindrome. 


// [l1……..r1] and [l2…….r2] are valid pairs if l1<=r1 < l2<=r2 and [l1….r1] = palindrome. [l2…….r2] = palindrome. 

// -> bbaa :- 10 valid pairs. 

// Fix the first string 


// First string can end at index 1 -> if this is the case how many total pairs are? 

// First string can end at index 2 -> if this is the case how many total pairs are? 

// First string can end at index 3 -> if this is the case how many total pairs are? 

// First string can end at index 4 -> if this is the case how many total pairs are? 

// First string can end at index 5 -> if this is the case how many total pairs are? 

// .
// .
// .
// .
// .
// .
// .
// .
// .
// .
// .
// .
// .
// First string can end at index n-1 -> if this is the case how many total pairs are? 
// stick=1
// while(stick<=n-1){
// b = 0
// for(ip=i;ip>=1;ip–){
// if(dp[ip][i]==1){
// b++
// }
// }
// y = dp1[i+1][n]
// count = count + x*y 
// }

// print(count) 


// —----------------------------------------------------------------

// Given a string please tell how many substring tuple([l1..r1],[l2…r2],[l3…r3]) are in the palindrome. 


// Fix the first string 


// First string can end at index 1 -> if this is the case how many total triplets are? 

// First string can end at index 2 -> if this is the case how many total triplet are? 

// First string can end at index 3 -> if this is the case how many total triplet are? 

// First string can end at index 4 -> if this is the case how many total triplet are? 

// First string can end at index 5 -> if this is the case how many total triplet are? 

// .
// .
// .
// .
// .
// .
// .
// .
// .
// .
// .
// .
// .
// First string can end at index n-1 -> if this is the case how many total triplet are? 


// B = number of first string palindrome ending at index “i” 

// Y = number of pairs of palindrome in range [i+1][N]


// Dp3[r] = number of pairs of palindrome in range [r….N]




// C++ https://ideone.com/B8x77m
// Java - https://ide.geeksforgeeks.org/online-java-compiler/716bb28c-f5b3-453b-96cf-7bdc2d98dcf2
// Py - https://ide.geeksforgeeks.org/online-python3-compiler/2799d9fa-d609-4b5e-9e76-769251c79fc7



// https://drive.google.com/file/d/1IoXIYm_CKvBnq8YaFoWCjE45vA2DS11d/view




#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin>>s;
    int n = s.size();

    vector<vector<int>> dp(n, vector<int> (n, 0));
    vector<vector<int>> dpc(n, vector<int> (n, 0));

    //lenght 1
    for(int i=0;i<n;i++){
        dp[i][i]=1;
        dpc[i][i]=1;
    }

    //lenght 2
    for(int i=0;i<n-1;i++){
        if(s[i]==s[i+1]){
            dp[i][i+1]=1;
            dpc[i][i+1]=3;
        }else{
            dpc[i][i+1]=2;
        }
    }

    //lenght 3
    for(int len=3;len<=n;len++){
        for(int i=0;i<n-len+1;i++){
            int j = i+len-1;
            if(s[i]==s[j] && dp[i+1][j-1]==1){
                dp[i][j] = 1;
            }
            dpc[i][j] = dpc[i+1][j] + dpc[i][j-1] - dpc[i+1][j-1] + dp[i][j];
        }
    }

    //making palindromic pairs
   
    vector<int> pdpp(n, 0);
    for(int i=0;i<n;i++){
        int j = i;
        int b = 0;
        while(j>=0){
            if(dp[j][i]==1){
                b++;
            }
            j--;
        }
        if(i+1<n){
            int rest = dpc[i+1][n-1];
            // cout<<dpc[i+1][n-1]<<endl;
            int val = b*rest;
            pdpp[i] = val;
        }
        
    }

    // int pairSum = 0;

    // for(int i=0;i<pdpp.size();i++){
    //     pairSum += pdpp[i];
    //     cout<<pdpp[i]<<" ";
    // }cout<<endl;
    // cout<<pairSum<<endl;

    //pdpp(palindromic dp pairs)

    //making palindromic dp triplets
    vector<int> pdpt(n, 0); //pdpt --> palindromic dp triplets
    for(int i=0;i<n;i++){
        int j = i;
        int b = 0;
        while(j>=0){
            if(dp[j][i]==1){
                b++;
            }
            j--;
        }
        if(i+1<n){
            int rest = 0;
            for(int k=i+1;k<n;k++){
                rest += pdpp[k];
            }
            int val = b*rest;
            pdpt[i] = val;
        }
        
    }

    int total = 0;
    for(int i=0;i<n;i++){
        // cout<<pdpt[i]<<" ";
        total += pdpt[i];
    }
    cout<<total<<endl;

   
}