    // selection
    // O(1) space?
    vector<int> majorityElement(vector<int>& nums) {
        int s=nums.size();
        if(!s)
            return {};
        vector<int> res;
        int count=0, candidate1=0, candidate2=0;
        
        nth_element(nums.begin(), nums.begin() + s / 3, nums.end());
        
        candidate1=nums[s/3]
        for(auto num:nums)
            num==candidate1 ? count++ : count;
        if(count>s/3)
            res.push_back(candidate1);
        
        nth_element(nums.begin(), nums.begin() + 2 * s / 3, nums.end());   
        
        count=0, candidate2=nums[2*s/3];
        for(auto num:nums)
            num==candidate2 ? count++ : count;
        if(count>s/3 && candidate1 != candidate2)
            res.push_back(candidate2);    
        
        return res;
    }
    
    // Moore Voting Algorithm
    vector<int> majorityElement(vector<int>& nums) {
        int array_size = nums.size();
        int candidate1, candidate2;
        int count1 = 0, count2 = 0;
        for(int i = 0; i < array_size; i ++){
            if(nums[i] == candidate1) count1 ++;
            else if(nums[i] == candidate2) count2 ++;
            else{
                if(count1 && count2) {count1 --; count2 --;}
                else if (count1){candidate2 = nums[i]; count2 = 1;}
                else {candidate1 = nums[i]; count1 = 1;}
            }
        }
        vector<int> result;
        count1=0, count2=0;
        for(int j = 0; j < array_size; j ++){
            if(nums[j] == candidate1) count1 ++;
            if(nums[j] == candidate2) count2 ++;
        }
        if(count1 > array_size/3) result.push_back(candidate1);
        if(count2 > array_size/3) result.push_back(candidate2);
        return result;
    }
