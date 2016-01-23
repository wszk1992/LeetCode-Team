#include<iostream>
#include<vector>
#include<string>

using namespace std;

void moveZeroes(vector<int>& nums) {
	int count = 0;
	for (vector<int>::reverse_iterator ri = nums.rbegin(); ri != nums.rend(); )
	{
		if (*ri == 0)
		{
			ri = vector<int>::reverse_iterator(nums.erase((++ri).base()));
			count++;
		}
		else
			ri++;
	}
	for (int i = 0; i < count; i++)
		nums.push_back(0);
}

// 反向迭代器的插入删除 ri.base()
//对 list/vector 来说，由于的 erase 能够返回一个有效的正向迭代器，因而只需要将返回的正向迭代器转换为反向迭代器即可。
//对 map / set 来说，因为在进行删除操作 l.erase((++rit).base()) 时，迭代器已经更新过了。
//从这里也可以看出，使用这种先递增后 base() 的转换删除法，代码更清晰。