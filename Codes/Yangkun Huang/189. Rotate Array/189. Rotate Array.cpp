#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<int>& nums, int k) {
	/*vector<int>::iterator iter = nums.end() - k;*/
	//vector<int>::iterator iter2 = nums.begin();
	int i = k%nums.size(); 
	nums.insert(nums.begin(), nums.end() - i, nums.end());
	nums.erase(nums.end() - i, nums.end());
}

//insert的使用 成段插入
//erase的使用 成段删除
//不能在删除迭代器时遍历？
int main()
{
	vector<int> v(1,1);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	rotate(v, 3);
	cout << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	system("pause");
}