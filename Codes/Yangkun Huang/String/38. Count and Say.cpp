string countAndSay(int n) {
	string s = "1";
	for (int i = 1; i<n; i++)
	{
		string temp;
		for (int j = 0, count = 1; j<s.length(); j++)
			if (s[j] == s[j + 1])
				count++;
			else
			{
				temp.insert(temp.end(), '0' + count);
				temp.insert(temp.end(), s[j]);
				count = 1;
			}
		s = temp;
	}
	return s;
}

string recursion(int n)
{
	if (n == 1)
		return "1";
	else
	{
		string s, temp;
		s = countAndSay(n - 1);
		for (int j = 0, count = 1; j<s.length(); j++)
			if (s[j] == s[j + 1])
				count++;
			else
			{
				temp.insert(temp.end(), '0' + count);
				temp.insert(temp.end(), s[j]);
				count = 1;
			}
		return temp;
	}
}