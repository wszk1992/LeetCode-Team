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
// method 1 pop ����1����β��������2 ֱ����ջ
// method 2 push �Ѷ���1��ջ��˳��������2 ֱ�ӳ�ջ