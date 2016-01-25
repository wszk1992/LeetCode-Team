#include<iostream>
#include<vector>
#include<string>

using namespace std;

string format(int begin, int end)
{
	char buffer[32];
	if (end == begin)
	{
		sprintf_s(buffer, "%d", begin);
	}
	else{
		sprintf_s(buffer, "%d->%d", begin, end);
	}
	return string(buffer);
}

vector<string> summaryRanges(vector<int>& nums) {
	vector<string> str;
	for (vector<int>::iterator iter = nums.begin(), tag = nums.begin(); iter != nums.end(); iter++)
		if (*iter + 1 < *(iter + 1) || iter + 1 == nums.end())
		{
		str.push_back(format(*tag, *iter));
		tag = iter + 1;
		}
	return str;
}

// vector��Ϊ����ֵ ֱ�ӷ��ز���Ҫ����
// string��Ϊvector������� stringͷ�ļ�����ֱ��cout��� 
// string�ĸ�ֵ 
// ΪʲôҪ��else �������޷�֪��else���ĸ�if���
