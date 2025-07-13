
There are 'n' stones in a row from 0 to n-1. For every ith stone , there are 2 values associated with it, a[i] and b[i] . You have to remove all the stones from the row one by one. Removing the ith stone follows the rule :

 

 

If (i-1)th and (i+1)th stones are still present , then , cost of removing the ith stone is b[i].

 

 

if either (i-1)th or (i+1)th stone is present , then cost of removing the ith stone is a[i].

 

 

if neither (i-1)th nor (i+1)th stone is present , the cost of removing the ith stone is 0.

 

 

Find the minimum total cost of removing all the stones.