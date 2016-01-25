#include<iostream>
#include<vector>
#include <set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
	//	method 1

	//  multiset<int> hs;
	//	multiset<int>::iterator iter;
	//	vector<int>::iterator i,j;
	//	for (i = nums.begin(); i != nums.end(); i++)
	//	    hs.insert(*i);
	//	for (i = nums.begin(); i != nums.end(); i++)
	//	    if (hs.count(*i)>1)
	//		    return true;
	//	return false;

	//  method 2

	set<int> s(nums.begin(), nums.end());
	if (s.size()<nums.size())
		return true;
	else
		return false;
}

// vector初始化 vector<int> v(4, 6) 包含4个6
// set拷贝vector set<int> hs(v.begin(), v.end()) 重复元素会被删除
// multiset拷贝vector multiset<int> hs(v.begin(),v.end())
