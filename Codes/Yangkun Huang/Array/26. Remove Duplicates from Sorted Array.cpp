    // better solution
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(auto n:nums)
            if(i<1 || nums[i-1]<n) // if meet duplicates, continue until find a new number and set it to nums[i]
                nums[i++]=n;
        return i;
    }



#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums) {
	for (vector<int>::iterator iter = nums.begin(); iter != nums.end();)
		if (iter + 1 != nums.end())
			if (*iter == *(iter + 1))
				iter = nums.erase(iter);
			else
				iter++;
		else
			break;
	return nums.size();
}
