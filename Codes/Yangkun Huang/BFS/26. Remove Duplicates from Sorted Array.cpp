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

// 不要尝试读.end指向的位置
