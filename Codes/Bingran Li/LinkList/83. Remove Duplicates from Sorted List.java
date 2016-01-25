/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        
        if(head==null || head.next==null){
            return head;
        }
        ListNode currentNode = head;
        while(currentNode!=null && currentNode.next!=null){
            
            if(currentNode.next.val==currentNode.val){ // If ---> wrong......
            currentNode.next = currentNode.next.next;
            }
            else   // miss this ----> maybe i should wirte some comment...
            currentNode = currentNode.next;
        }
        return head;
        
        
    }
}