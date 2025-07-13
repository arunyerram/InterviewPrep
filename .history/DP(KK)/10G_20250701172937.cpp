
// Link to the question :-> https://www.desiqna.in/13822/google-dp-interview-question-jan-2023 
// Find the number of journeys where you start from index 1 and end at index ‘n’ and the sum of every journey should be odd..

// Allowed to make jumps of size 1 or 2 
// 5 4 2 6 

// Number of odd sum journey : 
// -> (5,2,6)
// -> (5,4,2,6)
// -> (5,4,6)

// Number of even sum journey : 
// -> Nothing 


// 2 3 5 8 10 

// Evn sum journey 👍
// //evn
//     //2...3...5...8...10
//     //2...3...5.....10

// Odd sum journey : 

    
//     //odd
//     //2...5...10
//     //2...3...8...10
//     //2...5...8....10 





// Dp[i][even] = number of even sum journey till index ‘i’
// Dp[i][odd] = number of odd sum journey till index ‘i’




// -> 
// [1 2 3 4]

// Dp[3][even] = dp[1][odd] + dp[2][odd] 

 



// If a[i] is even …. 

// Dp[i][eve] = dp[i-1][eve] + dp[i-2][even] 

// Dp[i][odd] = dp[i-1][odd] + dp[i-2][odd] 


// If a[i] is odd …..

// Dp[i][even] = dp[i-1][odd] + dp[i-2][odd] 


// Dp[i][odd] = dp[i-1][eve] + dp[i-2][eve] 
// C++ https://ideone.com/kqxkFB 
// Java https://ideone.com/f5sswM 
// Py https://ideone.com/Yt6SLb 






// Find the number of journeys where you start from index 1 and end at index ‘n’ and the sum of every journey should be odd/even..

// Allowed to make jumps of size 1 or 2 or
// 3.

// If a[i] is even …. 

// Dp[i][even] = dp[i-1][even] + dp[i-2][even] + dp[i-3][even] 

// Dp[i][odd] = dp[i-1][odd] + dp[i-2][odd] + dp[i-3][odd]


// If a[i] is odd …..

// Dp[i][even] = dp[i-1][odd] + dp[i-2][odd] + dp[i-3][odd]


// Dp[i][odd] = dp[i-1][even] + dp[i-2][even] + dp[i-3][even]
 
// C++ https://ideone.com/Zafite 
// Java https://ideone.com/cEV9RN 
// Py https://ideone.com/mDK3UE 








#include <bits/stdc++.h>

using namespace std;
int dp[100005][3] ; 
int main() {
    int n ; 
    cin>>n ; 
    int a[n+1] = {0};
    int i = 1 ; 
    while(i<=n){
        cin>>a[i];
        i++;
    }
    
    //dp[i][1]--> number of journeys till index 'i' whose sumis odd.
    //dp[i][2]--> number of journeys till index 'i' whose sumis even.
    
    if(a[1]%2==0){
        dp[1][2] = 1 ; 
    } 
    
    else {
        dp[1][1] = 1 ; 
        
    }
    
    if(a[2]%2==0){
        dp[2][2] = dp[1][2] ;
        dp[2][1] = dp[1][1] ; 
    }
    else{
        dp[2][2] = dp[1][1] ; 
        dp[2][1] = dp[1][2] ;
    }
    
    i = 3 ; 
    while(i<=n){
        
        if(a[i]%2==0){
            dp[i][2] = dp[i-1][2] + dp[i-2][2] + dp[i-3][2];
            dp[i][1] = dp[i-1][1] + dp[i-2][1] + dp[i-3][1]; 
        }
        
        else{
            dp[i][2] = dp[i-1][1] + dp[i-2][1] + dp[i-3][1]; 
            dp[i][1] = dp[i-1][2] + dp[i-2][2] + dp[i-3][2];
        }
        
        
        
        i++;
    }    
    
    
    cout<<dp[n][1]<<" "<<dp[n][2] ; 
    
    
    return 0 ; 
}



// import java.util.Scanner;

// public class Main {
//     public static void main(String[] args) {
//         Scanner scanner = new Scanner(System.in);
//         int n = scanner.nextInt();
//         int[] a = new int[n + 1];
//         int[][] dp = new int[100005][3];

//         for (int i = 1; i <= n; i++) {
//             a[i] = scanner.nextInt();
//         }

//         if (a[1] % 2 == 0) {
//             dp[1][2] = 1;
//         } else {
//             dp[1][1] = 1;
//         }

//         if (a[2] % 2 == 0) {
//             dp[2][2] = dp[1][2];
//             dp[2][1] = dp[1][1];
//         } else {
//             dp[2][2] = dp[1][1];
//             dp[2][1] = dp[1][2];
//         }

//         int i = 3;
//         while (i <= n) {
//             if (a[i] % 2 == 0) {
//                 dp[i][2] = dp[i - 1][2] + dp[i - 2][2] + dp[i - 3][2];
//                 dp[i][1] = dp[i - 1][1] + dp[i - 2][1] + dp[i - 3][1];
//             } else {
//                 dp[i][2] = dp[i - 1][1] + dp[i - 2][1] + dp[i - 3][1];
//                 dp[i][1] = dp[i - 1][2] + dp[i - 2][2] + dp[i - 3][2];
//             }

//             i++;
//         }

//         System.out.println(dp[n][1] + " " + dp[n][2]);
//     }
// }





// n = int(input())
// a = [0] * (n + 1)
// dp = [[0] * 3 for _ in range(100005)]

// for i in range(1, n + 1):
//     a[i] = int(input())

// if a[1] % 2 == 0:
//     dp[1][2] = 1
// else:
//     dp[1][1] = 1

// if a[2] % 2 == 0:
//     dp[2][2] = dp[1][2]
//     dp[2][1] = dp[1][1]
// else:
//     dp[2][2] = dp[1][1]
//     dp[2][1] = dp[1][2]

// i = 3
// while i <= n:
//     if a[i] % 2 == 0:
//         dp[i][2] = dp[i - 1][2] + dp[i - 2][2] + dp[i - 3][2]
//         dp[i][1] = dp[i - 1][1] + dp[i - 2][1] + dp[i - 3][1]
//     else:
//         dp[i][2] = dp[i - 1][1] + dp[i - 2][1] + dp[i - 3][1]
//         dp[i][1] = dp[i - 1][2] + dp[i - 2][2] + dp[i - 3][2]
    
//     i += 1

// print(dp[n][1], dp[n][2])
