#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	vector<int>::iterator iter = nums1.begin(), iter2 = nums2.begin();
	if (m == 0)
	{
		for (; iter2 < nums2.end(); iter++, iter2++)
			iter = nums1.insert(iter, *iter2);
		nums1.erase(iter, nums1.end());
	}
	else
	{ 
		int tag = nums1.size() - m;                                      // 标记1中多余的元素
		for (; iter < nums1.end() - tag && iter2 < nums2.end(); iter++)  // 把2的元素插入1中
			if (*iter2 <= *iter)
			{
			iter = nums1.insert(iter, *iter2);
			iter2++;
			}
		for (; iter2 < nums2.end(); iter++, iter2++)
			iter = nums1.insert(iter, *iter2);
		if (n != 0)                                                     // 删除1中多余的元素
			nums1.erase(nums1.end() - tag, nums1.end());
	}
}

// 容器更新后迭代器会失效
// insert返回值
