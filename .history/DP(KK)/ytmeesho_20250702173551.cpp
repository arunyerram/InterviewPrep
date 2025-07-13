

// Link -> https://www.desiqna.in/18814/meesho-oa-ctc-35l-tree-climber-29th-june-set-7-kumar-k 

// Pre-requisite Warmup DSA + OA + CP Course - https://docs.google.com/document/d/1DMJKY_L2wem72ygUCao4IpZ7_jOW9LxZMyOPlH-gZQA/edit?tab=t.0 




// -> Always try to solve the easier version by considering a linear tree ⇒ array 

// -> Given an array -> for each index “j” find how many “i” exist in the range [0….j-1] such that a[i]*a[j] ⇒ perfect square; 

// -> Brute Force :-> TC :- O(N^2);

// -> Optimization :-> Any number y == k1.(g)^2; 

// :-> Each number in the array -> we will represent it as :-> k1*(g2)^2; 


// -> Problem solved; 

// -> create k1[] 

// -> for any “j” you need to find how many k1[i] in the range “0 to j-1” have their value == k1[j];

// -> use hashmap for it -> RRRRR 

// -> how will you convert the given number “y” to k1*(g)^2; 

// -> You will do special prime factorization algorithm and multiply factors with odd frequency to generate k1 for the given number -> further explained in video 


// -> Once you have done on the array -> do it on the tree using DFS;

// C++ - https://ideone.com/76ycom ; 
// Java - https://ideone.com/ZicDRU 
// Py -  https://ideone.com/eP5Ot1 





