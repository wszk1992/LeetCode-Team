/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeElements(ListNode head, int val) {
        
        // solution 1: iterative 
        /*
        ListNode myNode = new ListNode(0); // fake head
        ListNode currentNode,prevNode;
        myNode.next = head;
        currentNode = head;
        prevNode = myNode;
        
        
        while(currentNode!=null){
            if(currentNode.val == val){
                prevNode.next = currentNode.next;
               // currentNode = prevNode.next; // line 1
            }
            else{ // keep moving 
               // currentNode = currentNode.next; // line 2 
                prevNode = prevNode.next;
            } 
            // combine line 1 and line 2
            currentNode = currentNode.next;
        }
        return myNode.next;
        */
        // solution 2: recursive-----> but the operation time is same....
        
        if(head==null)
            return head;
        
        head.next = removeElements(head.next, val); // miss ;-----> FUCK
        if(head.val == val){
            return head.next;
        }
        else
            return head;
    }
}