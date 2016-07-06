int rob(vector<int>& nums) {
<<<<<<< HEAD
        // thought
        // since it is hard to decide whether the first house is robbed, then ignore this problem and just decomposed it into two House Robber problems
        // all circle problem could be decomposed into two subline
        if(nums.size()<2)
            return nums.size()?nums[0]:0;
        return max(robber(nums,0,nums.size()-1),robber(nums,1,nums.size()));
    }
    int robber(vector<int>& nums, int begin, int end)
    {
        int money=nums[begin], lastHouse=nums[begin], LLastHouse=0;
        for(int i=begin+1;i<end;i++)
        {
            money=max(LLastHouse+nums[i],lastHouse);
            LLastHouse=lastHouse;
            lastHouse=money;
        }
        return money;
    }
=======
        if(nums.size()==0)
            return 0;
        bool firstHouse=true;
        int money=nums[0], lastHouse=nums[0], plusLastHouse=0; // since the integers are non-negative, minimum value could use zero rather than INT_MIN
        for(int i=1;i<nums.size()-1;i++)
        {
            money=max(plusLastHouse+nums[i],lastHouse);
            plusLastHouse=lastHouse;
            lastHouse=money;
            if(money==nums[1])
                firstHouse=false;
        }
        if(firstHouse)
             money=max(plusLastHouse+nums[nums.size()-1],lastHouse);
        return money;
    }
>>>>>>> origin/master
