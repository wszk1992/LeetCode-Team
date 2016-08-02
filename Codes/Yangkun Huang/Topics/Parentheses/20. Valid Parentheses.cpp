bool isValid(string s) {
	stack<char> sta;
	for (auto c : s)
		if (c == '(' || c == '{' || c == '[')
			sta.push(c);
		else
		{
			if (sta.empty())
				return false;
			switch (sta.top())
			{
			case '(': if (c != ')')
				return false; break; //break������
			case '[': if (c != ']')
				return false; break;
			case '{': if (c != '}')
				return false; break;
			default:;
			}
			sta.pop();
		}
	return sta.empty();
}

// ����
//string left = "([{";
//string right = ")]}";
//stack<char> stk;
//for (auto c : s)
//if (left.find(c) != string::npos)
//stk.push(c);
//else
//{
//	if (stk.empty() || stk.top() != left[right.find(c)])
//		return false;
//	else
//		stk.pop();
//}
//return stk.empty();
