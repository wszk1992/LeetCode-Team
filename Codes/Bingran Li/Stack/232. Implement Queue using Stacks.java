class MyQueue {
    // solution 1: main stack and tem stack
    /*
    Stack myStack;
    Stack temStack; // time does not change----->if you want to improve, you can use "two" stacks, not main stack and tem stack
    public MyQueue(){
        myStack = new Stack();
        temStack = new Stack();
    }
    
    // Push element x to the back of queue.
    public void push(int x) {
        myStack.push(x);
    }

    // Removes the element from in front of queue.
    public void pop() {
        //Stack temStack = new Stack();
        while(myStack.empty()!=true){
             temStack.push(myStack.pop());
        }
        
        temStack.pop();
        
        while(temStack.empty()!=true){
            myStack.push(temStack.pop());
        }
        
    }

    // Get the front element.
    public int peek() {
        // not delete front element
       // Stack temStack = new Stack();
        while(myStack.empty()!=true){
             temStack.push(myStack.pop());
        }
       
        int element= (int)temStack.peek(); //Object cannot be converted to int
        
        while(temStack.empty()!=true){
            myStack.push(temStack.pop());
        }
        return element;
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return myStack.empty();
    }
    // solution 2: -----> from 24% to 64%
   */
   Stack pStack;
   Stack nStack;
   public MyQueue(){
        pStack = new Stack();
        nStack = new Stack();
    }
    
    // Push element x to the back of queue.
    public void push(int x) {
       if(nStack.empty()==true)
            pStack.push(x);
       else{
           while(!nStack.empty()){
               pStack.push(nStack.pop());
           }
           pStack.push(x);
       }
    }

    // Removes the element from in front of queue.
    public void pop() {
        if(!nStack.empty())
            nStack.pop();
        else{
            while(!pStack.empty()){
                 nStack.push(pStack.pop());
            }
            nStack.pop();
        }
        
    }

    // Get the front element.
    public int peek() {
       if(!nStack.empty())
            return (int)nStack.peek();
        else{
            while(!pStack.empty()){
                 nStack.push(pStack.pop());
            }
           return  (int)nStack.peek();
        }
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return pStack.empty() && nStack.empty();
    }
}