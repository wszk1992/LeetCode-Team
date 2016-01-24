/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public boolean isPalindrome(ListNode head) {
        // solution 1: use a stack, but need extra O(n) space
        /*
        if(head==null)  // need to consider null list
            return true;
        ListNode currentNode;
        int size=1;
        currentNode = head;
        while(currentNode.next!=null){
            currentNode = currentNode.next;
            size++;
        }
        int [] myArray = new int[size];
        currentNode = head;
        int i=0;
        while(i<size){                  // the condition used to be wrong, be careful about the condition sentence
            myArray[i]=currentNode.val;
            if(currentNode.next!=null)  // easy to miss
                currentNode = currentNode.next;
            i++;
        }
        currentNode = head;
        for(int j=myArray.length-1;j>-1;j--){
            if(myArray[j]!=currentNode.val)
                return false;
            else if(currentNode.next!=null)
                currentNode=currentNode.next;
            
        }
        return true;
        */
        // solution 2: reverse half the list
        if((head==null)||(head.next==null))
            return true;
            
        ListNode fastNode,slowNode;
        
        fastNode=head;
        slowNode=head;
        
        while((fastNode.next!=null)&&(fastNode.next.next!=null)){
            fastNode=fastNode.next.next;
            slowNode=slowNode.next;
        }
        slowNode = slowNode.next;
        // reverse the linkList
        ListNode head2,prevNode,currentNode,nextNode;
        
        head2=slowNode;
        prevNode=null;
        currentNode=head2;
        
        while(currentNode!=null){
             nextNode=currentNode.next;
             currentNode.next=prevNode;
             prevNode = currentNode;
             currentNode = nextNode;
        }
        head2=prevNode;
        // compare
        ListNode node1,node2;
        node1=head;
        node2=head2;
        while(node2!=null){
            if(node1.val!=node2.val)
                return false;
            else if(node2.next!=null){
                node1=node1.next;
                node2=node2.next;
            }
            else 
                break;
        }
      return true;  
    }
}