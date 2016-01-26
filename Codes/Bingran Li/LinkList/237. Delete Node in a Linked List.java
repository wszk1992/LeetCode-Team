/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void deleteNode(ListNode node) {
        
        // solution 1: put all values in the back forward -----> but actually we can only move one node !
        /*
        ListNode currentNode;
        currentNode = node;
        while(currentNode != null){
            
            currentNode.val = currentNode.next.val;
            if(currentNode.next.next == null){
                currentNode.next = null;
                break;                    // miss break--->bug 
            }
            else{
                currentNode = currentNode.next;
            }
        }
        */
        // solution 2: only copy once---->much simple
        ListNode myNode;
        myNode = node.next;
        
        node.val = myNode.val;
        node.next = myNode.next;
        
    }
}