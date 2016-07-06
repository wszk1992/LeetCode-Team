int maxSubArray(vector<int>& nums) {
        int sum=0,result=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            // if no greater than current value, set a new start
            sum=max(nums[i],sum+nums[i]);
            result=max(result,sum);
        }
        return result;
    }
