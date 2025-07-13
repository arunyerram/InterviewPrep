
#include <iostream>
#include <algorithm>
using namespace std;





Problem :- You are given an array of size “N” ; you have to start your journey at index “1” and you need to end your journey at index “N”. 

You can make jumps of size - 1 or 3 or 5 

In the array positive as well as negative numbers can be available. 

Please find the maximum sum of journey 

[5 8 3 100 -5 -5 5 10] 

O/P - 131 

-> dp[] of size “N” 

-> dp[i] = best answer to the question till index “i” - best answer of the journey if journey is starting at index 1 and ending at index “i”

-> Try to find the formula. 

-> Put the formula in the for loop 

-> Analyze all the dp values; most probably dp[n] will be the final answer 

dp[i] = max(dp[i-1] + b[i] , dp[i-3] + b[i] , dp[i-5] + b[i])

dp[n] will be the final answer which tells you the maximum cost to reach index “n”. 

Algorithm:- https://ideone.com/3sX5JJ.

C++ - https://onecompiler.com/cpp/42aqnwnm7
Java - https://onecompiler.com/java/42aqp8kz7
Py - https://onecompiler.com/python/42aqp9pgm

TC - O(N)
space.-> O(N)	 

 






int main() {
    int n;
    cin >> n;
    
    int b[n + 1]={0}; // Assuming b is already initialized
    
    int dp[n + 1]={0};
    
    for(int i=1;i<=n;i++){
      cin>>b[i];
    }
    
    dp[1] = b[1];
    dp[2] = b[1] + b[2];
    dp[3] = b[1] + b[2] + b[3];
    dp[4] = max(dp[1] + b[4], max(dp[2] + b[4], dp[3] + b[4]));
    dp[5] = max(dp[4] + b[5], dp[2] + b[5]);
    
    for (int i = 6; i <= n; i++) {
        dp[i] = max(dp[i - 1] + b[i], max(dp[i - 3] + b[i], dp[i - 5] + b[i]));
    }
    
    cout << dp[n] << endl;
    
    return 0;
}
