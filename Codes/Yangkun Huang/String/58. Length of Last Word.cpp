int lengthOfLastWord(string s) {
	int count = 0, result = 0;
	for (int i = 0; i<s.length(); i++)
		if (s[i] != ' ')
		{
		count++;
		result = count;
		}
		else
			count = 0;
	return result;
}