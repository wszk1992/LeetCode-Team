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
			if (i - iter->second <= k) // ������maps���ҵ��˸�Ԫ�ء��ƶ�����λ���Ƿ�С�ڵ���k
				return true;
			else
				int_map.erase(iter); // ɾ���������k��Ԫ��
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

// set�ὫԪ������
// equal_range ����һ��Ԫ��Ϊ������������pair����
// ������ת����������� ��ת��λ�ò��䣬��ת����ĩβ��һλ
