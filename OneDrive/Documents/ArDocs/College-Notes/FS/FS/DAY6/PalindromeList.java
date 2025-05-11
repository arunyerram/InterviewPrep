// import java.util.*;

// class ListNode {
//     int val;
//     ListNode next;
//     ListNode() {this.val = -1;}
//     ListNode(int val) { this.val = val; }
//     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
// }

// class Solution {
//     public static ListNode getMid(ListNode head){
//         ListNode slow = head;
//         ListNode fast = head.next;
//         while(fast != null && fast.next != null){
//             fast = fast.next.next;
//             slow = slow.next;
//         }
//         return slow;
//     }
//     public boolean isPalindrome(ListNode head) {
//         if(head == null || head.next == null){
//             return true;
//         }
//         ListNode mid = getMid(head);
//         ListNode temp = mid.next;
//         mid.next = reverse(temp);
//         ListNode p1 = head;
//         ListNode p2 = mid.next;
//         while(p2 != null){
//             if(p1.val != p2.val){
//                 return false;
//             }
//             p1 = p1.next;
//             p2 = p2.next;
//         }
//         temp = mid.next;
//         mid.next = reverse(temp);
//         return true;
//     }
//     public ListNode reverse(ListNode head){
//         ListNode prev = null;
//         while(head != null){
//             ListNode next = head.next;
//             head.next = prev;
//             prev = head;
//             head = next;
//         }
//         return prev;
//     }

//     public static void printList(ListNode head){
//         while(head != null){
//             System.out.print(head.val+" ");
//             head = head.next;
//         }
//         System.out.println();
//     }
// }

// public class PalindromeLinkedList {
//     public static void main(String[] args){
//         Solution sol = new Solution();
//         ListNode head = new ListNode(1);
//         head.next = new ListNode(2);
//         head.next.next = new ListNode(3);
//         head.next.next.next = new ListNode(1);
//         sol.printList(head);
//         System.out.println(sol.isPalindrome(head));
//     }
// }

import java.util.*;

class Node{    
	int data;    
	Node next;    
		
	public Node(int data) {    
		this.data = data;    
		this.next = null;    
	}    
}    

class Solution
{
	//Write if any supporting methods here
	
	public static void printList(Node head){
	    Node temp = head;
	    while(temp!=null){
	        System.out.print(temp.data+"->");
	        temp = temp.next;
	    }
	    
	}
	
	public Node getMid(Node head){
	    Node slow = head;
	    Node fast = head;
	    while(fast.next!=null && fast.next.next!=null){
	        fast= fast.next.next;
	        slow=slow.next;
	    }
	    return slow;
	}
	
	public Node reverse(Node head){
	   Node prev = null;
	   while(head!=null){
	       Node next = head.next;
	       head.next = prev;
	       prev = head;
	       head = next;
	   }
	   //printList(head);
	   return prev;
	}
    
	public boolean isPalindrome(Node head) 
	{
		//Write your code here and return boolean value
	    if(head == null || head.next == null){
	        return true;
	    }
	    
	    Node mid = getMid(head);

		Node temp = mid.next;
	    mid.next = reverse(temp);
	    Node head1 = head;
	    Node head2 = mid.next;

	    while(head2!=null){
	        if(head1.data != head2.data){
	            return false;
	        }
	        head1 = head1.next;
	        head2 = head2.next;
	    }
		// temp = mid.next;
		// mid.next = reverse(temp);
	    return true;
	    
	}    
}

public class PalindromeList 
{    
	public Node head = null;    
	public Node tail = null;    
	
	public static void printList(Node head){
	    Node temp = head;
	    while(temp!=null){
	        System.out.print(temp.data+"->");
	        temp = temp.next;
	    }
	    
	}

	public void addNode(int data) 
	{    
		Node newNode = new Node(data);
		// Node temp = head;
		if(head == null) 
		{    
			head = newNode;    
			tail = newNode;    
		}    
		else 
		{    
			// while(temp.next!=null){
			//     temp = temp.next;
			// }   
			// temp.next = newNode;
			tail.next = newNode;
			tail = newNode;
		}    
	}    
        
	public static void main(String[] args) 
	{    
		Scanner sc=new Scanner(System.in);
		PalindromeList list = new PalindromeList();       
		String list2[]=sc.nextLine().split(" "); 
		for(int i=0;i<list2.length;i++)
			list.addNode(Integer.parseInt(list2[i]));
		Solution sl=new Solution();
// 		printList(list.head);
		System.out.println(sl.isPalindrome(list.head));
	}    
}    