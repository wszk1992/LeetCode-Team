    bool search(vector<int>& nums, int target) {
        return search(0, nums.size()-1, target, nums);
    }
    
    bool search(int low, int high, int target, vector<int>& nums){
        if(low==high)
            return nums[low]==target;
        
        int mid=(low+high)/2;
        
        if(nums[low]==nums[mid])
            return search(low, mid, target, nums) || search(mid+1, high, target, nums);
            
        if(nums[low]<nums[mid])
            target>=nums[low] && target<=nums[mid] ? high=mid : low=mid+1;
        else
            target>=nums[low] || target<=nums[mid] ? high=mid : low=mid+1;
        return search(low, high, target, nums);
    }
