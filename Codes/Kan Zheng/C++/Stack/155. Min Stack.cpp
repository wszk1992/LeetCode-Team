
class MinStack {
    stack<int> s;
    stack<int> s_min;
public:
    void push(int x) {
        s.push(x);
        if(s_min.empty()||x<=s_min.top())
        s_min.push(x);
    }

    void pop() {
        if(s.empty())
            return;
        if(s_min.top()==s.top())
            s_min.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return s_min.top();
}

};

