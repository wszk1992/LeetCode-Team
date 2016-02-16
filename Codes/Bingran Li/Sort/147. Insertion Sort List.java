/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode insertionSortList(ListNode head) {
        // bug free
        if(head==null || head.next==null) return head;
        
        ListNode fakeHead = new ListNode(Integer.MIN_VALUE);
        fakeHead.next = head;
        
        ListNode sorted = head;
        ListNode current = head.next;
        
        while(sorted.next!=null){
            
            ListNode back = fakeHead;
            ListNode front = fakeHead.next;
            
            while(back!=sorted){
                
                if(current.val<front.val){
                    sorted.next = current.next;
                    back.next = current;
                    current.next = front;
                    current = sorted.next;
                    break;
                }
                back = front;
                front = front.next;
            }
            if(front == current){
                sorted = current;
                current = current.next;
            }
        }
        return fakeHead.next;
        
    }
}