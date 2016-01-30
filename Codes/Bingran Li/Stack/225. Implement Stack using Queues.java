class MyStack {
    
    Queue myQ;
    int count = 0;
    
    public MyStack(){
        myQ = new LinkedList <Integer>();
    }
    // Push element x onto stack.
    public void push(int x) {
        myQ.add(x);
        count++;
    }

    // Removes the element on top of the stack.
    public void pop() {
        int i=count;
        while(i>1){
            myQ.add(myQ.remove());
            i--;
        }
        myQ.remove();
        count--;
    }

    // Get the top element.
    public int top() {
        int i=count;
        while(i>1){
            myQ.add(myQ.remove());
            i--;
        }
        int element = (int)myQ.element(); // PAY ATTENTION TO CAST
        myQ.add(myQ.remove());
        return element;
    }

    // Return whether the stack is empty.
    public boolean empty() {
        if(count==0)
            return true; // DO NOT RETURN INT TYPE----> COMPILE ERROR
        else
            return false;
    }
}