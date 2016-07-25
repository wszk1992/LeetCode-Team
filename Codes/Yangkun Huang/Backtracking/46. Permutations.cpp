    // recursive solution
    // use next permutation generate permutation one by one
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        int n=1;
        for(int i=num.size();i>0;i--)
            n*=i;
        for(int j=0;j<n;j++)
            result.push_back(nextPermutation(num));
        return result;
    }

    vector<int> nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1, k = i;  // need not to handle [] case
        while (i > 0 && nums[i-1] >= nums[i]) // first find the first number(violated number) which is in increasing trend
            i--;
        for (int j=i; j<k; j++, k--)    // reverse all numbers after that number(violated number)
            swap(nums[j], nums[k]);
        if (i > 0) {                    
            k = i--;                    // k is violated number, and i become the first element which is less than violated number
            while (nums[k] <= nums[i])  // insert that number(violated number) in the followed correct position using swap
                k++;
            swap(nums[i], nums[k]);
        }
        return nums;
    }
    
    // another recursive solution
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int> > result;
	    permuteRecursive(num, 0, result);
	    return result;
    }
    
    // permute num[begin..end]
    // invariant: num[0..begin-1] have been fixed/permuted
    void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()-1) {
		    // one permutation instance
		    result.push_back(num);
		    return;
		}
		// important idea: swap first and then swap back(backtracking)
		// try to find out similar idea amoung previous problems
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result); // how to make sure all permutations are covered
		    // reset
		    swap(num[begin], num[i]);
		}
    }
