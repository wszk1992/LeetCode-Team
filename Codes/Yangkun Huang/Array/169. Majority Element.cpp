    	// hash table
    int majorityElement(vector<int>& nums) {
        map<int, int> aux;
        for(auto n:nums){
            if(++aux[n]>=(nums.size()+1)/2) // trick: use add 1 to calculate half range
                return n;
        }
        return -1;
    }

	// sorting
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
    
	// selection
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
    } 
    
	// randomization
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        srand(unsigned(time(NULL)));
        while (true) {
            int idx = rand() % n;
            int candidate = nums[idx];
            int counts = 0; 
            for (int i = 0; i < n; i++)
                if (nums[i] == candidate)
                    counts++; 
            if (counts > n / 2) return candidate;
        }
    }

	// divide and conquer
	// the key here is to count lm and rm when lm!=rm
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size() - 1);
    }
    int majority(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = left + ((right - left) >> 1);
        int lm = majority(nums, left, mid);
        int rm = majority(nums, mid + 1, right);
        if (lm == rm) return lm;
        return count(nums.begin() + left, nums.begin() + right + 1, lm) > count(nums.begin() + left, nums.begin() + right + 1, rm) ? lm : rm;
    }
  
	// Moore Voting Algorithm
	// majority element could offset all other element
    int majorityElement(vector<int>& nums) {
        int major, counts = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!counts) {
                major = nums[i];
                counts = 1;
            }
            else counts += (nums[i] == major) ? 1 : -1;
        }
        return major;
    }
    
    // bit manipulation
    // each bit value of majority element is surly more than n/2
    int majorityElement(vector<int>& nums) {
        int major = 0, n = nums.size();
        for (int i = 0, mask = 1; i < 32; i++, mask <<= 1) { // count bit by bit
            int bitCounts = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] & mask)  // check if i-th bit is '1'
                	bitCounts++;
                if (bitCounts > n / 2) { 
                    major |= mask;	// sum up to majority element bit by bit
                    break;
                }
            }
        } 
        return major;
    } 
    
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

