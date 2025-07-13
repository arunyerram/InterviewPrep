

// Mentor - Kumar K(https://www.linkedin.com/in/kumark1/ , Prv SDE @ Amazon,All India Rank 12 Google CodeJam’21)




// Find the number of ways to make sum “y” with the numbers “1”,”2”,”4”,”6”. 

// Condition :- 4 can be used at most 2 times. 

// Kumar K student cracks 80 LPA SDE Job offer from 10up - Europe Based MNC

// https://www.youtube.com/watch?v=JWQKyr3sgG0&t=419s&ab_channel=KumarK%5BAmazon%5D. 

// Join us here - https://training.desiqna.in 


// dp[3] = dp[2] + dp[1] 


// dp[4] = dp[0] + dp[2] + dp[3]

// dp[5] = dp[1]+dp[4]+dp[3]

// dp[6] = dp[0]+dp[4]+dp[2]+dp[5]




// C++ - https://ideone.com/BUKqmB
// Java - https://ideone.com/frwnn2
// Py - https://ideone.com/ejiSCz



// Actual Problem - 

// dp[i][0] = number of ways to create the number “i” such that “0” 4 is used. 

// dp[i][1] = number of ways to create the number “i” such that “1” 4 is used. 

// dp[i][2] = number of ways to create the number “i” such that “2” 4 are used. 


// Final answer = dp[n][0] + dp[n][1] + dp[n][2] → at most 2 <=2.

// dp[i][0]=dp[i-1][0]+dp[i-2][0]+dp[i-6][0] -> according to Gauri’s law. 

// dp[i][1]=dp[i-1][1]+dp[i-2][1]+dp[i-4][0]+dp[i-6][1]


// dp[i][2] =dp[i-1][2]+dp[i-2][2]+dp[i-4][1]+dp[i-6][2]




// -> n 






// -> dp[n+1][5]; dp[0][0]=dp[0][1]=dp[0][2]=1




// dp[1]=1


// for(i=2;i<=n;i++){
    
//    dp[i][0]=dp[i-1][0]+dp[i-2][0]+dp[i-6][0] 
//    dp[i][1]=dp[i-1][1]+dp[i-2][1]+dp[i-4][0]+dp[i-6][1]
//    dp[i][2] =dp[i-1][2]+dp[i-2][2]+dp[i-4][1]+dp[i-6][2]


// }
// print(dp[n][0]+dp[n][1]+dp[n][2])






// C++ - https://ideone.com/wbTpLJ.
// Java - https://ideone.com/M1Xbqd.
// Py - https://ideone.com/j4OAp0








// TC - O(N) 
// Takes O(N*3) size which is O(N.)






// Final - Same as above but at max “2” 4 can be used and at 
// max “2” 6 can be used. 


// C++ - https://ideone.com/bXq1M7
// Java - https://ideone.com/6Ixfe2
// Py - https://ideone.com/AAWfo9














