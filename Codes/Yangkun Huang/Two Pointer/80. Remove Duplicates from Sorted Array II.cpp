    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n : nums)
            if (i < 2 || n > nums[i-2])       // form a mismatch here
                nums[i++] = n;
        return i;
    }
