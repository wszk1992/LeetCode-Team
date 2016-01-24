/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        // solution 1: first get the size
        /*
        ListNode currentNode;
        currentNode = head;
        int size=0;
        while(currentNode!=null){
            size++;
            currentNode=currentNode.next;
        }
        currentNode = head;
        for(int i=0;i<size-n-1;i++){
            currentNode=currentNode.next;
        }
        if(size==n) // not consider if remove first element
            return head.next;
        currentNode.next=currentNode.next.next;
        return head;
        */
        // solution 2: only one pass, great idea---> let node1 go for a while and then node2 move
        //---->why time still not decrease??
     
        ListNode node1,node2;
        ListNode myNode=new ListNode(0);
        myNode.next = head;
        node1=myNode;
        node2=myNode;
        while(node1!=null){ 
            node1=node1.next;
            n--;
            if(n<-1){
                node2=node2.next;
            }
        }
        node2.next=node2.next.next;
        return myNode.next;
   
        
    }
}