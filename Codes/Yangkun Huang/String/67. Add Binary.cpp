string addBinary(string a, string b) {
	string result;
	int as = a.size(), bs = b.size();
	char carry = '0';
	for (int i = 0; i<abs(as - bs); i++)//直接比较size()会报错，每次insert后size都会改变
		as<bs ? a.insert(a.begin(), '0') : b.insert(b.begin(), '0');
	for (string::reverse_iterator ri1 = a.rbegin(), ri2 = b.rbegin(); ri1 != a.rend() && ri2 != b.rend(); ri1++, ri2++)
	{
		if (*ri1 + *ri2 + carry - 2 * '0'>'1')
		{

			result.insert(result.begin(), (*ri1 + *ri2 + carry - 2 * '0') % '2' + '0');
			carry = '1';
		}
		else
		{
			result.insert(result.begin(), *ri1 + *ri2 + carry - 2 * '0');
			carry = '0';
		}
	}
	if (carry == '1')
		result.insert(result.begin(), '1');
	return result;
}