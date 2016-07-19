      int searchInsert(vector<int>& nums, int target) {
        int low=0, high=nums.size();  // not nums.size()-1 here
        while(low<high){              // [low, high] is the range of candidates
            int mid=(low+high)/2;
            if(target==nums[mid])
                return mid;
            if(target>nums[mid])
                low=mid+1;
            else           // the key point is here: if target<nums[mid], target could be either at mid or at left side of mid
                high=mid;   // differ from standard bs: if target<nums[mid], target must be at left side of mid
        }
        return low;
    }
