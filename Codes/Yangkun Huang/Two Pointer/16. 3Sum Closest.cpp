    // same idea as 15.3Sum
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff=INT_MAX;
        bool sign=false;
        for(int left=0;left<nums.size();left++){
            int mid=left+1, right=nums.size()-1;
            while(mid<right){
                int sum=nums[left]+nums[right]+nums[mid];
                if(sum<target){
                    diff=min(diff, abs(sum-target));
                    if(diff==-(sum-target)) sign=true; // diff==-(sum-target) ? sign=true : sign=diff==sum-target ? false : sign;
                    if(diff==sum-target) sign=false;
                    do  mid++;
                    while(nums[mid]==nums[mid+2] && mid<right); // skip duplicates but need to remain at least two
                }
                else if(sum>target){
                    diff=min(diff, abs(sum-target));
                    if(diff==-(sum-target)) sign=true;
                    if(diff==sum-target) sign=false;
                    do right--;
                    while(nums[right]==nums[right-2] && right>mid);
                }
                else
                    return target;
            }
            while(left<nums.size() && nums[left]==nums[left+1])
                left++;
        }
        return sign ? target-diff : target+diff;
    }
