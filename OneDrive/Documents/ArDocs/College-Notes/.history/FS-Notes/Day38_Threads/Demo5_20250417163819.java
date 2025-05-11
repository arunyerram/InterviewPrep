class Calculate {
	double num;
	boolean check = false;

	synchronized void number(double num){
		try {
			if(check == true)	
				wait();
		}
		catch(InterruptedException ie) {}
		this.num = num;
		System.out.println("Number is " + num);
		check = true;
		notify();
	}

	synchronized void root(){
		try {
			if(check == false) 
				wait();		
		}
		catch(InterruptedException ie) {}
		System.out.println("Root is " + Math.sqrt(num));
 		//check = false;
		//notify();
	}
}

class Produce implements Runnable {
	Thread t;
	Calculate calc;

	Produce(Calculate calc){
		this.calc = calc;
		t = new Thread(this);
		t.start();
	}

	public void run(){
		try {
			for(int i = 0; i < 6; i++){
				calc.number((double)i);
				Thread.sleep(300);		
			}
		}
		catch(InterruptedException ie) {}
	}
}

class Consume implements Runnable{
	Thread t;
	Calculate calc;

	Consume(Calculate calc){
		this.calc = calc;
		t = new Thread(this);
		t.start();
	}

	public void run(){
		try {
			for(int i = 0; i < 6; i++){
				calc.root();
				Thread.sleep(50); 
			}
		}
		catch(InterruptedException ie) {}
	}
}

class Demo5 {
	public static void main(String[]args){
		Calculate calc = new Calculate();
		Consume c = new Consume(calc);
		Produce p = new Produce(calc);
	}
}




// dp[i][0] = dp[i-1][1];
// dp[i][1] = max(dp[i-1][0],dp[i-1][1]) ;

// Mr.Uday is trying to develop a software which reads array of strings from user and gives the
// longest common prefix of those strings, if no common prefix then it will give empty string. 
// Help uday to develop program.


// Input Format: 
// -------------
// Line-1: array of strings seperated by ','

// Output Foramt: 
// --------------
// longest common prefix.

// Sample Input-1:
// ---------------
// flower,flow,flight

// Sample Output-1: 
// ----------------
// fl

// Sample Input-2:
// --------------
// dog,racecar,car

// Sample Output-2:
// ----------------
// ""

// Explanation: There is no common prefix among the input strings.

// Note: USE TRIE DATASTRUCTURE
//       STRING SHOULD CONTAIN ONLY LOWER CASE ALPHABETS(a to z  only)




// 	  import java.util.*;
// 	  class TrieNode {
// 		  char val;
// 		  boolean isEnd;
// 		  TrieNode[] children;
		  
// 		  public TrieNode() {
// 			  this.children = new TrieNode[26];
// 		  }
		  
// 		  public TrieNode(char c) {
// 			  this();
// 			  this.val = c;
// 		  }
// 	  }
	  
// 	  class Trie {
// 		  private TrieNode root;
		  
// 		  public Trie() {
// 			  this.root = new TrieNode();
// 		  }
		  
// 		  public void insert(String word) {
// 			  TrieNode curr = this.root;
			  
// 			  for (char c : word.toCharArray()) {
// 				  if (curr.children[c - 'a'] == null) {
// 					  curr.children[c - 'a'] = new TrieNode(c);
// 				  }
				  
// 				  curr = curr.children[c - 'a'];
// 			  }
			  
// 			  curr.isEnd = true;
// 		  }
		  
// 		  public String longestCommonPrefix() {
// 			  //Write your code here and return string
// 		  }
		  
		 
// 	  }
	  
// 	  class Solution {
// 		  public String longestCommonPrefix(String[] strs) {
// 			  if (strs == null || strs.length == 0) {
// 				  return "";
// 			  }
			  
// 			  Trie trie = new Trie();
			  
// 			  for (String word : strs) {
// 				  trie.insert(word);
// 			  }
			  
// 			  return trie.longestCommonPrefix();
// 		  }
// 		  public static void main(String[] args)
// 		  {
// 			  Scanner sc=new Scanner(System.in);
// 			  String[] str = sc.nextLine().trim().split(",");
// 			  System.out.println(new Solution().longestCommonPrefix(str));
// 		  }
	  
// 	}

