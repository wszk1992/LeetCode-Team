class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> comb;
        combinationSum3Helper(k, n, res, comb, 1);
        return res;
    }
    
    void combinationSum3Helper(int k, int n, vector<vector<int>>& res, vector<int>& comb, int begin) {
        if(n == 0 && k == 0) {
            res.push_back(comb);
        }
        for(int i = begin; i < 10 && n >= i; i++) {
            comb.push_back(i);
            combinationSum3Helper(k-1, n-i, res, comb, i+1);
            comb.pop_back();
        }
    }
};
