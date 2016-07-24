class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;
        if(k <= n) {
            combineHelper(res, comb, n, k, 1);
        }
        return res;
    }
    
    void combineHelper(vector<vector<int>>& res, vector<int>& comb, int& n, int& k, int index) {
        if(comb.size() == k) {
            res.push_back(comb);
            return;
        }
        for(int i = index; i <= n - k + comb.size() + 1; i++) {
            comb.push_back(i);
            combineHelper(res, comb, n, k, i + 1);
            comb.pop_back();
        }
    }
};
