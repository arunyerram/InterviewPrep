
// > https://www.desiqna.in/13008/goldman-sachs-sde-oa-ctc-30-lac-2023-dp 







// > You can visit each index only 1 time. 

// B = [  2 10 8 -5 -10 5  ]

// Way 1 -> 2—-8—- -10—--outside= 0 
// Way2 -> 2—-8—- -10 —- (-5) —- (+ 5) = 0 
// 0 is the best answer to this question ; because this is the minimum sum you can get

// B = [ 2 -100 8 5 0 ] 

// Answer = -85(2—-8— -100—5—jump out of the array)

// Observation:- No consecutive backward moves can be made! 







// How can we solve this using DP ? 

// -> always make an empty DP[] 

// → clear the meaning of DP[i]

// → create the recurrence formula 

// —> calculate dp[i] for all i from 1 to N 

// -> dp[n] in most cases is your final answer.. 




// (DP[i] = it means the minimum cost to reach index ‘i’ or cross index ‘i’)

// Dp[i] = minimum cost to reach index i from index 1 .


// But in our problem ==== 

// Dp[i] means minimum cost to exactly reach point ‘i’..... 


// —--> no continuous back jump allowed + you can jump back at any index for at most 1 time…

// —-> you should not jump back multiple times. You cannot. 

// —> this is because you are allowed to visit any index only 1 time….

// —-> At any index of consideration you cannot jump back for more than 1 time continuously because of this we can use dp because we are going back only 1 time….

// —-> For a particular index only one backward jump is allowed to  its previous index only 




// —---> Whichever thing is creating a problem for you in the question l directly make a state for it

// dp[i][forward] = dp[i][2] = someone is coming from index i-2 to index i tell me the best answer in that case. 

// dp[i][backward] = dp[i][1] = someone is coming from index i+1 to i -> best answer in that case. 

 





// —--> dp[i][backwardjump] = it means the best way to reach index ‘i’ if someone is jumping on it from backward that us from i+1 

// dp[i][backward] = b[i] + (dp[i-1][forward]) + b[i+1]


// —---> dp[i][forwardjump] = it means the best way to reach index ‘i’ if someone is coming from i-2 index jumping forward from there… 

// B[i] + min(dp[i-2][forwardjump],dp[i-2][backwardjump]) 

// C++ :- https://ideone.com/rER6aM 
// Java :- https://ideone.com/miIZAr 
// Py :- https://onecompiler.com/java/42aqpd9db



#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 

int my(int k,int r,int g){
    
    return min(k,max(r,g));
}


int main() {
    int n ; 
    cin>>n ; 
    int b[n+1] = {0};
    
    int i = 1 ;
    while(i<=n){
        cin>>b[i] ; 
        i++;
    }
    
    int dp[n+1][5]; 
    
    dp[1][2] = b[1] ; 
    dp[1][1] = 100000000 ; 
    dp[2][2] = 100000000 ; 
    dp[2][1] = dp[1][2] + b[2] + b[3] ;
    
    
    i = 3 ; 
    while(i<=n-1){
        
        
        dp[i][2] = b[i] + min(dp[i-2][1],dp[i-2][2]);
        dp[i][1] = b[i] + b[i+1] + dp[i-1][2] ; 
        
        i++;
    }
    dp[i][2] = b[n] + min(dp[i-2][2],dp[i-2][1]);
    dp[i][1] = 100000000 ; 
    cout<<my(dp[n][2],dp[n-1][2],dp[n-1][1]);
    
    
    
    return 0 ; 
}


import java.util.*;

public class Main {

    public static int my(int k, int r, int g) {
        return Math.min(k, Math.max(r, g));
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int[] b = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            b[i] = scanner.nextInt();
        }

        int[][] dp = new int[n + 1][5];

        dp[1][2] = b[1];
        dp[1][1] = 100000000;
        dp[2][2] = 100000000;
        dp[2][1] = dp[1][2] + b[2] + b[3];

        int i = 3;
        while (i <= n-1) {
            dp[i][2] = b[i] + Math.min(dp[i - 2][1], dp[i - 2][2]);
            dp[i][1] = b[i] + b[i + 1] + dp[i - 1][2];
            i++;
        }
        dp[i][2] = b[n] + Math.min(dp[i-2][2],dp[i-2][1]);
        dp[i][1] = 100000000 ; 
        System.out.println(my(dp[n][2], dp[n - 1][2], dp[n - 1][1]));
    }
}





