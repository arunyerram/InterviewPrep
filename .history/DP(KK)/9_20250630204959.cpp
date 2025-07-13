// Link  https://atcoder.jp/contests/dp/tasks/dp_c 

// Greedy vs DP :-> 

// -> If a problem can be solved by the Greedy approach ; it means it is guaranteed ; that at each step ; you make a choice and that choice is the best possible for now as well as the future. Then you can solve this problem using the Greedy Method. 

// -> If there are multiple choices at each step and it is not clear which choice can given you the better answer long term -> use DP 

// Easier version of the Question :-> You are given three arrays a ; b ; c -> at each index you either select a[i] or b[i] or c[i] ; once you are done selecting n elements we want the sum of all elements to be maximum. 
// Link https://ideone.com/kPNLiz 
// This is a greedy solution-> Why? -> Self explanatory 


// Hard Version.-> https://atcoder.jp/contests/dp/tasks/dp_c 

// -> You cannot select a number from a particular array for more than 1 time consecutively -> You have to find the maximum sum of all the numbers -> can only be solved by DP-> because there are multiple choice and any choice you has not guarantee if the future will be great or final answer will be maximum. 

// -> 3 arrays a b c hence we create 3 dp arrays dpa[] dpb[] dpc[] 


// dpa[i] = best answer to the question if size of the array was ‘i’ and you selected a[i] at the ith index. 

// dpb[i] = best answer to the question if size of array is i and selected b[i] at index i

// dpc[i] = best answer to the question if size of array is i and selected c[i] at index i 

// -> dpa[3] = a[3] + max(dpb[2],dpc[2]) 
// Generalize ; substitute.-> i 

// dpa[i] = a[i] + max(dpb[i-1],dpc[i-1])
// dpb[i] = b[i] + max(dpc[i-1],dpa[i-1])



// dpc[i] = c[i] + max(dpb[i-1],dpa[i-1]) ;

// Put these in a for loop and your job is done. 

// TC :- O(N).. 
// SC:- O(N)...... 


// C++  https://atcoder.jp/contests/dp/submissions/42299240 

// Java https://atcoder.jp/contests/dp/submissions/42308712 
// Py https://atcoder.jp/contests/dp/submissions/42308782 

// New Question.-> Same as above ; but you are allowed to take a maximum of only 2 consecutive numbers ; not more than that->(3 numbers should not be consecutive.)

// -> 2 consecutive are allowed; 
// -> 3 consecutive are not allowed; 

// -> dpa[1] = a[1] dpb[1] = b[1] dpc[1] = c[1] 

// -> dpa[2] = a[2] + max(a[1],b[1],c[1]) 
// -> dpb[2] = b[2] + max(a[1],b[1],c[1])
// -> dpc[2] = c[2] + max(a[1],b[1],c[1]) 

// -> dpa[3] = a[3] + max(dpb[2],dpc[2]) -> first 
//                = OR a[3] + a[2] + max(dpb[1],dpc[1]) 



// -> dpb[i] = max(b[i] + max(dpa[i-1],dpc[i-1]) , b[i] + b[i-1] +max(dpa[i-2],dpc[i-2])) 

// C++ https://ideone.com/PKYS2S. 
// Java. https://ideone.com/OaMxSE. 
// Py https://ideone.com/4wC2i7.  


// —-----------------------------------------------------------------

// Hardest Version. -> https://www.youtube.com/watch?v=oAhlTS7U8GM&t=2s&ab_channel=KumarK%5BAmazon%5D . 




#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;





 




























