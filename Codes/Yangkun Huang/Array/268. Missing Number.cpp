    // method 1 sum
    int missingNumber(vector<int>& nums) {
        int n=nums.size(); // range from 0 to n, n+1 candidates but only n positions
        int sum=(1+n)*n/2, sum2=0;
        for(auto j:nums)
            sum2+=j;
        return sum-sum2;
    }
    
    // method 2 bit manipulation ^
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        for(int i=0;i<nums.size();i++)    // since a^b^b=a, then all number between 0 and n should have appeared twice
            result ^= i^nums[i];          // the missing one appears only once so it is left behind
        return result;            
    }
    
    // method 3 binary search like 287. Find the Duplicate Number.cpp
