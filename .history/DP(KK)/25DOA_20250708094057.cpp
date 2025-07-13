

There are N tasks. To be performed on N days; each day you perform a single task 

Each day you have three choices; either perform the easy[i] , medium [i] , hard[i] 

For doing each task you get some points. 

Maximize the total points. 

On day “i” you can do a hard task if and only if the day before the previous day you did an easy task 

On day “i” you can do a medium task if and only if the day before you did easy task and the day before that you did medium task 

Applicable from day>2. 



Solution :- 

dp_easy[i] = the maximum score you can get if you are doing an easy task on day “i” 


dp-easy[i] = easy[i]+(max(dp_easy(i-1),dp_medium(i-1),dp_hard(i-1)) 

dp_medium[i] = the maximum score you can get if you are doing an medium task on day “i” and follow all the conditions required to do medium task on day “i” 

dp_medium[i]=medium[i]+easy[i-1]+dp_medium[i-2] //RRRRR


dp_hard[i] = hard[i] + easy[i-1] + dp_easy[i-2] ……

dp_hard[i] = hard[i] + medium[i-1] + easy[i-2] + dp_medium[I-3]......

dp_hard[i] = hard[i] + hard[i-1] + easy[i-2] + dp_easy[i-3]........


Max of all of them is the answer 


Final answer :- max(dp_easy[n],dp_medium[n],dp_hard[n]) 




C++ - https://ideone.com/TMizpx. 
Java - https://ideone.com/JaJ9h4. 
Py - https://ideone.com/7whQNg 
















