



// dp[1][1][1] = a[1]%2 == 0?1:0;
// dp[1][1][2] = a[1]%2 != 0?1:0;
// dp[][][]

// index,wHicH array,even/odd..........
// 
// 1 ---> even.....
// 2--> odd.....
// i from 2 to n....
// if(a[i]%2 == 0)
// dp[i][1][1]  = dp[i-1][1][1] + dp[i-1][2][1];
// else 
// dp[i][1][1] = dp[i-1][1][2] + dp[i-1][2][2];

// if(a[i]%2 == 0)
// dp[i][1][2] = dp[i-1][1][2] + dp[i-1][2][2];
// else
// dp[i][1][2] = dp[i-1][1][1] + dp[i-1][2][1];

// if(b[i]%2 == 0)
// dp[i][2][1] = dp[i-1][2][1] + dp[i-1][1][1];
// else 
// dp[i][2][1] = dp[i-1][2][2]  +  dp[i-1][1][2];

// if(b[i]%2 == 0)
// dp[i][2][2] = dp[i-1][2][2] + dp[i-1][1][2];
// else 
// dp[i][2][2] = dp[i-1][2][1] + dp[i-1][1][1];

#include <iostream>
#include <vector>

using namespace std;

void countJourneys(vector<int>& a, vector<int>& b) {
    int n = a.size();
    
    // Initialize dp array
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2, 0)));
    
    // Base case
        
    if(b[1]%2==0){
      dp[1][1][0] = 1 ; 
      dp[1][1][1] = 0 ; 
    }
    else{
      dp[1][1][0] = 0 ; 
      dp[1][1][1] = 1 ; 
    }
    
    
    if(a[1]%2==0){
      dp[1][0][0] = 1 ; 
      dp[1][0][1] = 0 ; 
    }
    else{
      dp[1][0][0] = 0 ; 
      dp[1][0][1] = 1 ; 
    }
        
    // Dynamic programming
    for (int i = 2; i <= n; ++i) {
        // Update dp[i][a][even]
        if (a[i] % 2 == 0) {
            dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][1][0])  ;
        } else {
            dp[i][0][0] = (dp[i - 1][0][1] + dp[i - 1][1][1])  ;
        }
        
        // Update dp[i][a][odd]
        if(a[i] % 2 == 0) {
            dp[i][0][1] = (dp[i - 1][0][1] + dp[i - 1][1][1])  ;
        } else {
            dp[i][0][1] = (dp[i - 1][0][0] + dp[i - 1][1][0])  ;
        }
        
        // Update dp[i][b][even]
        if (b[i] % 2 == 0) {
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][1][0])  ;
        } else {
            dp[i][1][0] = (dp[i - 1][0][1] + dp[i - 1][1][1])  ;
        }
        
        // Update dp[i][b][odd]
        if (b[i] % 2 == 0) {
            dp[i][1][1] = (dp[i - 1][0][1] + dp[i - 1][1][1])  ;
        } else {
            dp[i][1][1] = (dp[i - 1][0][0] + dp[i - 1][1][0])  ;
        }
    }
    
    // Total even and odd journeys
    int evenJourneys = (dp[n][0][0] + dp[n][1][0])  ;
    int oddJourneys = (dp[n][0][1] + dp[n][1][1])  ;
    
    cout << "Even journey count is " << evenJourneys << endl;
    cout << "Odd journey count is " << oddJourneys << endl;
}

int main() {
    vector<int> a = {1, 2, 1};
    vector<int> b = {3, 1, 1};
    
    countJourneys(a, b);
    
    return 0;
}








