/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode sortList(ListNode head) {
        
        // my first thought: like divide & conquer, merge sort
        
        // then quick sort? maybe not
       
       // leave the special case
       if(head==null || head.next==null) return head;
       
       
       // general 
       ListNode left = head;
       ListNode right = div(head);
       
       ListNode subLeft = sortList(left);
       ListNode subRight = sortList(right);
       
       return merge(subLeft,subRight);
        
        
    }
    public ListNode div(ListNode node){
        
        ListNode fakeHead = new ListNode (0);
        fakeHead.next = node; // ** bug **
        ListNode fast = fakeHead, slow = fakeHead;
        while (fast!=null && fast.next!=null){
            slow = slow.next;
            fast = fast.next.next; /// ** bug here **
        }
        ListNode result = slow.next;
        slow.next =null;
        return result;
    }
  
  
    public ListNode merge(ListNode node1, ListNode node2){
       
        if(node1==null) return node2;
        if(node2==null) return node1;
        
        ListNode head =null;
        if(node1.val<node2.val){
            head = node1;
            node1 = node1.next;
        }
        else{
            head= node2;
            node2 = node2.next;
        }
        
        head.next = merge(node1,node2);
        
        return head;   
    }
   
    
}