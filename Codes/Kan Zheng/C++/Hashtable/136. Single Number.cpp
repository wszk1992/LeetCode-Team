class Solution {
public:

    int singleNumber(vector<int>& nums) {
        /*Use extra memory
        unordered_set <int> set;
        for(int i=0;i<nums.size();i++)
        {
            if(set.find(nums[i])==set.end())
                set.insert(nums[i]);
            else
                set.erase(nums[i]);
        }
        return *(set.begin());
        */
        
        //Use XOR
        int result=0;
        for(int i=0;i<nums.size();i++)
        {
            result ^= nums[i];
        }
        return result;
        
    }
};