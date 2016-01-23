#include<iostream>
#include<vector>
#include <set>
using namespace std;
int majorityElement(vector<int>& nums) {
	multiset<int> ms(nums.begin(), nums.end());
	for (multiset<int>::reverse_iterator ri = ms.rbegin(); ri != ms.rend(); ri++)
		if (ms.count(*ri)>nums.size() / 2)
			return *ri;
}