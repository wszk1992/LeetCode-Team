#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
	// method 1 
	for (vector<int>::iterator iter = nums.begin(); iter != nums.end();)
	{
		if (val == *iter)
			iter = nums.erase(iter);   // ֱ�ӱ���Ȼ��ɾ��
		else
			iter++;
	}
	return nums.size();
	
	//  method 2
		int n = nums.size();
		int i = 0;
		while (i < n)     // ��ɾ��Ԫ�طŵ���Ч����֮��
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

// ִ��erase�����󣬲��ܶ�ȡ����������
// erase����ָ����ɾ��Ԫ����һ��λ�õĵ�����
// vector.swap��ʹ�� ����vectorԪ�صĽ��� �����ڴ��ͷ�
// ��׼swap �����������Ͳ���
