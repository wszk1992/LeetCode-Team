class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int step=k%nums.size();
        vector<int> rotate;
        rotate.reserve(nums.size());
        for(int i=0;i<step;i++)
        {
            rotate.push_back(nums[nums.size()-step+i]);
        }
        for(int i=0;i<nums.size()-step;i++)
        {
            rotate.push_back(nums[i]);
        }
        nums = rotate;
    }
};
