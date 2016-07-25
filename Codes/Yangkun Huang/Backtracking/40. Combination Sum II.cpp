    // numbers in C are not unique at this problem
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        combinationSum2(candidates, target, res, combination, 0);
        return res;
    }

    void combinationSum2(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &combination, int begin) {
      	if  (!target) {
      		res.push_back(combination);
      		return;
	  }
        for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
            combination.push_back(candidates[i]);
            combinationSum2(candidates, target - candidates[i], res, combination, i+1);
            combination.pop_back();
            while(candidates[i+1]==candidates[i] && i<candidates.size())
                i++;
        }
    }
