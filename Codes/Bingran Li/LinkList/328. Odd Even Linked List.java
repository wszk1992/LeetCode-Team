/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode oddEvenList(ListNode head) {
        // solution 1: memory exceed??!!------have bug
     
        ListNode oddHead,evenHead;
        ListNode node1, node2;
        if(head==null || head.next==null)
            return head;
        oddHead = head;
        evenHead = head.next;
        node1=oddHead;
        node2=evenHead;
        while(node2!=null && node2.next!=null){ // miss first condition
            node1.next=node2.next;
            node1=node2.next;
           // if(node1.next==null)  -----> wrong
           //   break;
            node2.next=node1.next;
            node2=node1.next;
        }
        node1.next = evenHead;
        return head;

        // solution 2: 
        
        
    }
}