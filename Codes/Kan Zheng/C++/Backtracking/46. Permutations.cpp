class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> vec;
        permuteHelper(nums, res, vec);
        return res;
    }
    
    void permuteHelper(vector<int>& nums, vector<vector<int>>& res, vector<int>& vec) {
        if(nums.empty()) {
            res.push_back(vec);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            vec.push_back(val);
            nums.erase(nums.begin() + i);
            permuteHelper(nums, res, vec);
            nums.insert(nums.begin() + i, val);
            vec.pop_back();
        }
    }
};
