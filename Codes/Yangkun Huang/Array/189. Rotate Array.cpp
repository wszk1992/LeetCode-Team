#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
	int i = k%nums.size(); 
	nums.insert(nums.begin(), nums.end() - i, nums.end());
	nums.erase(nums.end() - i, nums.end());
}

// insert的使用 成段插入
// erase的使用 成段删除
