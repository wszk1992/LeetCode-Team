bool canJump(vector<int>& nums) {
       int reach=0;
        for(int i=0;i < reach+1 &&i<nums.size();i++)
                reach=max(reach, i + nums[i]);
        return reach>=nums.size()-1;
    }
    }