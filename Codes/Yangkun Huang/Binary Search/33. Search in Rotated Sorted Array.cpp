    int search(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        while(low<high){
            int mid=(low+high)/2;
            if(nums[low]>nums[mid]){
                if(target>=nums[low] || target<=nums[mid])
                    high=mid;
                else
                    low=mid+1;
            }
            else{
                if(target>nums[mid] || target<nums[low])
                    low=mid+1;      // since "/" is rounding down, it is better to use low=mid+1 rather than low=mid
                else
                    high=mid;
            }
        }
        return nums[low]==target ? low : -1;
    }
