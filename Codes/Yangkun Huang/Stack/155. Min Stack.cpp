stack<int> minstack, min;
void push(int x) {
	if (minstack.empty())
		min.push(x);
	else
		if (x <= min.top())
			min.push(x);
	minstack.push(x);
}

void pop() {
	if (!min.empty())
		if (minstack.top() == min.top())
			min.pop();
	minstack.pop();
}

int top() {
	return minstack.top();
}

int getMin() {
		return min.top();
}
