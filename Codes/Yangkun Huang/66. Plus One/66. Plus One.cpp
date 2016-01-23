#include<iostream>
#include<vector>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
		int tag = 1;
		for (vector<int>::reverse_iterator riter = digits.rbegin(); riter != digits.rend(); riter++)
			if (*riter + tag >= 10)
			{
			tag = 1;
			*riter = 0;
			}
			else
			{
				*riter = *riter + tag;
				tag = 0;
			}
		if (tag == 1)
			digits.insert(digits.begin(), 1);
		return digits;
}
//反向迭代器的使用
//*digits.begin()不用加括号

