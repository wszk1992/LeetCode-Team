class Queue {
    stack<int> qin;
    stack<int> qout;
public:
    // Push element x to the back of queue.
    void push(int x) {
        while(!qout.empty())
        {
            qin.push(qout.top());
            qout.pop();
        }
        qin.push(x);
        while(!qin.empty())
        {
            qout.push(qin.top());
            qin.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        qout.pop();
    }

    // Get the front element.
    int peek(void) {
        return qout.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return qout.empty();
    }
};