#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
	for (vector<int>::iterator iter = nums.begin(); iter != nums.end();)
		if (iter + 1 != nums.end())
			if (*iter == *(iter + 1))
				iter = nums.erase(iter);
			else
				iter++;
		else
			break;
	return nums.size();
}

// 注意不要尝试读.end指向的位置

int main()
{
	vector<int> v(1, 1);
	for (int i = 1; i < 10; i++)
		v.push_back( i);

	cout << removeDuplicates(v)	<<endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	system("pause");
}