class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> perm;
        permuteUniqueHelper(res, nums, perm);
        return res;
    }
    
    void permuteUniqueHelper(vector<vector<int>>& res, vector<int>& nums, vector<int>& perm) {
        if(nums.empty()) {
            res.push_back(perm);
        }
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            perm.push_back(nums[i]);
            nums.erase(nums.begin() + i);
            permuteUniqueHelper(res, nums, perm);
            nums.insert(nums.begin() + i, perm.back());
            perm.pop_back();
        }
    }
};
