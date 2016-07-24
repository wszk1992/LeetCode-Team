class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> list;
        sort(nums.begin(), nums.end());
        subsetHelper(result, list, nums, 0);
        return result;
    }
    
    void subsetHelper(vector<vector<int>>& result, vector<int>& list, vector<int>& nums, int pos) {
        result.push_back(list);
        for(int i = pos; i < nums.size(); i++) {
            if(i != pos && nums[i] == nums[i-1]) {
                continue;
            }
            list.push_back(nums[i]);
            subsetHelper(result, list, nums, i+1);
            list.pop_back();
        }
    }
};
