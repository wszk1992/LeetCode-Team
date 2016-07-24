    // a cheating method
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if(find(nums.begin(), nums.end(), target)==nums.end())
            return res;
        auto low=lower_bound(nums.begin(), nums.end(), target);
        auto high=upper_bound(nums.begin(), nums.end(), target);
        res[0]=(int)(low-nums.begin());
        res[1]=(int)(high-nums.begin())-1;
        return res;
    }
    
    // standard binary search method
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size(), mid, left, right;  // end should not be nums.size()-1, since upper bound means the first ">"
        while (start < end) {               // find lower bound
            mid = (start + end) / 2;
            if (nums[mid] >= target)
                end = mid;
            else
                start = mid + 1;
        }
        left = start;
        start = 0, end = nums.size();
        while (start < end) {               // find upper bound
            mid = (start + end) / 2;
            if (nums[mid] > target)
                end = mid;
            else
                start = mid + 1;
        }
        right = start;
        return left == right ? vector<int> {-1,-1} : vector<int> {left,right-1};
    }
