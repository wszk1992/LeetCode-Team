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
		int tag = nums1.size() - m;
		for (; iter < nums1.end() - tag && iter2 < nums2.end(); iter++)
			if (*iter2 <= *iter)
			{
			iter = nums1.insert(iter, *iter2);
			iter2++;
			}
		if (iter < nums1.end() - tag && iter2 == nums2.end())
			iter++;
		for (; iter2 < nums2.end(); iter++, iter2++)
			iter = nums1.insert(iter, *iter2);
		if (n != 0)
			nums1.erase(nums1.end() - tag, nums1.end());
	}
}

// 容器更新后迭代器会失效
// insert返回值

int main()
{
	int a[] = { 4, 5, 6, 0, 0, 0 }, b[] = { 1, 2, 3, 5, 6 };

	vector<int> v1(a,a+6), v2(b,b+3);
	/*for (int i = 1; i < 10; i++)
		v.push_back(i);*/
	merge(v1, 3, v2, 3);

	for (int i=0; i < v1.size(); i++)
		cout<<v1[i]<<endl;
	system("pause");
}