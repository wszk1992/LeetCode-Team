    // solution 1
    // the idea here is any number xor with 0 equal to itself and xor with itself equal to 0
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>()); // bit_xor<int>()
    }

    // solution 2
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;  
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        for(auto iter:m)
            if(iter.second==1)
                return iter.first;
        return 0;
    }
