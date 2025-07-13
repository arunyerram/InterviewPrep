
// Link https://www.desiqna.in/17037/google-girl-hackathon-oa-2024-april-2024-set-1 



// Understanding - Divide the array in “k” parts such that the sum of all the parts is maximum.

// Sum of a part [a1 a2 a3 a4……] = a1 -a2 + a3 -a4…….. 

// What if all the numbers are positive? 

// Sum of the array is the answer and we keep each number in separate parts -> Total N parts. 


// What if the numbers are negative :- Watch.



// dp[i][+] = best block sum you can get till index “i”  such that + sign enforced on the number b[i](+)

// dp[i][-] =  best block sum you can get till index “i” such that -sign is enforced on the last number b[i](-) 

// When you are calculating dp[i][+] = you can always assume that the new block is starting from [b[i] ……….] 

// dp[i][+] = b[i] + max(dp[i-1][+],dp[i-1][-])

// dp[i][-] = -(b[i]) + dp[i-1][+] (Why?)

// Because if the current number you are making is negative then it is compulsory to make the previous number positive. 


// Final answer - dp[n][+] OR dp[n][-] 



// C++ - https://onecompiler.com/cpp/42b8kuc5k
// Java - https://onecompiler.com/java/42b8m2zvu
// Python - https://onecompiler.com/python/42b8m4y6w



// https://drive.google.com/file/d/1c6o1SVmALNlwa3dJK3ANXuKDnD3f2QRV/view







