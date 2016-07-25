    // no reference to num, no swap back
    void permuteRecursive(vector<int> num, int begin, vector<vector<int> > &result)	{
    	if (begin >= num.size()-1) {
    	    result.push_back(num);
    	    return;
    	}
    	for (int i = begin; i < num.size(); i++) {
    	    if(begin==i || num[begin]!=num[i]){
    	        swap(num[begin], num[i]);
    	        permuteRecursive(num, begin + 1, result); 
    	        //  swap(num[begin], num[i]);  // why delete this line
    	    }
    	}
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());  // why is sort necessary
        permuteRecursive(nums, 0, ans);
        return ans;
    }
    
    // use reference to num, but stil no swap back
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        dfs(0, nums, res);
        return res;
    }

    void dfs(int i, vector<int>& nums, vector<vector<int>> &res){
        if (i >= nums.size()){
            res.push_back(nums);
            return;
        }
        int p;
        for (p = i; p < nums.size(); p++){
            if (p == i || nums[p] != nums[i]){
                swap(nums[i], nums[p]);
                dfs(i + 1, nums, res);
            }
        }
        int last = nums[i];
        for (p = i + 1;p < nums.size(); p++)
            nums[p - 1] = nums[p];
        nums[p - 1] = last;
    }
