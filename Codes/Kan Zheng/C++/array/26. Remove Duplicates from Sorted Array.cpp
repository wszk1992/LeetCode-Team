class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        if(nums.size()==0) return 0;
        for(;i<nums.size()-1;)
        {
            if(nums[i]==nums[i+1])
                nums.erase(nums.begin()+i+1);
            else
                i++;
        }
        return i+1;
    }
};
