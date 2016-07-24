class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> list;
        sort(nums.begin(),nums.end());
        subsetHelper(result, nums, list, 0);
        return result;
    }
    
    void subsetHelper(vector<vector<int>>& result, vector<int>& nums, vector<int>& list, int pos) {
        result.push_back(list);
        for(int i = pos; i < nums.size(); i++) {
            list.push_back(nums[i]);
            subsetHelper(result, nums, list, i+1);
            list.pop_back();
        }
    }
};
