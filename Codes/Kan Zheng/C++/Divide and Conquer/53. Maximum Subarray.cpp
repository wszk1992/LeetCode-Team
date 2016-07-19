class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int min_sum = 0;
        int max_sub_sum = nums[0];
        int cur_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            cur_sum += nums[i];
            if(cur_sum - min_sum > max_sub_sum){
                max_sub_sum = cur_sum - min_sum;
            }
            if(cur_sum < min_sum){
                min_sum = cur_sum;
            }
        }
        return max_sub_sum;
        
    }
};
