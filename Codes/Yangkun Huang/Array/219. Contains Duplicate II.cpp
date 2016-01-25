#include<iostream>
#include<vector>
#include<set>
#include<map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
	
	// method 1
	map<int, int> int_map;
	map<int, int>::iterator iter;
	for (int i = 0; i<nums.size(); i++) 
	{
		if ((iter = int_map.find(nums[i])) != int_map.end())
		{
			if (i - iter->second <= k) // 假设在maps中找到了该元素。推断它们位置是否小于等于k
				return true;
			else
				int_map.erase(iter); // 删除距离大于k的元素
		}
		int_map.insert(pair<int, int>(nums[i], i));
	}
	return false; 
	
	// method 1
	unordered_map<int, int> maps;
	for (int i = 0; i<nums.size(); i++)
	{
		if (maps.count(nums[i]))
		{
			if ((i - maps[nums[i]]) <= k)
				return true;
		}
		maps[nums[i]] = i;
	}
	return false;

	// method 2 Time Limit Exceeded 
	for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++)
		for (vector<int>::iterator iter = i + 1; iter <i + k; iter++)
			if (*i == *iter)
				return true;
	return false;

}

// set会将元素排序
// equal_range 返回一个元素为两个迭代器的pair类型
// 迭代器转换反向迭代器 正转反位置不变，反转正向末尾移一位
