    void nextPermutation(vector<int>& nums) {
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
    }
