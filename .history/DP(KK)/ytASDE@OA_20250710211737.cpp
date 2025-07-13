

https://www.linkedin.com/feed/update/urn:li:activity:7348384277501247489/ (like it to get Amazon referral) 


Hi fellow coders,
I have come across a coding question, which I was unable to solve. I need some thoughts on it.

------------------------------
Problem Statement:

You are given an array "arr" of length at most 2000(N), where each element is an integer in the range 0 <= arr[i] <= 10^9.

You may rearrange the elements of the array in any order.

For each index i (0 ≤ i < N), define the variance at index i as the absolute difference between the maximum and minimum values among the first i + 1 elements (i.e., from index 0 to index i).

Let the total variance be the sum of variances at all indices.

Your task is to rearrange the array to minimize the total variance, and return this minimum possible sum.

---------------------------
Sample input :
N = 3 & arr = [1, 3, 4]

Output: 4

Explanation:
The optimal rearrangement is: [3, 4, 1]

At index 0: max = 3, min = 3 → variance = 0

At index 1: max = 4, min = 3 → variance = 1

At index 2: max = 4, min = 1 → variance = 3

Total variance = 0 + 1 + 3 = 4
-----------------------------
Let me know if any further clarifications are needed. 
Thanks advance 🙂

-> Welcome student 

-> What if we needed to extract only 2 elements from the given array -> sort the array -> and check all the adjacent differences and pick the two adjacent elements with minimum adjacent difference; 


-> What if you want to extract the answer for 3 elements -> sort the array and try all the subarrays of size “3”; (in optimal fashion;) 

-> for each subarray sorted of size 3 -> {a1,a2,a3} -> there are two best options -> always go with them; ->{a1,a2} +{a3} OR {a2,a3}+{a1}

-> dp[i][j] => best answer to the question if you consider the sorted array [i…….j] 

Final answer -> dp[1][n];

-> dp[i][i+1] = b[i+1]-b[i] 

-> dp[i][j] = min(dp[i][j-1] + b[j]-b[i],dp[i+1][j] + b[j]-b[i]) 

-> dp[2][3] = min(dp[1][2] + b[3]-b[1],dp[2][3] + b[3]-b[1]) 

-> dp[i][j] = min(dp[i][j-1] + b[j]-b[i],dp[i+1][j] + b[j]-b[i]) 


