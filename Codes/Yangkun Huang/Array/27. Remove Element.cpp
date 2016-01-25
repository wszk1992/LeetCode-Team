#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
	// method 1 
	for (vector<int>::iterator iter = nums.begin(); iter != nums.end();)
	{
		if (val == *iter)
			iter = nums.erase(iter);   // 直接遍历然后删除
		else
			iter++;
	}
	return nums.size();
	
	//  method 2
		int n = nums.size();
		int i = 0;
		while (i < n)     // 把删除元素放到有效长度之外
		{
			if (nums[i] == val) 
			{
				swap(nums[i], nums[n - 1]);
				n--;
			}
			else {
				i++;
			}
		}
		return n;
	}
}

// 执行erase操作后，不能读取迭代器内容
// erase返回指向所删除元素下一个位置的迭代器
// vector.swap的使用 两个vector元素的交换 用于内存释放
// 标准swap 交换两个整型参数
