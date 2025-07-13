

// You are given two arrays a and b -> both are of size “N”. 

// Start your journey at index 1 and end your journey at index “N”. 

// In a move you can move from a[i]->a[i+1] or a[i]->b[i+1] 

// OR 

// b[i]->b[i+1] or b[i]->a[i+1]

// Output the number of journeys whose sum is even and odd. 



// Input -> 

// A        B
// 1         3
// 2         1
// 1         1

// Total 4 even journeys :- (1→2→1) 2 times; + (3→2→1) 2 times; = 4.

// Similarly 4 odd journeys. 

// Basic Intuition. 

// dp[i][even] = number of even journeys  ending at index “i” 

// dp[i][odd] = No of odd journeys till index i


// How can we make it more easy and descriptive?
// We are not directly able to make the formula because we exactly need to know that for which current array at index “i” is it being reached from which index i-1 of which array 

// dp[i][a][even] = number of journeys ending at index “i” of array a and having even sum. 

// dp[i][a][odd] , dp[i][b][even] and dp[i][b][odd]. 


// If a[i] is even:- 

// dp[i][a][even] = dp[i-1][a][even] + dp[i-1][b][even] 

// If a[i] is odd:- 

// dp[i][a][even] = dp[i-1][a][odd] + dp[i-1][b][odd]

// If a[i] is even:- 

// dp[i][a][odd] = dp[i-1][a][odd] + dp[i-1][b][odd] 


// If a[i] is odd :- 


// Homework 


// Similarly for all dp[i][b][even/odd] 


// C++ - https://onecompiler.com/cpp/42bb4rwzy
// Java - https://onecompiler.com/java/42bbrrxn6
// Py - https://onecompiler.com/python/42bbrtjw8


// TC - O(N)
// Space :- O(N*2*2) = O(N.) 



// analysis..................


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










import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Integer> a = Arrays.asList(1, 2, 1);
        List<Integer> b = Arrays.asList(3, 1, 1);

        countJourneys(a, b);
    }

    public static void countJourneys(List<Integer> a, List<Integer> b) {
        int n = a.size();

        // Initialize dp array
        int[][][] dp = new int[n + 1][2][2];

        // Base case
        if (b.get(0) % 2 == 0) {
            dp[1][1][0] = 1;
            dp[1][1][1] = 0;
        } else {
            dp[1][1][0] = 0;
            dp[1][1][1] = 1;
        }

        if (a.get(0) % 2 == 0) {
            dp[1][0][0] = 1;
            dp[1][0][1] = 0;
        } else {
            dp[1][0][0] = 0;
            dp[1][0][1] = 1;
        }

        // Dynamic programming
        for (int i = 2; i <= n; ++i) {
            // Update dp[i][a][even]
            if (a.get(i - 1) % 2 == 0) {
                dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][1][0]);
            } else {
                dp[i][0][0] = (dp[i - 1][0][1] + dp[i - 1][1][1]);
            }

            // Update dp[i][a][odd]
            if (a.get(i - 1) % 2 == 0) {
                dp[i][0][1] = (dp[i - 1][0][1] + dp[i - 1][1][1]);
            } else {
                dp[i][0][1] = (dp[i - 1][0][0] + dp[i - 1][1][0]);
            }

            // Update dp[i][b][even]
            if (b.get(i - 1) % 2 == 0) {
                dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][1][0]);
            } else {
                dp[i][1][0] = (dp[i - 1][0][1] + dp[i - 1][1][1]);
            }

            // Update dp[i][b][odd]
            if (b.get(i - 1) % 2 == 0) {
                dp[i][1][1] = (dp[i - 1][0][1] + dp[i - 1][1][1]);
            } else {
                dp[i][1][1] = (dp[i - 1][0][0] + dp[i - 1][1][0]);
            }
        }

        // Total even and odd journeys
        int evenJourneys = (dp[n][0][0] + dp[n][1][0]);
        int oddJourneys = (dp[n][0][1] + dp[n][1][1]);

        System.out.println("Even journey count is " + evenJourneys);
        System.out.println("Odd journey count is " + oddJourneys);
    }
}
