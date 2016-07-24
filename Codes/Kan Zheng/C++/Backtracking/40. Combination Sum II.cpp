class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> comb;
        combinationSum2Helper(candidates, target, res, comb, 0);
        return res;
    }
    
    void combinationSum2Helper(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& comb, int begin) {
        if(target == 0) {
            res.push_back(comb);
        }
        for(int i = begin; i < candidates.size() && target >= candidates[i]; i++) {
            if(i > begin && candidates[i] == candidates[i-1]) {
                continue;
            }
            comb.push_back(candidates[i]);
            combinationSum2Helper(candidates, target - candidates[i], res, comb, i+1);
            comb.pop_back();
        }
    }
};
