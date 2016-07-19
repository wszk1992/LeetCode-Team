    // no need to specially handle zero case
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (int i = 0, prev = 1; i < nums.size(); prev *= nums[i], ++i) 
          ans[i] = prev;
        for (int i = nums.size() - 1, prev = 1; i >= 0; prev *= nums[i], --i)
          ans[i] *= prev;
        return ans;
    }
    
    
    // use stack to store intermediate result
    int multiply(vector<int>& nums, int index, int left) {
        int right = 1;
        int curr = nums[index];
        if(index < nums.size() -1 )
            right = multiply( nums, index+1, left*curr);  // left means product of left side without curr position, so does right
    
        nums[index] = left * right; // neglect curr element
        return right *curr;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        multiply(nums,0,1);
        return nums;
    }

