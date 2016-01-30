class MinStack {
    
    //  how to get the min number in constant time????
    //  just retrieve the min node, do need to go to that node, we only need to know there is a node and its value
    Node head=null; 

    public void push(int x) {
    
       Node myNode = new  Node(x);
       
       if(head == null){
            myNode.min = myNode.val; // didn't consider when head is null, there is no head.min!!!----> PAY ATTENTION 
       } 
       else{
           myNode.min = x<head.min? x:head.min;
       }
       myNode.next = head;
       head = myNode;
       
    }

    public void pop() {
        
        head = head.next;
        
    }

    public int top() {
        
        return head.val;
    }

    public int getMin() {
        
        return head.min;
    }
    
    private class Node{
        
        int val;
        int min;
        Node next;
        
        public Node(int val){
            this.val = val;
            this.next = null;
        }
    }
    
    
}
