// Push element x onto stack.
queue<int> in, out;
void push(int x) {
	in.push(x);
}

// Removes the element on top of the stack.
void pop() {
	while (in.front() != in.back())
	{
		out.push(in.front());
		in.pop();
	}
	in.pop();
	while (!out.empty())
	{
		in.push(out.front());
		out.pop();
	}
}

// Get the top element.
int top() {
	return in.back();
}

// Return whether the stack is empty.
bool empty() {
	return in.empty();
}
// method 1 pop 队列1除队尾外放入队列2 直接入栈
// method 2 push 把队列1按栈的顺序存入队列2 直接出栈