class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = nums[0];
        int n = 1;
        for(int i = 1; i < nums.size() - 1; i++) {
            if(nums[i] == res) {
                n++;
            }else if(n == 1) {
                res = nums[i + 1];
                i++;
            }else {
                n--;
            }
        }
        return res;
    }
};
