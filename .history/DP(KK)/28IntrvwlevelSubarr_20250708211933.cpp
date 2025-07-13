
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




// import java.util.Scanner;

// public class Main {
//     public static void main(String[] args) {
//         Scanner scanner = new Scanner(System.in);
//         String s = scanner.next();
//         int n = s.length();

//         boolean[][] dp = new boolean[n][n];
//         int[][] dp1 = new int[n][n];

//         // length 1 string
//         for (int i = 0; i < n; i++) {
//             dp[i][i] = true;
//             dp1[i][i] = 1;
//         }

//         // length 2 string
//         for (int i = 0; i < n - 1; i++) {
//             if (s.charAt(i) == s.charAt(i + 1)) {
//                 dp[i][i + 1] = true;
//             }
//             dp1[i][i + 1] = dp1[i][i] + dp1[i + 1][i + 1] + (dp[i][i + 1] ? 1 : 0);
//         }

//         // lengths 3 to n
//         for (int length = 3; length <= n; length++) {
//             for (int i = 0; i <= n - length; i++) {
//                 int j = i + length - 1;
//                 if (s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1]) {
//                     dp[i][j] = true;
//                 }
//                 dp1[i][j] = dp1[i][j - 1] + dp1[i + 1][j] - dp1[i + 1][j - 1] + (dp[i][j] ? 1 : 0);
//             }
//         }

//         int q = scanner.nextInt();
//         for (int i = 0; i < q; i++) {
//             int l = scanner.nextInt();
//             int r = scanner.nextInt();
//             System.out.println(dp1[l][r]);
//         }

//         scanner.close();
//     }
// }




def main():
    import sys
    input = sys.stdin.read
    data = input().split()

    s = data[0]
    n = len(s)
    dp = [[0] * n for _ in range(n)]
    dp1 = [[0] * n for _ in range(n)]

    # length 1 string
    for i in range(n):
        dp[i][i] = 1
        dp1[i][i] = 1

    # length 2 string
    for i in range(n - 1):
        if s[i] == s[i + 1]:
            dp[i][i + 1] = 1
        dp1[i][i + 1] = dp1[i][i] + dp1[i + 1][i + 1] + dp[i][i + 1]

    # lengths 3 to n
    for length in range(3, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            if s[i] == s[j] and dp[i + 1][j - 1] == 1:
                dp[i][j] = 1
            dp1[i][j] = dp1[i][j - 1] + dp1[i + 1][j] - dp1[i + 1][j - 1] + dp[i][j]

    index = 1
    q = int(data[index])
    index += 1
    results = []
    for _ in range(q):
        l = int(data[index])
        r = int(data[index + 1])
        index
