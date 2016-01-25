/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        
        ListNode nodeA,nodeB;
        int num1,num2;
        // count # of list
        nodeA = headA;
        nodeB = headB;
        num1=0;
        num2=0; // miss ;--------> DO NOT DO TI AGAIN
        while(nodeA!=null){
            nodeA = nodeA.next;
            num1++;
        }
        nodeA = headA;
        while(nodeB!=null){
            nodeB=nodeB.next;
            num2++;
        }
        nodeB=headB;
        // move, if point to the same element, then return that node
        int count = num2-num1;
        if(count<0){
            while(count<0){
                count++;
                nodeA = nodeA.next;
            }
        }
        else if (count>0){ //move list2 
            while(count>0){
                count--;
                nodeB = nodeB.next;
            }
        }
        while(nodeA!=null){
            if(nodeA==nodeB){
                return nodeA;
            }
            // everytime keep moving
            nodeA = nodeA.next;
            nodeB = nodeB.next;
        }
        // if no intersection 
        return null;
    }
}