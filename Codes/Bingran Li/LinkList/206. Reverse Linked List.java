/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prevNode, currentNode, nextNode;
        prevNode = null;
        currentNode = head;
        while(currentNode!=null){
            nextNode = currentNode.next;
            currentNode.next=prevNode;
            prevNode= currentNode;
            currentNode = nextNode;
        }
        head= prevNode;
        return head;
    }
}