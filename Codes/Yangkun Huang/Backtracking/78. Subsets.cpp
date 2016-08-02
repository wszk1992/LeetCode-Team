    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<vector<int> > result;
        vector<int> path;
        subsets(nums, path, 0, result); // return subset from 0 to end and an empty path vector
        return result;
    }

    static void subsets(const vector<int> &S, vector<int> &path, int step, vector<vector<int> > &result) {
        if (step == S.size()) {
            result.push_back(path);
            return;
        }
        // current element is S[step]
        // recursion goes from buttom-up while loop goes from top-down
        subsets(S, path, step + 1, result);  // first return all possible subsets of following elements from step+1 to end
        path.push_back(S[step]);             // add current element S[step]
        subsets(S, path, step + 1, result);  // attach all subsets of following elements
        path.pop_back();                     // backtracking -- clean up and return to previous element
    }
