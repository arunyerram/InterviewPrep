
function processStrings() {
    let str1 = "The Quick Brown Fox";
    let toggleCase = (str) => 
        str.split("").map(char => 
            char === char.toUpperCase() ? char.toLowerCase() : char.toUpperCase()
        ).join("");
    
    var ans = "";
    for(let i=0;i<str1.length;i++){
        if(str1[i] != " "){
            ans = ans + str1[i];
        }
    }
    
    console.log(toggleCase(ans));
}

processStrings();


You are given an array of people, which are the attributes of some people in 
a queue (not necessarily in order). 
Each people[i] = [hi, ki] represents the ith person of height hi with exactly ki 
other people in front who have a height greater than or equal to hi.

Reconstruct and return the queue that is represented by the input array people. 
The returned queue should be formatted as an array queue, where queue[j] = [hj, kj]
is the attributes of the jth person in the queue (queue[0] is the person at the front of the queue).

Input Format : 
--------------
Line-1: An integer n
Line-2: n number of pairs

Output Format : 
--------------
list of n pairs

Sample Input-1:
---------------
6
7 0
4 4
7 1
5 0
6 1
5 2

Sample Output-1: 
---------------
[[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]]

Explanation:
Person 0 has height 5 with no other people taller or the same height in front.
Person 1 has height 7 with no other people taller or the same height in front.
Person 2 has height 5 with two persons taller or the same height in front, which is person 0 and 1.
Person 3 has height 6 with one person taller or the same height in front, which is person 1.
Person 4 has height 4 with four people taller or the same height in front, which are people 0, 1, 2, and 3.
Person 5 has height 7 with one person taller or the same height in front, which is person 1.
Hence [[5,0],[7,0],[5,2],[6,1],[4,4],[7,1]] is the reconstructed queue.

Sample Input-2:
--------------
6
6 0 
5 0 
4 0
3 2
2 2
1 4

Sample Output-2: 
----------------
[[4,0],[5,0],[2,2],[3,2],[1,4],[6,0]]
 

Constraints:
-------------
1 <= people.length <= 2000
0 <= hi <= 106
0 <= ki < people.length
It is guaranteed that the queue can be reconstructed.











An English competition is taking place in a school. One problem is given in the following manner 
There are words formed with lower case alphabets, participants need to find the count of characters which are repeatedly appeared in all words. 
If no such characters are there, then return 0.

Note: give solution using bit manipulation only

Input Format: 
-------------
Line-1: comma separated strings

Output Format:
--------------
Line-1: an integer

Sample Input-1:
---------------
abc,abc,bc

Sampel Output-1:
----------------
2

Explanation:
------------
The characters 'b' and 'c' appear in each word, so there output is 2 .

Sample Input-2:
---------------
abcdde,baccd,eeabg

Sample Output-2:
----------------
2

Explanation:
------------
Only 'a' and 'b' occur in every word.


Constraints
Each word consists of only lower-case letters ('a'-'z').