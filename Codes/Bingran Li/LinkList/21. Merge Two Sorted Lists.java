/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        // solution 1: not elegant
        /*
        ListNode current1, next1,current2,next2;
        
        //special case
        if(l1==null)
            return l2;
        if(l2==null)
            return l1;
            
        //common case
        ListNode myNode = new ListNode(l2.val-1);
        current1=myNode;
        current2=l2;
        next1=l1;
        next2=l2;
        while((next2!=null)&&(next1!=null)){
            if((current1.val<=current2.val)&&(next1.val>current2.val)){
                next2=next2.next;
                current1.next=current2;
                current2.next=next1;
                current1=current1.next;
                current2=next2;
            }
            else{
                //bug 1: leave a unuseful sentence here
                current1=next1;
                next1=next1.next;
            }
            
        }
        if(next1==null){  //bug two: mis-spelling--==--->!=
            current1.next=current2;
        }
        if(l1.val<=l2.val)
            return l1;
        else 
            return l2;
       */
       //solution 2:
       ListNode head=null;
       
       if(l1==null)
         return l2;
       if(l2==null)
         return l1;
         
       ListNode head1 ;
       ListNode head2 ;
       //get the head of l1 and l2
       if(l1.val<l2.val){
           head = l1;
           head1 = l1.next;
           head2 = l2;
       }
       else{
           head = l2;
           head1 = l1;
           head2 = l2.next;
       }
       
       // return head of the two lists
       head.next = mergeTwoLists(head1, head2);
       
       
       return head;
    }
}