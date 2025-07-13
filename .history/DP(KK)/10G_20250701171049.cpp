
Link to the question :-> https://www.desiqna.in/13822/google-dp-interview-question-jan-2023 
Find the number of journeys where you start from index 1 and end at index ‘n’ and the sum of every journey should be odd..

Allowed to make jumps of size 1 or 2 
5 4 2 6 

Number of odd sum journey : 
-> (5,2,6)
-> (5,4,2,6)
-> (5,4,6)

Number of even sum journey : 
-> Nothing 


2 3 5 8 10 

Evn sum journey 👍
//evn
    //2...3...5...8...10
    //2...3...5.....10

Odd sum journey : 

    
    //odd
    //2...5...10
    //2...3...8...10
    //2...5...8....10 





Dp[i][even] = number of even sum journey till index ‘i’
Dp[i][odd] = number of odd sum journey till index ‘i’




-> 
[1 2 3 4]

Dp[3][even] = dp[1][odd] + dp[2][odd] 

 



If a[i] is even …. 

Dp[i][eve] = dp[i-1][eve] + dp[i-2][even] 

Dp[i][odd] = dp[i-1][odd] + dp[i-2][odd] 


If a[i] is odd …..

Dp[i][even] = dp[i-1][odd] + dp[i-2][odd] 


Dp[i][odd] = dp[i-1][eve] + dp[i-2][eve] 
C++ https://ideone.com/kqxkFB 
Java https://ideone.com/f5sswM 
Py https://ideone.com/Yt6SLb 






Find the number of journeys where you start from index 1 and end at index ‘n’ and the sum of every journey should be odd/even..

Allowed to make jumps of size 1 or 2 or
3.

If a[i] is even …. 

Dp[i][even] = dp[i-1][even] + dp[i-2][even] + dp[i-3][even] 

Dp[i][odd] = dp[i-1][odd] + dp[i-2][odd] + dp[i-3][odd]


If a[i] is odd …..

Dp[i][even] = dp[i-1][odd] + dp[i-2][odd] + dp[i-3][odd]


Dp[i][odd] = dp[i-1][even] + dp[i-2][even] + dp[i-3][even]
 
C++ https://ideone.com/Zafite 
Java https://ideone.com/cEV9RN 
Py https://ideone.com/mDK3UE 








