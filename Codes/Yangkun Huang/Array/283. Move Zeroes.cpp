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

// ����������Ĳ���ɾ�� ri.base()
//�� list/vector ��˵�����ڵ� erase �ܹ�����һ����Ч����������������ֻ��Ҫ�����ص����������ת��Ϊ������������ɡ�
//�� map / set ��˵����Ϊ�ڽ���ɾ������ l.erase((++rit).base()) ʱ���������Ѿ����¹��ˡ�
