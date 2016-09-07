    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        vector<int> rets(2, 0);
        for (int num : nums)
            rets[!(num & diff)] ^= num;
        return rets;
    }
    
    vector<int> singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int n : nums)                 a ^= n;
        for (int n : nums) if (n & a & -a) b ^= n;
        return {a ^ b, b};
    }
