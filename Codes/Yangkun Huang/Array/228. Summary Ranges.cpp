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

// vector作为返回值 直接返回不需要引用
// string作为vector类型输出 string头文件可以直接cout输出 
// string的赋值 
// 为什么要加else 编译器无法知道else个哪个if配对
